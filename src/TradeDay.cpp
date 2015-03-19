//
//  TradeDay.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "TradeDay.h"


namespace std {
    
    TradeDay::TradeDay(double lastPrice, string company) {
        this->lastPrice = lastPrice;
        this->company = company;
    }
    
    double TradeDay::getLastPrice() {
        return lastPrice;
    }
    
    string TradeDay::getCompany() {
        return company;
    }


}