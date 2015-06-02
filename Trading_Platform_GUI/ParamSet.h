#ifndef PARAMSET_H
#define PARAMSET_H

#include "GlobalIncludes.h"

#include <map>
#include "QuantPara.h"
#include "AnalysisData.h"


namespace std
{

struct Para {
    double qnt = 0.0;
    double raw = 0.0;
    bool valid = false; //false means there was not enough data to evaluate, or no trades etc

    inline Para operator+(Para a) {
        a.qnt += qnt;
        a.raw += raw;
        a.valid = a.valid && valid;
        return a;
    }
};

class ParamSet
{
private:
    string equityType, dateStart, dateEnd;
    int numStrategies;
    map<string, vector<Para>> quantifiedParameters;
    vector<AnalysisData *> analysisData;
public:
    ParamSet(string equityType, string dateStart, string dateEnd, int numStrategies);
    ~ParamSet();

    //rawValsForEachStrat should be in same order, first strategy at index 0 and so on
    void setParam(QuantPara *paraType, vector<Para> rawValsForEachStrat);

    void setAnalysisDataForEachStrat(vector<AnalysisData *> csvData);
    AnalysisData *getAnalysisDataForStrat(int strategyIndex);

    inline int getNumberOfStrategies() {return numStrategies;}
    inline string getEquityType() {return equityType;}
    inline string getStartDate() {return dateStart;}
    inline string getEndDate() {return dateEnd;}

    /* paraTypes:
     * paraReturns
     * paraGranality
     * paraVolatility
     * */
    Para getQuantifiedParameter(QuantPara *paraType, int strategyIndex);

    //deletes all csv data this obj contains
    void releaseAllAnalysisData();

};

}

#endif // PARAMSET_H
