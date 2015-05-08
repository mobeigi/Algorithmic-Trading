//
//  MomentumStrategy.h
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
//


#ifndef __Algorithmic_Trading__MomentumStrategy__
#define __Algorithmic_Trading__MomentumStrategy__

namespace std {
    class MomentumStrategy;
}

#include "GlobalIncludes.h"

#include <map>

#include "Strategy.h"
#include "MomentumStrategyData.h"


namespace std {
    
    
    class MomentumStrategy : public Strategy {
        
    private:
        typedef Strategy super;
        
        map<string, MomentumStrategyData> companyData;
        
        double defThreshold;
        unsigned int defReturnsInCalculation; //number of returns to use in equation (n from spec)
        
    protected:
        //if forced signal != buy of sell, then ignore
        int nextTradeDay(TradeDay tradeDay, bool enableBuyTrades, bool enableSellTrades, double thresholdBias, int forcedSignal); //returns signal
        virtual void nextTradeDay(TradeDay tradeDay, bool enableTrading);
        
        //call has no effect on this object, also treat data as read only!
        //also this is a valid pointer until ANY mutating call to this object is made
        MomentumStrategyData *dataForTradeDay(TradeDay tradeDay);
        
        
        
    public:
      MomentumStrategy(Logger &logger, string startDate, string endDate, unsigned int returnsInCalculation, double threshold);
        
    };
    
}



#endif

