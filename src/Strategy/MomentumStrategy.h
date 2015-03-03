//
//  MomentumStrategy.h
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//


#ifndef __Algorithmic_Trading__MomentumStrategy__
#define __Algorithmic_Trading__MomentumStrategy__

namespace std {
    class MomentumStrategy;
}

#include "GlobalIncludes.h"

#include "Strategy.h"


namespace std {
    
    
    class MomentumStrategy : public Strategy {
        
    private:
        typedef Strategy super;
        
    protected:
        virtual void nextTradeDay(TradeDay tradeDay);
        virtual StrategyResult calculateTradingStategy();

    public:
        MomentumStrategy(Logger &logger, vector<TradeDay> trades);
        virtual StrategyResult execute();

    };
    
}



#endif 
