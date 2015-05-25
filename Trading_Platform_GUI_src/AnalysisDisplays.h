#ifndef ANALYSISDISPLAYS_H
#define ANALYSISDISPLAYS_H

#include "DisplayAnalysis.h"
#include "ParseCSVData.h"
#include "GlobalIncludes.h"

#include <QMessageBox>
#include <QListWidget>

#include <map>

class AnalysisDisplays
{

private:
    std::map<long, DisplayAnalysis *> displays;
    std::vector<QListWidgetItem *> listItems;
    std::ParseCSVData *parseCSV;
    long currentDisplayId;

public:
    AnalysisDisplays();
    ~AnalysisDisplays();
    static AnalysisDisplays *instance();

    inline std::vector<QListWidgetItem *> getListItems() { return listItems; }
    void analyzeCSVOutput(std::string csvFile, QWidget *parent);
    void showAnalysisDisplays(QWidget *parent);
    void showCheckList(std::string csvFile, QListWidget* lw);
    void displayClosing(long displayId);
};

#endif // ANALYSISDISPLAYS_H
