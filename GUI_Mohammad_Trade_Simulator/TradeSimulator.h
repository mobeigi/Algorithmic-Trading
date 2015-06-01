#ifndef TRADESIMULATOR_H
#define TRADESIMULATOR_H

#include "GlobalIncludes.h"
#include "ParseInputCSVData.h"

#include <QWidget>
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
    void addTradeData(std::string eqType, vector<TradeDayData> data) {
       this->eqType = eqType;
        this->data = data;
    }

private:
    Ui::TradeSimulator *ui;
    std::string eqType;
    vector<TradeDayData> data;
};

#endif // TRADESIMULATOR_H
