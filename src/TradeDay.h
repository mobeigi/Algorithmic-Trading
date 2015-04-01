//
//  TradeDay.h
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
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
        double openPrice;
        double highPrice;
        double lowPrice;
        string company;
        string date;
        
    public:
        TradeDay(double openPrice, double highPrice, double lowPrice, double lastPrice, string company, string date);
        double getLastPrice();
        double getLowPrice();
        double getHighPrice();
        double getOpenPrice();
        string getDate();
        string getCompany();
        
    };
    
}



#endif
