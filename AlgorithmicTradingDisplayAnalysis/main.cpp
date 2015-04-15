#include "DisplayAnalysis.h"
#include "ParseCSVData.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    std::ParseCSVData parseCSV = std::ParseCSVData("/Users/admin/Documents/COMP3011/Algorithmic-Trading/build-AlgorithmicTradingDisplayAnalysis-Desktop_Qt_5_4_1_clang_64bit-Debug/BHP.csv");///Users/admin/Documents/COMP3011/Algorithmic-Trading/build-AlgorithmicTradingDisplayAnalysis-Desktop_Qt_5_4_1_clang_64bit-Debug/BHP.csv
    std::vector<DisplayAnalysis *> analysisDisplays;


    for (std::string eqType : parseCSV.getAllEquityTypes()) {

        DisplayAnalysis *w = new DisplayAnalysis();
        analysisDisplays.push_back(w);
        w->show();
        w->displayAnalysis(parseCSV.getDataForEquityType(eqType));
    }



    //test data
    /*std::AnalysisData data("TestCompany");
    DisplayAnalysis w;
    w.show();

    data.addNextTradeData(std::BUY, "07-FEB-2000", 18.80, 100);
    data.addNextTradeData(std::SELL, "09-FEB-2000", 18.35, 100);
    data.addNextTradeData(std::BUY, "15-FEB-2000", 17.80, 100);
    data.addNextTradeData(std::SELL, "22-FEB-2000", 16.81, 100);
    data.addNextTradeData(std::BUY, "24-FEB-2000", 16.84, 100);
    data.addNextTradeData(std::SELL, "28-FEB-2000", 16.12, 100);
    data.addNextTradeData(std::BUY, "01-MAR-2000", 16.2, 100);
    data.addNextTradeData(std::SELL, "08-MAR-2000", 16.07, 100);
    data.addNextTradeData(std::BUY, "01-MAY-2000", 16.2, 100);



    w.displayAnalysis(&data);*/

    int retval = a.exec();

    for (DisplayAnalysis *analysisDisplay : analysisDisplays) {
        delete analysisDisplay;
    }

    return retval;

}
