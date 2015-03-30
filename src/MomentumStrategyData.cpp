//
//  MomentumStrategyData.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "MomentumStrategyData.h"


namespace std {

    MomentumStrategyData::MomentumStrategyData() {
        this->lastHadMovingAverage = false;
        previousSignal = -1;
        previousPrice = 0.0;
        returns = vector<double>();
    }

}
