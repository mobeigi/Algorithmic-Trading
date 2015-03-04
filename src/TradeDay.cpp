//
//  TradeDay.cpp
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "TradeDay.h"


namespace std {
    
    TradeDay::TradeDay(double lastPrice) {
        this->lastPrice = lastPrice;
    }
    
    double TradeDay::getLastPrice() {
        return lastPrice;
    }


}