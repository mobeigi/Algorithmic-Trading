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

void ParamSet::releaseAllAnalysisData() {
    for (AnalysisData *dat : analysisData) {
        if (dat != nullptr) delete dat;
    }
    analysisData = vector<AnalysisData *>();
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

void ParamSet::setAnalysisDataForEachStrat(vector<AnalysisData *> analysisData) {
    this->analysisData = analysisData;
}


AnalysisData *ParamSet::getAnalysisDataForStrat(int strategyIndex) {
    if (strategyIndex >= analysisData.size() || strategyIndex < 0)
        return nullptr;
    return analysisData[strategyIndex];
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



