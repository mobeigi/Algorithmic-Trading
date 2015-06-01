#ifndef TRADESIMULATOR_H
#define TRADESIMULATOR_H

#include "GlobalIncludes.h"

#include <QWidget>

using namespace std; //for vectors

namespace Ui {
class TradeSimulator;
}

class TradeSimulator : public QWidget
{
    Q_OBJECT

public:
    explicit TradeSimulator(QWidget *parent = 0);

private:
    Ui::TradeSimulator *ui;
};

#endif // TRADESIMULATOR_H
