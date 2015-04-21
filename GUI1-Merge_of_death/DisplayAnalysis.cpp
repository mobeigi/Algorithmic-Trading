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
    scene->addText("E\nq\nu\ni\nt\ny\n \nP\nr\ni\nc\ne", QFont("Times", 16))->setPos(yAxisLabelX, yAxisLabelY);

    //draw x axis label "date"
    double xAxisLabelY = shiftY + chartHeight/2.0 + 35.0;
    double xAxisLabelX = shiftX + (-daySize) * data->daysTrading() / 2 + 50.0;
    scene->addText("Date", QFont("Times", 16))->setPos(xAxisLabelX, xAxisLabelY);


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
            scene->addText(QString::fromStdString(std::Helper::formatPrice(percentMarker * (data->highestPrice() - data->lowestPrice()) + data->lowestPrice())), QFont("Times", 13))->setPos(markerPriceX, markerPriceY);
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
            scene->addText(QString::fromStdString(std::Helper::formatPrice(percentMarker * (data->highestPrice() - data->lowestPrice()) + data->lowestPrice())), QFont("Times", 13))->setPos(markerPriceX, markerPriceY);
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
            scene->addText(QString::fromStdString(std::Helper::dateString(currDate)), QFont("Times", 13))->setPos(startX + dayUpto*daySize - 9.0, startY);
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
    //maintain queues of trades, one for buy and one for sell
    // int is for maintaining which one came first
    vector<tuple<TradeData, int>> buy_trades;
    vector<tuple<TradeData, int>> sell_trades;

    //maintain total return percentage
    double net_return_perc = 0;

    //read the trade orders line by line
    for (int i = 0; i < data->tradeDataAvailable(); i++) {

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

            if (get<1>(sell_trade) > get<1>(buy_trade)) {
                //a buy-sell pair
                printf("Buy@%.2lf,", get<0>(buy_trade).price);
                printf("Sell@%.2lf. ", get<0>(sell_trade).price);
                printf("Date: %s. ",get<0>(sell_trade).date.c_str());
            } else {
                //a sell-buy pair
                printf("Buy@%.2lf,", get<0>(sell_trade).price);
                printf("Sell@%.2lf. ", get<0>(buy_trade).price);
                printf("Date: %s. ",get<0>(buy_trade).date.c_str());
            }

            //Calculate return
            double return_perc = (get<0>(sell_trade).price - get<0>(buy_trade).price) / get<0>(buy_trade).price;
            printf("Return: %.2lf\n",return_perc);

            //update total return
            net_return_perc += return_perc;

            //Remove the first trades from both queues
            buy_trades.erase(buy_trades.begin(),buy_trades.begin()+1);
            sell_trades.erase(sell_trades.begin(),sell_trades.begin()+1);
        }
    }

    printf("FINAL NET RETURN: %.2lf\n",net_return_perc);

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
