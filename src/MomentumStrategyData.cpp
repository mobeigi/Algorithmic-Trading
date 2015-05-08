//
//  MomentumStrategyData.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
//

#include "MomentumStrategyData.h"


namespace std {
    
    MomentumStrategyData::MomentumStrategyData() : MomentumStrategyData(0.0, 0) {}
    
    MomentumStrategyData::MomentumStrategyData(double threshold, unsigned int returnsInCalculation) {
        this->lastHadMovingAverage = false;
        previousSignal = -1;
        previousPriceOnSignal = 0.0;
        lastSignalOdd = false;
        lastTradeDaysAgo = 0;
        previousPrice = 0.0;
        returns = vector<double>();
        priceAtReturn = vector<double>();
        this->threshold = threshold;
        this->returnsInCalculation = returnsInCalculation;
    }
    
}
