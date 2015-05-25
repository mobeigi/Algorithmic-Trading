#include "ParamSet.h"

namespace std
{

ParamSet::ParamSet(string equityType, string dateStart,
                   string dateEnd, int numStrategies) : equityType(equityType),
    dateStart(dateStart), dateEnd(dateEnd), numStrategies(numStrategies) {

    if (numStrategies <= 0) {
        ERR_FATAL("ParamSet: numStrategies must be > 0!\n");
    }

}

ParamSet::~ParamSet() {}

vector<ParamSet> ParamSet::generateTestAnalysis() {

    vector<Para> paras;
    Para para; para.valid = true;

    ParamSet p = ParamSet("A", "10-10-2015", "30-12-2015", 3);
    paras = vector<Para>();
    para.raw = 32.3; paras.push_back(para);
    para.raw = 12; paras.push_back(para);
    para.raw = 3.3; paras.push_back(para);
    p.setParam(paraReturns, paras);
    paras = vector<Para>();
    para.raw = 322.3; paras.push_back(para);
    para.raw = 34; paras.push_back(para);
    para.raw = 31.3; paras.push_back(para);
    p.setParam(paraGranality, paras);
    paras = vector<Para>();
    para.raw = 22.3; paras.push_back(para);
    para.raw = 14; paras.push_back(para);
    para.raw = 2.3; paras.push_back(para);
    p.setParam(paraVolatility, paras);

    ParamSet p2 = ParamSet("B", "10-10-2015", "30-12-2015", 3);
    paras = vector<Para>();
    para.raw = 32.3; paras.push_back(para);
    para.raw = 12; paras.push_back(para);
    para.raw = 3.3; paras.push_back(para);
    p2.setParam(paraReturns, paras);
    paras = vector<Para>();
    para.raw = 322.3; paras.push_back(para);
    para.raw = 34; paras.push_back(para);
    para.raw = 31.3; paras.push_back(para);
    p2.setParam(paraGranality, paras);
    paras = vector<Para>();
    para.raw = 22.3; paras.push_back(para);
    para.raw = 14; paras.push_back(para);
    para.raw = 2.3; para.valid = false; paras.push_back(para);
    p2.setParam(paraVolatility, paras);

    return {p, p2};
}

//rawValsForEachStrat should be in same order, first strategy at index 0 and so on
void ParamSet::setParam(QuantPara *paraType, vector<Para> rawValsForEachStrat) {
    string paraId = paraType->getName();

    if (rawValsForEachStrat.size() != (size_t)numStrategies) {
        ERR_FATAL("ParamSet: Set param, numStrategies inconsistency error!\n");
    }

    //find min max and average
    double sum = 0;
    bool firstYet = false;
    double max = 0;
    double min = 0;
    for (Para val : rawValsForEachStrat) {
        if (val.valid) {
            sum += val.raw;
            if (!firstYet) {
                firstYet = true;
                min = val.raw;
                max = val.raw;
            } else {
                if (val.raw > max) max = val.raw;
                if (val.raw < min) min = val.raw;
            }
        }
    }
    double avg = sum / double(rawValsForEachStrat.size());

    vector<Para> quantParams = vector<Para>();
    for (Para par : rawValsForEachStrat) {
        par.qnt = paraType->calculateParam(par.raw, max, min, avg);
        quantParams.push_back(par);
    }

    quantifiedParameters[paraId] = quantParams;
}

Para ParamSet::getQuantifiedParameter(QuantPara *paraType, int strategyIndex) {
    string paraId = paraType->getName();

    if (quantifiedParameters.find(paraId) == quantifiedParameters.end()) {
        ERR_FATAL("ParamSet: param type incorrect or not analyzed!\n");
    }
    if (strategyIndex < 0 || strategyIndex >= numStrategies) {
        ERR_FATAL("ParamSet: requested strat index incorrect!\n");
    }

    return quantifiedParameters[paraId][strategyIndex];

}

}



