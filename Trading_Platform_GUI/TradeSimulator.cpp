#include "TradeSimulator.h"
#include "MyTableWidgetItem.h"
#include "MyDateTableWidgetItem.h"

#include <math.h>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <chrono>

TradeSimulator::TradeSimulator(QWidget *parent) :
    QWidget(parent), ui(new Ui::TradeSimulator)
{
    this->ui->setupUi(this);
    this->setWindowTitle("Trock Trade Simulator");
}


void TradeSimulator::addTradeData(std::string eqType, vector<TradeDayData> data)
{
    this->eqType = eqType;
    this->data = data;

    //Set company name
    this->ui->tradeSimulator_companyName->setText(eqType.c_str());

    //Disable sell button to begin with
    this->ui->sendSellSignal->setEnabled(false);

    //Disable output csv order file
    this->ui->exportOrderFileButton->setEnabled(false);

    //Create analysis data
    this->cumulativeData = new AnalysisData(eqType);
}

void TradeSimulator::runSimulation() {
    //Set up a thread
    this->simWorker = new std::thread(&TradeSimulator::simulationWorker, this);
}

//Worker thread that handles simulation
void TradeSimulator::simulationWorker() {

    std::chrono::milliseconds curTime = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch());

    this->index = -1;

    //While trade day data still exist
    while (this->index == -1 || this->index < (int)this->data.size() - 1) { //one less here as index starts from -1

        std::chrono::milliseconds newTime = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch());

        //If not enough time has passed yet, continue looping
        if ((newTime - curTime).count() < this->updatePeriod) {
            continue;
        }

        //Clear error messages
        ui->simulator_error_box->clear();

        curTime = newTime;

        //Get next vector item (pre inc)
        TradeDayData tdd = this->data.at(++this->index);

        //Update date
        this->ui->tradeSimulator_curDate->setText(tdd.date.c_str());

        //Update prices on trade simulator display
        char openStr[10];
        char highStr[10];
        char lowStr[10];
        char lastStr[10];

        sprintf(openStr, "%.2f", tdd.open);
        sprintf(highStr, "%.2f", tdd.high);
        sprintf(lowStr, "%.2f", tdd.low);
        sprintf(lastStr, "%.2f", tdd.last);

        this->ui->open_price->setText(openStr);
        this->ui->high_price->setText(highStr);
        this->ui->low_price->setText(lowStr);
        this->ui->last_price->setText(lastStr);
    }

    //Trade data exhausted, display message and disable buttons
    connect(this, SIGNAL(sendEndThread()), this, SLOT(doThreadEndActions()), Qt::QueuedConnection);
    this->sendEndThread();
}

//Do final thread actions (in queued order)
void TradeSimulator::doThreadEndActions() {
    this->ui->sendBuySignal->setEnabled(false);
    this->ui->sendSellSignal->setEnabled(false);
    this->ui->exportOrderFileButton->setEnabled(true);
    ui->simulator_error_box->setText("Trade data exhausted.");
}

void TradeSimulator::on_sendBuySignal_clicked() {
    if (!isBuyEnabled)
        return;

    //No trades on initial state
    if (this->index < 0)
        return;

    //Don't buy/sell in same day
    if (this->index == lastTradeIndex) {
        ui->simulator_error_box->setText("You cannot buy on the same day you sell.");
        return;
    }

    lastTradeIndex = this->index;

    //Disable Buy (enable sell)
    isBuyEnabled = false;
    isSellEnabled = true;
    ui->sendBuySignal->setEnabled(false);
    ui->sendSellSignal->setEnabled(true);

    //Add data to analysis data
    TradeDayData tdd = this->data.at(this->index);
    this->cumulativeData->addNextTradeData(std::signal::BUY, tdd.date, tdd.last, 100);

    //Add buy to user trades
    this->userTrades.push_back(tdd);
}

void TradeSimulator::on_sendSellSignal_clicked() {
    if (!isSellEnabled)
        return;

    //No trades on initial state
    if (this->index < 0)
        return;

    //Don't buy/sell in same day
    if (this->index == lastTradeIndex) {
        ui->simulator_error_box->setText("You cannot sell on the same day you buy.");
        return;
    }

    lastTradeIndex = this->index;

    //Disable Sell (enable buy)
    isBuyEnabled = true;
    isSellEnabled = false;
    ui->sendSellSignal->setEnabled(false);
    ui->sendBuySignal->setEnabled(true);

    //Add data to analysis data
    TradeDayData tdd = this->data.at(this->index);
    this->cumulativeData->addNextTradeData(std::signal::SELL, tdd.date, tdd.last, 100);

    //Add buy to user trades
    this->userTrades.push_back(tdd);

    //On sell signals, update buysell pair list
    displayReturnsAnalysis(this->cumulativeData); //show analysis

    //Display graph for buy sell pairs
    displayGraphAnalysis(this->cumulativeData);
}

//Generate an order CSV File using trades that user made
void TradeSimulator::on_exportOrderFileButton_clicked() {

    if (this->lastTradeIndex == -1) {
        ui->simulator_error_box->setText("No trades were made.");
        return;
    } else {
        //Check if a final 'dangling' buy order exists (ignore if so)
        size_t totalTrades = userTrades.size();

        //if not even, dangling buy order (ignore last order)
        if (userTrades.size() % 2 != 0)
            --totalTrades;

        //prepare output file
        QString filename = QFileDialog::getSaveFileName(this, tr("Save Order File"), "/path/to/file/", tr("CSV File (*.csv)"));
        QFile file(filename);
        if(file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);

            //Output header
            stream << "#Company, Date, Price, Volume, Value, Signal" << endl;

            size_t counter = 0;

            //Now output trades
            for (size_t i = 0; i < totalTrades; ++i) {
                TradeDayData tdd = this->userTrades.at(i);

                stream << QString::fromStdString(this->eqType) << ","
                       << QString::fromStdString(tdd.date) << ","
                       << QString::number(tdd.last) << ","
                       << QString::number(100) << ","
                       << QString::number(100 * tdd.last) << ","
                       << ((counter % 2 == 0) ? QString::fromStdString("B") : QString::fromStdString("S"))
                       << endl;
                ++counter;
            }
        }
        file.close();
    }
}

void TradeSimulator::displayReturnsAnalysis(std::AnalysisData *data) {

    //Clear current list
    ui->tradeSimulator_returnsAnalysis->setRowCount(0); //setting row to 0 auto deletes all items

    //Prepare the table
    ui->tradeSimulator_returnsAnalysis->setColumnCount(4);                     //for the four headings: buy,sell,date,and return
    ui->tradeSimulator_returnsAnalysis->verticalHeader()->setVisible(false);   //hide line numbers
    ui->tradeSimulator_returnsAnalysis->setHorizontalHeaderLabels(QString("Buy-Sell Pair;Date;Return Value;Return %").split(";")); //insert column names

   //adjusting header sizes
    ui->tradeSimulator_returnsAnalysis->horizontalHeader()->resizeSection(0,215);
    ui->tradeSimulator_returnsAnalysis->horizontalHeader()->resizeSection(1,170);
    ui->tradeSimulator_returnsAnalysis->horizontalHeader()->resizeSection(2,145);
    ui->tradeSimulator_returnsAnalysis->horizontalHeader()->resizeSection(3,155);


    //maintain queues of trades, one for buy and one for sell
    // int is for maintaining which one came first
    vector<tuple<TradeData, int>> buy_trades;
    vector<tuple<TradeData, int>> sell_trades;

    //maintain total return percentage
    double net_return_value = 0;
    double net_return_perc = 0;

    //read the trade orders line by line
    for (int i = 0; i < data->tradeDataAvailable(); i++) {
        //Prepare some variables
        string buySellPair; //details buy and sell price
        string date;        //when the buy-sell / sell-buy pair occurs
        string returnValue; //the numeric return value
        string returnPerc;  //the percentage return value

        //load the vectors as appropriate
        if (data->getData(i).tradeSignal == BUY) {
            buy_trades.push_back(tuple<TradeData,int>(data->getData(i),i));
        } else {
            sell_trades.push_back(tuple<TradeData,int>(data->getData(i),i));
        }

        //Determine whether there is a buy-sell / sell-buy pair
        if (buy_trades.size() > 0 && sell_trades.size() > 0) {
            tuple<TradeData,int> buy_trade = buy_trades.front();
            tuple<TradeData,int> sell_trade = sell_trades.front();

            char buySellPairBuffer[50]; //for converting buy-sell values into a string

            if (get<1>(sell_trade) > get<1>(buy_trade)) { //a buy-sell pair

                //Construct buy-sell pair string
                sprintf(buySellPairBuffer,"Buy: $%.2lf, Sell: $%.2lf",get<0>(buy_trade).price,get<0>(sell_trade).price);
                buySellPair = std::string(buySellPairBuffer);

                //Construct Date string
                date.append(get<0>(sell_trade).date.c_str());

            } else { //a sell-buy pair

                //Construct buy-sell pair string
                sprintf(buySellPairBuffer,"Sell: $%.2lf, Buy: $%.2lf",get<0>(sell_trade).price,get<0>(buy_trade).price);
                buySellPair = std::string(buySellPairBuffer);

                //Construct Date string
                date.append(get<0>(buy_trade).date.c_str());

            }

            //Calculate and construct return value string
            double return_value =(get<0>(sell_trade).price - get<0>(buy_trade).price);
            char returnValueBuffer[50];
            if (return_value < 0) {
                sprintf(returnValueBuffer,"-$%.2lf",return_value * (-1));
            } else {
                sprintf(returnValueBuffer,"$%.2lf",return_value);
            }
            returnValue = std::string(returnValueBuffer);

            //Calculate and construct return percentage string
            double return_perc = (get<0>(sell_trade).price - get<0>(buy_trade).price) * 100 / get<0>(buy_trade).price;
            char returnPercBuffer[50];
            sprintf(returnPercBuffer,"%.2lf",return_perc);
            returnPerc = std::string(returnPercBuffer);
            returnPerc.append("%");

            //Insert results into table
            insertRowIntoReturnsAnalysis(buySellPair, date, returnValue, returnPerc);

            //update total return value and percentage
            net_return_value += return_value;
            net_return_perc += return_perc;

            //Remove the first trades from both queues
            buy_trades.erase(buy_trades.begin(),buy_trades.begin()+1);
            sell_trades.erase(sell_trades.begin(),sell_trades.begin()+1);
        }
    }

    //Set returns style
    if (net_return_perc < 0) {
        this->ui->tradeSimulator_ongoingReturns->setStyleSheet("color:red;font: 14pt \"Verdana\";");
    } else {
        this->ui->tradeSimulator_ongoingReturns->setStyleSheet("color:green;font: 14pt \"Verdana\";");
    }

    QString ongoing_net_returns_str;
    ongoing_net_returns_str.append(QString::number(net_return_perc) + "%");
    this->ui->tradeSimulator_ongoingReturns->setText(ongoing_net_returns_str);

}

void TradeSimulator::insertRowIntoReturnsAnalysis(std::string buySellPair,
                                                   std::string date,
                                                    std::string returnValue,
                                                   std::string returnPerc) {

    //increase table rows by 1
    int currRows = ui->tradeSimulator_returnsAnalysis->rowCount();
    ui->tradeSimulator_returnsAnalysis->setRowCount(currRows + 1);


    QTableWidgetItem* col0 = new QTableWidgetItem(QString::fromStdString(buySellPair), QTableWidgetItem::Type);
    col0->setFlags(col0->flags() ^ Qt::ItemIsEditable);
    col0->setTextAlignment(Qt::AlignHCenter);
    ui->tradeSimulator_returnsAnalysis->setItem(currRows,0, col0);

    MyDateTableWidgetItem* col1 = new MyDateTableWidgetItem(QString::fromStdString(date));
    col1->setFlags(col1->flags() ^ Qt::ItemIsEditable);
    col1->setTextAlignment(Qt::AlignHCenter);
    ui->tradeSimulator_returnsAnalysis->setItem(currRows, 1, col1);


    MyTableWidgetItem* col2 = new MyTableWidgetItem(QString::fromStdString(returnValue));
    col2->setFlags(col2->flags() ^ Qt::ItemIsEditable);
    col2->setTextAlignment(Qt::AlignHCenter);
    ui->tradeSimulator_returnsAnalysis->setItem(currRows, 2, col2);

    MyTableWidgetItem* col3 = new MyTableWidgetItem(QString::fromStdString(returnPerc));
    col3->setFlags(col2->flags() ^ Qt::ItemIsEditable);
    col3->setTextAlignment(Qt::AlignHCenter);
    ui->tradeSimulator_returnsAnalysis->setItem(currRows, 3, col3);
}

// Display graph data as it becomes available
void TradeSimulator::displayGraphAnalysis(std::AnalysisData *data) {

    QFont titleFont = QFont();
    titleFont.setBold(true);
    QFont normalFont = QFont();
    normalFont.setBold(false);


    double daySize = 7.0;
    double chartHeight = 240.0;

    if (scene != nullptr)
        delete scene;

    scene = new QGraphicsScene();

    double extraWidth = 150.0 + 50.0;
    double extraBase = 30.0;

    double shiftX = - ((-daySize) * data->daysTrading() / 2 - extraWidth/2.0);//50.0;
    double shiftY = 0.0;

    scene->setSceneRect(0, shiftY - (chartHeight/2.0), daySize * data->daysTrading() + extraWidth, chartHeight + extraBase);

    //scene->setSceneRect(shiftX + (-daySize) * data->daysTrading() / 2 - extraWidth/2.0, shiftY - (chartHeight/2.0), daySize * data->daysTrading() + extraWidth, chartHeight + extraBase);

    //scene->setSceneRect(shiftX + (-daySize) * data->daysTrading() / 2 - extraWidth/2.0, shiftY - (chartHeight/2.0), daySize * data->daysTrading() + extraWidth, chartHeight + extraBase);


    QPen pen;

    //draw y axis label "Equity Price"
    double yAxisLabelY = shiftY - 70.0;
    double yAxisLabelX = shiftX + (-daySize) * data->daysTrading() / 2 - 92.0;//150.0;
    scene->addText("P\nr\ni\nc\ne", titleFont)->setPos(yAxisLabelX, yAxisLabelY);

    //draw x axis label "date"
    double xAxisLabelY = shiftY + chartHeight/2.0 + 30.0;
    double xAxisLabelX = shiftX + (-daySize) * data->daysTrading() / 2 + 50.0;
    scene->addText("Date", titleFont)->setPos(xAxisLabelX, xAxisLabelY);


    double startX = shiftX + (-daySize) * data->daysTrading() / 2 + daySize/2;
    double startY = shiftY + chartHeight/2.0 + daySize + 4;


    //draw price markers
    double markerPriceX = startX - 70.0;
    int numPriceMarkers = 6;

    //chartHeight/2.0 - chartHeight * pricePercentToMax + daySize/2.0;
    double percentUsed = (floor(data->highestPrice() - ceil(data->lowestPrice())) / (data->highestPrice() - data->lowestPrice()));

    if (percentUsed <= 0.0) {
        for (int i = 0; i != numPriceMarkers; ++i) {
            double percentMarker = static_cast<double>(i) / (static_cast<double>(numPriceMarkers) - 1.0);
            double markerPriceY = shiftY + chartHeight/2.0 - chartHeight * percentMarker + daySize/2.0;
            scene->addText(QString::fromStdString(std::Helper::formatPrice(percentMarker * (data->highestPrice() - data->lowestPrice()) + data->lowestPrice())), normalFont)->setPos(markerPriceX, markerPriceY);
            scene->addLine(markerPriceX, markerPriceY, markerPriceX + daySize * data->daysTrading() + extraWidth, markerPriceY, pen);
        }

    } else {

        for (int i = 0; i != numPriceMarkers + 1; ++i) {
            double additionOfPercentForSmoothness = 1.0 - (data->highestPrice() - ceil(data->lowestPrice())) / (data->highestPrice() - data->lowestPrice());
            //double additionOfPercentForSmoothness = 1.0 - (data->highestPrice() - ceil(data->lowestPrice())) / (data->highestPrice() - data->lowestPrice());
            double percentMarkerIncr = percentUsed * (static_cast<double>(1.0) / (static_cast<double>(numPriceMarkers) - 1.0));
            if (additionOfPercentForSmoothness >= percentMarkerIncr) {
                additionOfPercentForSmoothness -= percentMarkerIncr;
            }
            double percentMarker = percentUsed * (static_cast<double>(i) / (static_cast<double>(numPriceMarkers) - 1.0)) + additionOfPercentForSmoothness;


            //double percentMarkerIncr = 1.0 / (static_cast<double>(numPriceMarkers) - 1.0);
            //double priceIncr = percentMarkerIncr * (data->highestPrice() - data->lowestPrice()) + data->lowestPrice();
            //double percentMarker = (floor(priceIncr) / priceIncr) * (static_cast<double>(i) / (static_cast<double>(numPriceMarkers) - 1.0));
            //double percentMarker = (floor(priceIncr) / (data->highestPrice() - data->lowestPrice()));

            double markerPriceY = shiftY + chartHeight/2.0 - chartHeight * percentMarker + daySize/2.0;
            scene->addText(QString::fromStdString(std::Helper::formatPrice(percentMarker * (data->highestPrice() - data->lowestPrice()) + data->lowestPrice())), normalFont)->setPos(markerPriceX, markerPriceY);
            scene->addLine(markerPriceX, markerPriceY, markerPriceX + daySize * data->daysTrading() + extraWidth, markerPriceY, pen);
        }

    }

    //draw dates and lines
    if (data->tradeDataAvailable() > 0) {
        std::TradeData firstTrade = data->getData(0);

        int daysBetweenDateMarkers = 14;
        int dayUpto = 0;
        std::Date currDate = std::Helper::parseDate(firstTrade.date);


        while (dayUpto < data->daysTrading()) {
            //scene->addText("asdasdsad", QFont("Times", 13))->setPos(startX + dayUpto*daySize, startY);
            scene->addLine(startX + dayUpto*daySize, startY, startX + dayUpto*daySize, -startY, pen);
            scene->addText(QString::fromStdString(std::Helper::dateString(currDate)), normalFont)->setPos(startX + dayUpto*daySize - 9.0, startY);
            currDate = std::Helper::addDays(currDate, daysBetweenDateMarkers);
            dayUpto += daysBetweenDateMarkers;
        }

    }

    //scene->addText("asd", QFont());

    int startOfDaysPos = (-daySize) * data->daysTrading() / 2;

    double prevX, prevY;
    bool hasPreviousPos = false;

    for (int i = 0; i < data->tradeDataAvailable(); ++i) {
        std::TradeData trade = data->getData(i);

        double pricePercentToMax = (trade.price - data->lowestPrice()) / (data->highestPrice() - data->lowestPrice());

        QBrush brush = QBrush(Qt::blue);
        if (trade.tradeSignal == std::SELL) {
            brush = QBrush(Qt::green);
        }

        scene->addEllipse(shiftX + startOfDaysPos + daySize * trade.tradeDayOffset, shiftY + chartHeight/2.0 - chartHeight * pricePercentToMax, daySize, daySize, pen, brush);

        double thisX = shiftX + startOfDaysPos + daySize * trade.tradeDayOffset + daySize/2.0;
        double thisY = shiftY + chartHeight/2.0 - chartHeight * pricePercentToMax + daySize/2.0;

        if (hasPreviousPos) {
            scene->addLine(thisX, thisY, prevX, prevY, pen);
        }

        hasPreviousPos = true;
        prevX = thisX;
        prevY = thisY;
    }

    ui->tradeSimulator_graphicsGraphDisplay->setScene(scene);
    ui->tradeSimulator_graphicsGraphDisplay->setRenderHints( QPainter::Antialiasing );
    //ui->graphicsGraphDisplay->setHorizontalScrollBar();
    //ui->graphicsGraphDisplay->scrollContentsBy(0, 0);
    //ui->scrollArea_2->horizontalScrollBar()->setValue(0);
}
