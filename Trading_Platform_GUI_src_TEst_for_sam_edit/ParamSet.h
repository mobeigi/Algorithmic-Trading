#ifndef PARAMSET_H
#define PARAMSET_H

#include "GlobalIncludes.h"

#include <map>
#include "QuantPara.h"


namespace std
{

struct Para {
    double qnt = 0.0;
    double raw = 0.0;
    bool valid = false; //false means there was not enough data to evaluate, or no trades etc
};

class ParamSet
{
private:
    string equityType, dateStart, dateEnd;
    int numStrategies;
    map<string, vector<Para>> quantifiedParameters;
public:
    ParamSet(string equityType, string dateStart, string dateEnd, int numStrategies);
    ~ParamSet();

    static vector<ParamSet> generateTestAnalysis();

    //rawValsForEachStrat should be in same order, first strategy at index 0 and so on
    void setParam(QuantPara *paraType, vector<Para> rawValsForEachStrat);

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

};

}

#endif // PARAMSET_H
