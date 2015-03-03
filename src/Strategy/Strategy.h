//
//  Strategy.h
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
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
        
    protected:
        Logger &logger;
        vector<TradeDay> trades;
        
        virtual void nextTradeDay(TradeDay tradeDay) = 0; // to be implemented (template)
        virtual StrategyResult calculateTradingStategy() = 0; // to be implemented (template)
        

    public:
        Strategy(Logger &logger, vector<TradeDay> trades);
        virtual StrategyResult execute();

    };
    
}



#endif 

