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


void AnalysisDisplays::analyzeCSVOutput(std::string csvFile) {

    std::ParseCSVData parseCSV = std::ParseCSVData(csvFile);

    for (std::string eqType : parseCSV.getAllEquityTypes()) {

        DisplayAnalysis *w = new DisplayAnalysis();
        displays[currentDisplayId] = w;
        w->setDisplayId(currentDisplayId);
        currentDisplayId++;
        w->show();
        w->displayAnalysis(parseCSV.getDataForEquityType(eqType));
    }

}

void AnalysisDisplays::displayClosing(long displayId) {
    if (displays.find(displayId) != displays.end()) {
        DisplayAnalysis *display = displays[displayId];
        delete display;
        displays.erase(displayId);
    }
}







