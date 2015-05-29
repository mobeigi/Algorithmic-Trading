#ifndef PARAMANALYSISHELPER_H
#define PARAMANALYSISHELPER_H

#include "GlobalIncludes.h"

#include <vector>
#include "ParamSet.h"
#include "ParseCSVData.h"

namespace std
{

struct StrategyData {
    string name; //name of strategy
    vector<ParseCSVData *> dataForEachDateRange;
};

class ParamAnalysisHelper
{
private:
    ParamAnalysisHelper();
public:

    //equityTypes - list of each type of equity to expect and in the display order

    //dateRanges - (from, to) dates used for each strategy

    //strategiesData - data for each strategy run, strategiesData.dataForEachDateRange
    //should be the same for every strategy, since they need to be compared
    //"performParamAnalysis" DOES NOT become the owner of
    //each strategiesData.dataForEachDateRange object

    //the order of indexes in strategiesData will determine the index of the strategy in each
    //ParamSet

    static vector<ParamSet> performParamAnalysis(vector<string> equityTypes,
                                          vector<tuple<string, string>> dateRanges,
                                          vector<StrategyData> strategiesData);
};

}

#endif // PARAMANALYSISHELPER_H
