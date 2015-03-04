//
//  TradeDay.h
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//


#ifndef __Algorithmic_Trading__TradeDay__
#define __Algorithmic_Trading__TradeDay__

namespace std {
    class TradeDay;
}

#include "GlobalIncludes.h"


namespace std {
    
    
    class TradeDay {
        
    private:
        double lastPrice;

    public:
        TradeDay(double lastPrice);
        double getLastPrice();

    };
    
}



#endif 

