//
//  MomentumStrategy.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
//

#include "MomentumStrategy.h"


namespace std {
    
  MomentumStrategy::MomentumStrategy(Logger &logger, unsigned int returnsInCalculation, double threshold) :
    super(logger), companyData() {
        this->returnsInCalculation = returnsInCalculation;
        this->threshold = threshold;
    }
    
    
    void MomentumStrategy::nextTradeDay(TradeDay tradeDay) {
        
        if (companyData.find(tradeDay.getCompany()) == companyData.end()) {
            companyData[tradeDay.getCompany()] = MomentumStrategyData();
        }
        MomentumStrategyData *data = &companyData[tradeDay.getCompany()];
        double thisPrice = tradeDay.getLastPrice();
        logger.logDebug("");
        double Rt = 0.0;
        
        //return calculation
        if (data->previousPrice == 0.0) {
            logger.logDebug("Rt: 0.0");
        } else {
            Rt = (thisPrice - data->previousPrice) / data->previousPrice;
            logger.logDebug("Rt: " + Helper::formatDouble(Rt));
        }
        
        data->returns.push_back(Rt);
        
        //SMA calculation
        if (data->returns.size() < returnsInCalculation) {
            logger.logDebug("SMAt: 0.0");
        } else {
            //enough returns to start calculating moving average
            double sumRt = 0.0;
            for (unsigned long i = data->returns.size() - returnsInCalculation; i < data->returns.size(); i++) {
                sumRt += data->returns[i];
            }
            double SMAt = sumRt / returnsInCalculation;
            logger.logDebug("SMAt: " + Helper::formatDouble(SMAt));
            
            if (data->lastHadMovingAverage) {
                double diff = SMAt - data->lastMovingAverage;
                if (diff > threshold) {
                    logger.logDebug("Buy Signal");
                    if(data->previousSignal != __BUY_SIGNAL) {
                        data->previousSignal = __BUY_SIGNAL;
                        logger.writeToCSV(tradeDay.getCompany(), tradeDay.getDate(), tradeDay.getLastPrice(), __BUY_SIGNAL);
                    } else logger.logDebug("Ignored Signal");
                } else if (diff < -threshold) {
                    logger.logDebug("Sell Signal");
                    if(data->previousSignal != __SELL_SIGNAL) {
                        data->previousSignal = __SELL_SIGNAL;
                        logger.writeToCSV(tradeDay.getCompany(), tradeDay.getDate(), tradeDay.getLastPrice(), __SELL_SIGNAL);
                    } else logger.logDebug("Ignored Signal");
                    
                } else {
                    
                }
            }
            
            data->lastHadMovingAverage = true;
            data->lastMovingAverage = SMAt;
        }
        
        
        data->previousPrice = thisPrice;
    }
    
    
}
