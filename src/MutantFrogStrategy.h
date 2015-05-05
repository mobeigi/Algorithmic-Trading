//
//  MutantFrogStrategy.h
//  Algorithmic Trading SENG3011
//
//  Created on 05/05/15.
//  Copyright (c) Trock. All rights reserved.
//


#ifndef __Algorithmic_Trading__MutantFrogStrategy__
#define __Algorithmic_Trading__MutantFrogStrategy__

namespace std {
    class MutantFrogStrategy;
}

#include "GlobalIncludes.h"

#include "MomentumStrategy.h"
#include "TradingInfluences.h"


namespace std {
    
    
    class MutantFrogStrategy : public MomentumStrategy {
        
    private:
        typedef MomentumStrategy super;
        
        TradingInfluences influences;
        
    protected:
        virtual void nextTradeDay(TradeDay tradeDay, bool enableTrading);
        
    public:
      MutantFrogStrategy(Logger &logger, string startDate, string endDate);
        
    };
    
}



#endif

