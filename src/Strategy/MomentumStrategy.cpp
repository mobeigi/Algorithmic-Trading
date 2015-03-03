//
//  MomentumStrategy.cpp
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "MomentumStrategy.h"


namespace std {

    MomentumStrategy::MomentumStrategy(Logger &logger, vector<TradeDay> trades) :
    super(logger, trades) {}
    
    StrategyResult MomentumStrategy::execute() {
        
        //setup before main strategy exec
        logger.log("Momentum: Strategy Execute");
        
        return super::execute();
    }
    
    void MomentumStrategy::nextTradeDay(TradeDay tradeDay) {
        logger.log("Momentum: Next Trade Day");
    }
    
    StrategyResult MomentumStrategy::calculateTradingStategy() {
        logger.log("Momentum: Calculate Trading Strategy");
        return StrategyResult::nullResult();
    }

}