//
//  MutantFrogStrategy.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
//

#include "MutantFrogStrategy.h"


#define INITIAL_RETURNS_IN_CALCULATION 3
#define INITIAL_THRESHOLD 0.001

namespace std {
    
    MutantFrogStrategy::MutantFrogStrategy(Logger &logger, string startDate, string endDate) :
    super(logger, startDate, endDate, INITIAL_RETURNS_IN_CALCULATION, INITIAL_THRESHOLD), influences() {}
    
    void MutantFrogStrategy::nextTradeDay(TradeDay tradeDay, bool enableTrading) {
        
        //biased based on threshold and influences
        double threshBias = super::threshold * influences.tradeDayInfluence(tradeDay);
        super::nextTradeDay(tradeDay, enableTrading, threshBias);
    }
    
    
}
