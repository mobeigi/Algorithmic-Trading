#include "AnalysisDisplays.h"
#include "DisplayAnalysis.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void AnalysisDisplays::showCheckList(std::string csvFile, QListWidget* lw, QWidget *parent) {

    parseCSV = new std::ParseCSVData(csvFile);

    //Add checkboxes to list for each company
    for (std::string eqType : parseCSV->getAllEquityTypes()) {
        const QString itemName = eqType.c_str();
        QListWidgetItem *item = new QListWidgetItem(itemName, lw);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable); // set checkable flag
        item->setCheckState(Qt::Unchecked); // AND initialize check state
        lw->addItem(item);
        listItems.push_back(item);
    }

    if (parseCSV->getAllEquityTypes().size() == 0) {
        QMessageBox::question(parent, "No Equity Trades", "The strategy suggested no equity trades.", QMessageBox::Ok);
    }

}

void AnalysisDisplays::showAnalysisDisplays(QWidget *parent) {

    /*
    DisplayAnalysis *w = new DisplayAnalysis();
    displays[currentDisplayId] = w;
    w->setDisplayId(currentDisplayId);
    currentDisplayId++;

    for (std::string eqType : parseCSV->getAllEquityTypes()) {
        w->show();
        w->displayAnalysis(parseCSV->getDataForEquityType(eqType));
    }

    w->show();
    w->displayAnalysis(parseCSV->getDataForEquityType(eqType));
    */
}

void AnalysisDisplays::analyzeCSVOutput(std::string csvFile, QWidget *parent) {
    /*
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
    */

}

void AnalysisDisplays::displayClosing(long displayId) {
    if (displays.find(displayId) != displays.end()) {
        DisplayAnalysis *display = displays[displayId];
        delete display;
        displays.erase(displayId);
    }
}







