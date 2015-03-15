#include "mainwindow.h"
#include <QApplication>

#include "MomentumStrategy.h"
#include "Logger.h"
#include "TradeDay.h"


void test(std::vector<std::TradeDay> trades) {
    std::Logger logger = std::Logger::standardLogger();
    std::MomentumStrategy strategy = std::MomentumStrategy(logger, 4, 0.001);
    for (std::TradeDay tradeDay : trades) {
        strategy.nextDay(tradeDay);
    }
    //logger.log(result.description());
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    std::vector<std::TradeDay> testTrades = {
            std::TradeDay(30),
            std::TradeDay(30.34),
            std::TradeDay(30.71),
            std::TradeDay(31.09),
            std::TradeDay(31.54),
            std::TradeDay(31.76),
            std::TradeDay(31.98),
            std::TradeDay(32.58)};

    test(testTrades);

    return a.exec();
}
