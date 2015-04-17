//
//  Strategy.h
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
//


#ifndef __Algorithmic_Trading__Strategy__
#define __Algorithmic_Trading__Strategy__

namespace std {
    class Strategy;
}

#include "GlobalIncludes.h"

#include "Logger.h"
#include "StrategyResult.h"
#include "TradeDay.h"


namespace std {
    
    
    class Strategy {
        
    private:
        string dStart, dEnd;
        
    protected:
        Logger &logger;
        
        virtual void nextTradeDay(TradeDay tradeDay, bool enableTrading) = 0; // to be implemented (template)
        
        
    public:
        Strategy(Logger &logger, string startDate, string endDate);
        StrategyResult nextDay(TradeDay tradeDay);
        
    };
    
}



#endif 

