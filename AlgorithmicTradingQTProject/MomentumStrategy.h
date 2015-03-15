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
        
        int returnsInCalculation; //number of returns to use in equation (n from spec)
        double previousPrice;
        vector<double> returns;
        double threshold;
        bool lastHadMovingAverage;
        double lastMovingAverage;
        
    protected:
        virtual void nextTradeDay(TradeDay tradeDay);

    public:
        MomentumStrategy(Logger &logger, int returnsInCalculation, double threshold);
        
    };
    
}



#endif 

