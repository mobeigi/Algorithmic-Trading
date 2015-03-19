//
//  Strategy.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "Strategy.h"


namespace std {

    Strategy::Strategy(Logger &logger) :
    logger(logger) {}
    
    /*StrategyResult Strategy::execute() {
        //things to do for every strategy
        
        logger.log("Base: Strategy Execute");
        
        for (TradeDay tradeDay : trades) {
            nextTradeDay(tradeDay);
        }
        
        return calculateTradingStategy();

    }*/
    
    
    StrategyResult Strategy::nextDay(TradeDay tradeDay) {
        nextTradeDay(tradeDay);
        return StrategyResult::nullResult();
    }


}



