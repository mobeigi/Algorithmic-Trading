//
//  MomentumStrategyData.h
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
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
       int previousSignal;
        double previousPrice;
        vector<double> returns;
        bool lastHadMovingAverage;
        double lastMovingAverage;

    };

}



#endif
