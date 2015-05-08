//
//  MomentumStrategyData.h
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
//


#ifndef __Algorithmic_Trading__MomentumStrategyData__
#define __Algorithmic_Trading__MomentumStrategyData__

namespace std {
    class MomentumStrategyData;
}

#include "GlobalIncludes.h"


namespace std {
    
    
    class MomentumStrategyData {
        
    public:
        MomentumStrategyData();
        MomentumStrategyData(double threshold, unsigned int returnsInCalculation);
        int previousSignal;
        double previousPriceOnSignal;
        double previousPrice;
        int lastTradeDaysAgo;
        bool lastSignalOdd;
        vector<double> returns;
        vector<double> priceAtReturn;
        bool lastHadMovingAverage;
        double lastMovingAverage;
        double threshold;
        unsigned int returnsInCalculation;
    };
    
}



#endif
