//
//  MomentumStrategy.cpp
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "MomentumStrategy.h"


namespace std {

    MomentumStrategy::MomentumStrategy(Logger &logger, vector<TradeDay> trades, int returnsInCalculation) :
    super(logger, trades) {
        this->returnsInCalculation = returnsInCalculation;
    }
    
    StrategyResult MomentumStrategy::execute() {
        //setup before main strategy exec
        previousPrice = 0.0;
        returns = vector<double>();
        
        return super::execute();
    }
    
    void MomentumStrategy::nextTradeDay(TradeDay tradeDay) {
        double thisPrice = tradeDay.getLastPrice();
        
        logger.log("");
        double Rt = 0.0;
        
        //return calculation
        if (previousPrice == 0.0) {
            logger.log("Rt: ");
        } else {
            Rt = (thisPrice - previousPrice) / previousPrice;
            logger.log("Rt: " + Helper::formatDouble(Rt));
        }
        
        returns.push_back(Rt);
        
        //SMA calculation
        if (returns.size() < returnsInCalculation) {
            logger.log("SMAt: ");
        } else {
            //enough returns to start calculating moving average
            double sumRt = 0.0;
            for (long i = returns.size() - returnsInCalculation; i < returns.size(); i++) {
                sumRt += returns[i];
            }
            double SMAt = sumRt / returnsInCalculation;
            logger.log("SMAt: " + Helper::formatDouble(SMAt));
        }
        
        
        previousPrice = thisPrice;
    }
    
    StrategyResult MomentumStrategy::calculateTradingStategy() {
        logger.log("Momentum: Calculate Trading Strategy");
        return StrategyResult::nullResult();
    }

}



