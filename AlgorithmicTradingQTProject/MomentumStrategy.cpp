//
//  MomentumStrategy.cpp
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "MomentumStrategy.h"


namespace std {

    MomentumStrategy::MomentumStrategy(Logger &logger, int returnsInCalculation, double threshold) :
    super(logger) {
        this->returnsInCalculation = returnsInCalculation;
        this->threshold = threshold;
        this->lastHadMovingAverage = false;
        previousPrice = 0.0;
        returns = vector<double>();
    }
    
    
    /*StrategyResult MomentumStrategy::execute() {
        //setup before main strategy exec
        previousPrice = 0.0;
        returns = vector<double>();
        
        return super::execute();
    }*/
    
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
        if (static_cast<int>(returns.size()) < returnsInCalculation) {
            logger.log("SMAt: ");
        } else {
            //enough returns to start calculating moving average
            double sumRt = 0.0;
            for (long i = returns.size() - returnsInCalculation; i < static_cast<long>(returns.size()); i++) {
                sumRt += returns[i];
            }
            double SMAt = sumRt / returnsInCalculation;
            logger.log("SMAt: " + Helper::formatDouble(SMAt));
            
            if (lastHadMovingAverage) {
                double diff = SMAt - lastMovingAverage;
                if (diff > threshold) {
                    logger.log("Buy Signal");
                } else if (diff < -threshold) {
                    logger.log("Sell Signal");
                } else {
                    
                }
            }
            
            lastHadMovingAverage = true;
            lastMovingAverage = SMAt;
        }
        
        
        previousPrice = thisPrice;
    }
    

}



