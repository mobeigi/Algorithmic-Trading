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
}

void DisplayAnalysis::setDisplayId(long displayId) {
    this->displayId = displayId;
}

void DisplayAnalysis::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    AnalysisDisplays::instance()->displayClosing(displayId);
}

void DisplayAnalysis::displayAnalysis(std::AnalysisData *data) {

    this->setWindowTitle(QString::fromStdString("Equity Strategy Analysis (" + data->getCompany() + ")"));

    double daySize = 7.0;
    double chartHeight = 240.0;

    if (scene != nullptr)
        delete scene;
    scene = new QGraphicsScene();

    double extraWidth = 150.0;
    double extraBase = 30.0;
    scene->setSceneRect( (-daySize) * data->daysTrading() / 2 - extraWidth/2.0, -(chartHeight/2.0), daySize * data->daysTrading() + extraWidth, chartHeight + extraBase);

    QPen pen;


    double startX = (-daySize) * data->daysTrading() / 2 + daySize/2;
    double startY = chartHeight/2.0 + daySize + 4;

    //draw price markers
    double markerPriceX = startX - 70.0;
    int numPriceMarkers = 5;

    //chartHeight/2.0 - chartHeight * pricePercentToMax + daySize/2.0;

    for (int i = 0; i != numPriceMarkers; ++i) {
        double percentMarker = static_cast<double>(i) / (static_cast<double>(numPriceMarkers) - 1.0);
        double markerPriceY = chartHeight/2.0 - chartHeight * percentMarker + daySize/2.0;
        scene->addText(QString::fromStdString(std::Helper::formatPrice(percentMarker * (data->highestPrice() - data->lowestPrice()) + data->lowestPrice())), QFont("Times", 13))->setPos(markerPriceX, markerPriceY);
        scene->addLine(markerPriceX, markerPriceY, markerPriceX + daySize * data->daysTrading() + extraWidth, markerPriceY, pen);
    }

    //draw dates and lines
    if (data->tradeDataAvaliable() > 0) {
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

    for (int i = 0; i < data->tradeDataAvaliable(); ++i) {
        std::TradeData trade = data->getData(i);

        double pricePercentToMax = (trade.price - data->lowestPrice()) / (data->highestPrice() - data->lowestPrice());

        QBrush brush = QBrush(Qt::blue);
        if (trade.tradeSignal == std::SELL) {
            brush = QBrush(Qt::green);
        }

        scene->addEllipse(startOfDaysPos + daySize * trade.tradeDayOffset, chartHeight/2.0 - chartHeight * pricePercentToMax, daySize, daySize, pen, brush);

        double thisX = startOfDaysPos + daySize * trade.tradeDayOffset + daySize/2.0;
        double thisY = chartHeight/2.0 - chartHeight * pricePercentToMax + daySize/2.0;

        if (hasPreviousPos) {
            scene->addLine(thisX, thisY, prevX, prevY, pen);
        }

        hasPreviousPos = true;
        prevX = thisX;
        prevY = thisY;
    }

    ui->graphicsGraphDisplay->setScene(scene);
    ui->graphicsGraphDisplay->setRenderHints( QPainter::Antialiasing );
}

DisplayAnalysis::~DisplayAnalysis()
{
    delete ui;
    if (scene != nullptr)
        delete scene;
}
