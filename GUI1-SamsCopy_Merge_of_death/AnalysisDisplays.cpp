#include "AnalysisDisplays.h"

#include "DisplayAnalysis.h"

AnalysisDisplays* __analysisDisplays = nullptr;

AnalysisDisplays::AnalysisDisplays()
{
    currentDisplayId = 0;
}

AnalysisDisplays::~AnalysisDisplays()
{

}

AnalysisDisplays *AnalysisDisplays::instance() {
    if (__analysisDisplays == nullptr) {
        __analysisDisplays = new AnalysisDisplays();
    }
    return __analysisDisplays;
}


void AnalysisDisplays::analyzeCSVOutput(std::string csvFile, QWidget *parent) {

    std::ParseCSVData parseCSV = std::ParseCSVData(csvFile);

    for (std::string eqType : parseCSV.getAllEquityTypes()) {

        DisplayAnalysis *w = new DisplayAnalysis();
        displays[currentDisplayId] = w;
        w->setDisplayId(currentDisplayId);
        currentDisplayId++;
        w->show();
        w->displayAnalysis(parseCSV.getDataForEquityType(eqType));
    }

    if (parseCSV.getAllEquityTypes().size() == 0) {
        QMessageBox::question(parent, "No Equity Trades", "The strategy suggested no equity trades.", QMessageBox::Ok);
    }

}

void AnalysisDisplays::displayClosing(long displayId) {
    if (displays.find(displayId) != displays.end()) {
        DisplayAnalysis *display = displays[displayId];
        delete display;
        displays.erase(displayId);
    }
}







