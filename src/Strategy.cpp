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
    
    
    
    StrategyResult Strategy::nextDay(TradeDay tradeDay) {
        nextTradeDay(tradeDay);
        return StrategyResult::nullResult();
    }
    
    
}



