#ifndef TRADESIMULATOR_H
#define TRADESIMULATOR_H

#include "GlobalIncludes.h"
#include "ParseInputCSVData.h"
#include "ui_tradesimulator.h"
#include "AnalysisData.h"

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QScrollBar>

#include <QWidget>
#include <thread>
#include <vector>

using namespace std; //for vectors

namespace Ui {
class TradeSimulator;
}

class TradeSimulator : public QWidget
{
    Q_OBJECT

public:
    explicit TradeSimulator(QWidget *parent = 0);
    void addTradeData(string eqType, vector<TradeDayData> data);

    //Runs trade simulation in a thread
    void runSimulation();
    void simulationWorker();

    void displayGraphAnalysis(std::AnalysisData *data);
    void displayReturnsAnalysis(std::AnalysisData *data);

    void insertRowIntoReturnsAnalysis(std::string buySellPair,
                                      std::string date,
                                      std::string returnValue,
                                      std::string returnPerc);

signals:
    void sendEndThread();

private slots:
    void on_sendBuySignal_clicked();
    void on_sendSellSignal_clicked();
    void on_exportOrderFileButton_clicked();

    void doThreadEndActions();

private:
    Ui::TradeSimulator *ui;
    std::string eqType;
    vector<TradeDayData> data;
    vector<TradeDayData> userTrades;
    QGraphicsScene *scene = nullptr;
    std::thread *simWorker = nullptr;
    std::AnalysisData *cumulativeData = nullptr;
    bool isBuyEnabled = true;
    bool isSellEnabled = false;
    int index = -1;
    int lastTradeIndex = -1;
    static const int updatePeriod = 3000;
};

#endif // TRADESIMULATOR_H
