#include "ParamAnalysisHelper.h"

namespace std
{

ParamAnalysisHelper::ParamAnalysisHelper() {}

vector<ParamSet> ParamAnalysisHelper::performParamAnalysis(vector<string> equityTypes,
                                      vector<tuple<string, string>> dateRanges,
                                      vector<StrategyData> strategiesData) {

    vector<ParamSet> paramSet = vector<ParamSet>();

    Para invalidPara;
    invalidPara.valid = false;

    //each equity type
    for (size_t equityIndex = 0; equityIndex < equityTypes.size(); ++equityIndex) {
        string equityType = equityTypes[equityIndex];

        //each date range in each equity type
        for (size_t dateIndex = 0; dateIndex < dateRanges.size(); ++dateIndex) {
            string startDate = get<0>(dateRanges[dateIndex]);
            string endDate = get<1>(dateRanges[dateIndex]);

            ParamSet pSet = ParamSet(equityType, startDate, endDate, strategiesData.size());

            vector<Para> returnVals = vector<Para>();
            vector<Para> granalityVals = vector<Para>();
            vector<Para> volatilityVals = vector<Para>();
            vector<AnalysisData *> analysisDataSetVals = vector<AnalysisData *>();

            //each strategy column
            for (StrategyData stratData : strategiesData) {

                if (stratData.dataForEachDateRange.size() <= dateIndex) {
                    ERR_FATAL("ParamAnalysisHelper: data for date range too small!\n");
                }

                ParseCSVData *data =  stratData.dataForEachDateRange[dateIndex];
                AnalysisData *dataSet = data->getDataForEquityType(equityType);

                if (dataSet == nullptr) {
                    //no dataSet for this equity type, probably means there were no trades
                    returnVals.push_back(invalidPara);
                    granalityVals.push_back(invalidPara);
                    volatilityVals.push_back(invalidPara);
                } else {

                    Para paraReturns, granalityReturns, volatilityReturns;
                    paraReturns.valid = false;
                    granalityReturns.valid = false;
                    volatilityReturns.valid = false;
                    paraReturns.raw = 0.0;
                    granalityReturns.raw = 0.0;
                    volatilityReturns.raw = 0.0;

                    double lastBuy = 0.0;
                    signal lastSignal = SELL;
                    double lastBuyTradeDayOffset;
                    double sumDaysBetweenPairs = 0.0;
                    int numPairs = 0;
                    for (int tradeIndex = 0; tradeIndex < dataSet->tradeDataAvailable(); ++ tradeIndex) {
                        TradeData tDat = dataSet->getData(tradeIndex);

                        //returns calculated in pairs of buy then sell
                        if (tDat.tradeSignal == BUY) {
                            if (lastSignal == SELL)
                                lastBuy = tDat.price;
                            lastBuyTradeDayOffset = tDat.tradeDayOffset;
                        } else {
                            if (lastSignal == BUY) {
                                if (lastBuy > 0.0) {
                                    double ret = (tDat.price - lastBuy) / lastBuy;

                                    volatilityReturns.raw += (ret >= 0.0) ? 1.0 : -1.0;
                                    volatilityReturns.valid = true;

                                    paraReturns.valid = true;
                                    paraReturns.raw += ret; //sum returns of buy/sell pairs

                                    numPairs++;
                                    sumDaysBetweenPairs += tDat.tradeDayOffset - lastBuyTradeDayOffset;
                                } else {
                                    ERR("performParamAnalysis: lastBuy <= 0 error");
                                }
                            }
                        }

                        lastSignal = tDat.tradeSignal;

                    }

                    if (numPairs > 0) {
                        granalityReturns.valid = true;
                        granalityReturns.raw = sumDaysBetweenPairs / (double)numPairs;
                    }

                    returnVals.push_back(paraReturns);
                    granalityVals.push_back(granalityReturns);
                    volatilityVals.push_back(volatilityReturns);
                    analysisDataSetVals.push_back(dataSet);

                }

            }

            pSet.setParam(paraReturns, returnVals);
            pSet.setParam(paraGranality, granalityVals);
            pSet.setParam(paraVolatility, volatilityVals);
            pSet.setAnalysisDataForEachStrat(analysisDataSetVals);

            paramSet.push_back(pSet);
        }
    }

    return paramSet;
}

}

