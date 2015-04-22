#include "DisplayAnalysis.h"
#include "ui_DisplayAnalysis.h"

#include "AnalysisDisplays.h"

DisplayAnalysis::DisplayAnalysis(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DisplayAnalysis)
{
    ui->setupUi(this);
    scene = nullptr;
    displayId = -1;

    //ui->scrollArea_2->horizontalScrollBar()->setValue(0);
}

void DisplayAnalysis::setDisplayId(long displayId) {
    this->displayId = displayId;
}

void DisplayAnalysis::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    AnalysisDisplays::instance()->displayClosing(displayId);
}

void DisplayAnalysis::displayGraphAnalysis(std::AnalysisData *data) {

    //QFont titleFont("Times", 16);
    //QFont normalFont("Times", 9);

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

    ui->graphicsGraphDisplay->setScene(scene);
    ui->graphicsGraphDisplay->setRenderHints( QPainter::Antialiasing );
    //ui->graphicsGraphDisplay->setHorizontalScrollBar();
    //ui->graphicsGraphDisplay->scrollContentsBy(0, 0);
    //ui->scrollArea_2->horizontalScrollBar()->setValue(0);
}


void DisplayAnalysis::displayReturnsAnalysis(std::AnalysisData *data) {

    //Prepare the table
    ui->returnsAnalysis->setColumnCount(4);                     //for the four headings: buy,sell,date,and return
    ui->returnsAnalysis->verticalHeader()->setVisible(false);   //hide line numbers
    ui->returnsAnalysis->setHorizontalHeaderLabels(QString("Buy-Sell Pair;Date;Return Value;Return %").split(";")); //insert column names

   //adjusting header sizes
    ui->returnsAnalysis->horizontalHeader()->resizeSection(0,215);
    ui->returnsAnalysis->horizontalHeader()->resizeSection(1,170);
    ui->returnsAnalysis->horizontalHeader()->resizeSection(2,145);
    ui->returnsAnalysis->horizontalHeader()->resizeSection(3,155);


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

    //Display net return
    QString net_return_perc_str;
    char netReturnValueBuffer[50];
    if (net_return_value < 0) {
        sprintf(netReturnValueBuffer,"-$%.2lf",net_return_value * (-1));
    } else {
        sprintf(netReturnValueBuffer,"$%.2lf",net_return_value);
    }
    net_return_perc_str.append(netReturnValueBuffer);

    net_return_perc_str.append(" (");
    net_return_perc_str.append(QString::number(net_return_perc));
    net_return_perc_str.append("%)");
    ui->net_return_value_label->setText(net_return_perc_str);

}

void DisplayAnalysis::insertRowIntoReturnsAnalysis(std::string buySellPair,
                                                   std::string date,
                                                    std::string returnValue,
                                                   std::string returnPerc) {

    //increase table rows by 1
    int currRows = ui->returnsAnalysis->rowCount();
    ui->returnsAnalysis->setRowCount(currRows + 1);


    QTableWidgetItem* col0 = new QTableWidgetItem(QString::fromStdString(buySellPair), QTableWidgetItem::Type);
    col0->setFlags(col0->flags() ^ Qt::ItemIsEditable);
    col0->setTextAlignment(Qt::AlignHCenter);
    ui->returnsAnalysis->setItem(currRows,0, col0);

    QTableWidgetItem* col1 = new QTableWidgetItem(QString::fromStdString(date), QTableWidgetItem::Type);
    col1->setFlags(col1->flags() ^ Qt::ItemIsEditable);
    col1->setTextAlignment(Qt::AlignHCenter);
    ui->returnsAnalysis->setItem(currRows, 1, col1);

    QTableWidgetItem* col2 = new QTableWidgetItem(QString::fromStdString(returnValue), QTableWidgetItem::Type);
    col2->setFlags(col2->flags() ^ Qt::ItemIsEditable);
    col2->setTextAlignment(Qt::AlignHCenter);
    ui->returnsAnalysis->setItem(currRows, 2, col2);

    QTableWidgetItem* col3 = new QTableWidgetItem(QString::fromStdString(returnPerc), QTableWidgetItem::Type);
    col3->setFlags(col2->flags() ^ Qt::ItemIsEditable);
    col3->setTextAlignment(Qt::AlignHCenter);
    ui->returnsAnalysis->setItem(currRows, 3, col3);
}


void DisplayAnalysis::displayAnalysis(std::AnalysisData *data) {

    this->setWindowTitle(QString::fromStdString("Equity Strategy Analysis (" + data->getCompany() + ")"));

    this->displayGraphAnalysis(data);
    this->displayReturnsAnalysis(data);
}

DisplayAnalysis::~DisplayAnalysis()
{
    delete ui;
    if (scene != nullptr)
        delete scene;
}
