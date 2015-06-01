#include "mainwindow.h"
#include <QApplication>


#include "TradeSimulator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    TradeSimulator *ts = new TradeSimulator();
    ts->show();

    return a.exec();
}
