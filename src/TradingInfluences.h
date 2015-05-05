//
//  TradingInfluences.h
//  Algorithmic Trading SENG3011
//
//  Created on 05/05/15.
//  Copyright (c) Trock. All rights reserved.
//


#ifndef __Algorithmic_Trading__TradingInfluences__
#define __Algorithmic_Trading__TradingInfluences__

namespace std {
    class TradingInfluences;
}

#include "GlobalIncludes.h"

#include "TradeDay.h"


namespace std {
    
    
    class TradingInfluences {
        
    public:
        TradingInfluences();
        
        //-1.0 (most sell influence) to 1.0 (most buy influence)
        double tradeDayInfluence(TradeDay tradeDay);
        
    };
    
}



#endif

