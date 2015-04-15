#include "DisplayAnalysis.h"
#include "ui_DisplayAnalysis.h"

DisplayAnalysis::DisplayAnalysis(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DisplayAnalysis)
{
    ui->setupUi(this);

}

void DisplayAnalysis::displayAnalysis(std::AnalysisData *data) {

    this->setWindowTitle(QString::fromStdString("Equity Strategy Analysis (" + data->getCompany() + ")"));

    double daySize = 7.0;
    double chartHeight = 200.0;

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect( (-daySize) * data->daysTrading() / 2, -(chartHeight/2.0), daySize * data->daysTrading(), chartHeight );

    QPen pen;

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
}
