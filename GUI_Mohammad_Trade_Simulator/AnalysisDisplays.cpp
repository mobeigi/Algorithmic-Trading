#include "AnalysisDisplays.h"
#include "DisplayAnalysis.h"
#include "SummaryForm.h"
#include "MyTabWindow.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

AnalysisDisplays* __analysisDisplays = nullptr;

AnalysisDisplays::AnalysisDisplays()
{
    currentDisplayId = 0;
    parseCSV = nullptr;
}

AnalysisDisplays::~AnalysisDisplays()
{
    if (parseCSV != nullptr) delete parseCSV;
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


}

void AnalysisDisplays::showAnalysisDisplays(QWidget *parent) {

    QMainWindow *mw = new QMainWindow(parent);

    mw->setWindowTitle("Equity Strategy Analysis");
    mw->setMinimumSize(750, 700);

    MyTabWidget *tabw = new MyTabWidget(mw, this->parseCSV);
    mw->setCentralWidget(tabw);

    //Load summary tab
    SummaryForm *summary = new SummaryForm(tabw);
    std::string summaryText = "Summary";
    tabw->addTab(summary, summaryText.c_str());
    tabw->addEqType(summaryText);

    //Create vector of checked equities
    vector<string> eqTypeList;
    for (QListWidgetItem *wi: listItems) {
         if (wi->checkState()) {
            eqTypeList.push_back(wi->text().toStdString());
        }
    }

    //Set total returns
    summary->setTotalNetReturns(this->parseCSV, eqTypeList);
    summary->show();

    //Load company tabs
    for (QListWidgetItem *wi: listItems) {
        if (wi->checkState()) {
            std::string eqType = wi->text().toStdString();

            tabw->addEqType(eqType);

            DisplayAnalysis *dw = new DisplayAnalysis();

            displays[currentDisplayId] = dw;

            //Add this tab to tab widget
            tabw->addTab(dw, eqType.c_str());

            dw->setDisplayId(currentDisplayId);
            currentDisplayId++;
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

    QMainWindow *mw = new QMainWindow(parent);

    mw->setWindowTitle("Equity Strategy Analysis");
    mw->setMinimumSize(750, 700);

    QTabWidget *tabw = new QTabWidget(mw);
    mw->setCentralWidget(tabw);

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







