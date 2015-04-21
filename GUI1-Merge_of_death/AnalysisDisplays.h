#ifndef ANALYSISDISPLAYS_H
#define ANALYSISDISPLAYS_H

#include "DisplayAnalysis.h"
#include "ParseCSVData.h"
#include "GlobalIncludes.h"

#include<QMessageBox>

#include <map>

class AnalysisDisplays
{

private:
    AnalysisDisplays();

    std::map<long, DisplayAnalysis *> displays;
    long currentDisplayId;

public:
    ~AnalysisDisplays();
    static AnalysisDisplays *instance();

    void analyzeCSVOutput(std::string csvFile, QWidget *parent);
    void displayClosing(long displayId);
};

#endif // ANALYSISDISPLAYS_H
