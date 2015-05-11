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

void AnalysisDisplays::showAnalysisDisplays() {

    QMainWindow *mw = new QMainWindow();
    mw->setFixedSize(750,700);
    mw->setWindowTitle("Equity Strategy Analysis");
    QTabWidget *tabw = new QTabWidget(mw);
    tabw->setFixedSize(750,700);

    for (QListWidgetItem *wi: listItems) {
        if (wi->checkState()) {
            std::string eqType = wi->text().toStdString();

            DisplayAnalysis *dw = new DisplayAnalysis();

            displays[currentDisplayId] = dw;

            //Add this tab to tab widget
            tabw->addTab(dw, eqType.c_str());

            dw->setDisplayId(currentDisplayId);
            currentDisplayId++;
            dw->show();

            dw->displayAnalysis(parseCSV->getDataForEquityType(eqType));
        }

    }

    //Show the main window
    mw->show();
}

void AnalysisDisplays::analyzeCSVOutput(std::string csvFile, QWidget *parent) {

    std::ParseCSVData parseCSV = std::ParseCSVData(csvFile);

    if (parseCSV.getAllEquityTypes().size() == 0) {
        QMessageBox::question(parent, "No Equity Trades", "The strategy suggested no equity trades.", QMessageBox::Ok);
        return;
    }

    QMainWindow *mw = new QMainWindow();
    mw->setFixedSize(750,700);
    mw->setWindowTitle("Equity Strategy Analysis");
    QTabWidget *tabw = new QTabWidget(mw);
    tabw->setFixedSize(750,700);

    std::ParseCSVData tmpParseCSV = std::ParseCSVData(csvFile);

    for (std::string eqType : tmpParseCSV.getAllEquityTypes()) {

        DisplayAnalysis *dw = new DisplayAnalysis();

        displays[currentDisplayId] = dw;

        //Add this tab to tab widget
        tabw->addTab(dw, eqType.c_str());

        dw->setDisplayId(currentDisplayId);
        currentDisplayId++;
        dw->show();

        dw->displayAnalysis(tmpParseCSV.getDataForEquityType(eqType));
    }

    //Show the main window
    mw->show();
}

void AnalysisDisplays::displayClosing(long displayId) {
    if (displays.find(displayId) != displays.end()) {
        DisplayAnalysis *display = displays[displayId];
        delete display;
        displays.erase(displayId);
    }
}







