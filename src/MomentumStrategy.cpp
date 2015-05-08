//
//  MomentumStrategy.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
//

#include "MomentumStrategy.h"


namespace std {
    
  MomentumStrategy::MomentumStrategy(Logger &logger, string startDate, string endDate, unsigned int returnsInCalculation, double threshold) :
    super(logger, startDate, endDate), companyData() {
        this->defReturnsInCalculation = returnsInCalculation;
        this->defThreshold = threshold;
    }
    
    MomentumStrategyData *MomentumStrategy::dataForTradeDay(TradeDay tradeDay) {
        if (companyData.find(tradeDay.getCompany()) == companyData.end()) {
            companyData[tradeDay.getCompany()] = MomentumStrategyData(defThreshold, defReturnsInCalculation);
        }
        MomentumStrategyData *data = &companyData[tradeDay.getCompany()];
        return data;
    }
    
    int MomentumStrategy::nextTradeDay(TradeDay tradeDay, bool enableBuyTrades, bool enableSellTrades, double thresholdBias, int forcedSignal) {
        
        int signalSignaled = -1;
        
        if (companyData.find(tradeDay.getCompany()) == companyData.end()) {
            companyData[tradeDay.getCompany()] = MomentumStrategyData(defThreshold, defReturnsInCalculation);
        }
        MomentumStrategyData *data = &companyData[tradeDay.getCompany()];
        double thisPrice = tradeDay.getLastPrice();
        data->lastTradeDaysAgo++;
        logger.logDebug("");
        double Rt = 0.0;
        
        //return calculation
        if (data->previousPrice == 0.0) {
            logger.logDebug("Rt: 0.0");
        } else {
            Rt = (thisPrice - data->previousPrice) / data->previousPrice;
            logger.logDebug("Rt: " + Helper::formatDouble(Rt));
            data->returns.push_back(Rt);
            data->priceAtReturn.push_back(thisPrice);
        }
        
        //SMA calculation
        if (data->returns.size() < data->returnsInCalculation) {
            logger.logDebug("SMAt: 0.0");
        } else {
            //enough returns to start calculating moving average
            double sumRt = 0.0;
            for (unsigned long i = data->returns.size() - data->returnsInCalculation; i < data->returns.size(); i++) {
                sumRt += data->returns[i];
            }
            double SMAt = sumRt / data->returnsInCalculation;
            logger.logDebug("SMAt: " + Helper::formatDouble(SMAt));
            
            if (data->lastHadMovingAverage) {
                double diff = SMAt - data->lastMovingAverage + thresholdBias;
                
                bool enableTrading = enableBuyTrades || enableSellTrades;
                if (enableTrading) {
                    
                    if ((diff > data->threshold || forcedSignal == __BUY_SIGNAL) && enableBuyTrades) {
                        logger.logDebug("Buy Signal");
                        if(data->previousSignal != __BUY_SIGNAL) {
                            signalSignaled = __BUY_SIGNAL;
                            data->previousPriceOnSignal = thisPrice;
                            data->lastSignalOdd = !data->lastSignalOdd;
                            data->lastTradeDaysAgo = 0;
                            data->previousSignal = __BUY_SIGNAL;
                            logger.writeToCSV(tradeDay.getCompany(), tradeDay.getDate(), tradeDay.getLastPrice(), __BUY_SIGNAL);
                        } else logger.logDebug("Ignored Signal");
                    } else if ((diff < -data->threshold || forcedSignal == __SELL_SIGNAL) && enableSellTrades) {
                        logger.logDebug("Sell Signal");
                        if(data->previousSignal != __SELL_SIGNAL) {
                            signalSignaled = __SELL_SIGNAL;
                            data->previousPriceOnSignal = thisPrice;
                            data->lastSignalOdd = !data->lastSignalOdd;
                            data->lastTradeDaysAgo = 0;
                            data->previousSignal = __SELL_SIGNAL;
                            logger.writeToCSV(tradeDay.getCompany(), tradeDay.getDate(), tradeDay.getLastPrice(), __SELL_SIGNAL);
                        } else logger.logDebug("Ignored Signal");
                        
                    } else {
                        logger.logDebug("Ignored Signal");
                    }
                    
                }
            }
            
            data->lastHadMovingAverage = true;
            data->lastMovingAverage = SMAt;
        }
        
        
        data->previousPrice = thisPrice;
        
        return signalSignaled;
    }
    
    void MomentumStrategy::nextTradeDay(TradeDay tradeDay, bool enableTrading) {
        nextTradeDay(tradeDay, enableTrading, enableTrading, 0.0, -1);
    }
    
    
}


