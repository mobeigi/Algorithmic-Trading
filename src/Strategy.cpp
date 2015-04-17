//
//  Strategy.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
//

#include "Strategy.h"


namespace std {
    
    Strategy::Strategy(Logger &logger, string startDate, string endDate) :
    logger(logger), dStart(startDate), dEnd(endDate) {}
    
    
    
    StrategyResult Strategy::nextDay(TradeDay tradeDay) {
        
        bool shouldTrade = true;
        
        DateComparisonResult compareStart = Helper::compareDates(dStart, tradeDay.getDate());
        DateComparisonResult compareEnd = Helper::compareDates(dEnd, tradeDay.getDate());
        
        if (compareStart == dateBefore || compareEnd == dateAfter) {
            shouldTrade = false;
        }
        
        //just incase, trade always
        if (dStart.compare("") == 0 || dEnd.compare("") == 0
            || tradeDay.getDate().compare("") == 0)
            shouldTrade = true;
        
        nextTradeDay(tradeDay, shouldTrade);
        return StrategyResult::nullResult();
    }
    
    
}



