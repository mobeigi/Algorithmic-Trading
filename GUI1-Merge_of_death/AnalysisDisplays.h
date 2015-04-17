#ifndef ANALYSISDISPLAYS_H
#define ANALYSISDISPLAYS_H

#include "DisplayAnalysis.h"
#include "ParseCSVData.h"
#include "GlobalIncludes.h"


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

    void analyzeCSVOutput(std::string csvFile);
    void displayClosing(long displayId);
};

#endif // ANALYSISDISPLAYS_H
