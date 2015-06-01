#include "TradeSimulator.h"
#include "ui_tradesimulator.h"

TradeSimulator::TradeSimulator(QWidget *parent) :
    QWidget(parent), ui(new Ui::TradeSimulator)
{
    this->ui->setupUi(this);
    this->setWindowTitle("Trock Trade Simulator");
}
