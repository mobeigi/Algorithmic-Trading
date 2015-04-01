//
//  TradeDay.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "TradeDay.h"


namespace std {
    
    TradeDay::TradeDay(double openPrice, double highPrice, double lowPrice, double lastPrice, string company, string date) {
        this->openPrice = openPrice;
        this->highPrice = highPrice;
        this->lowPrice = lowPrice;
        this->lastPrice = lastPrice;
        this->company = company;
        this->date = date;
    }
    
    double TradeDay::getOpenPrice() {
        return openPrice;
    }
    
    double TradeDay::getHighPrice() {
        return highPrice;
    }
    
    double TradeDay::getLowPrice() {
        return lowPrice;
    }
    
    double TradeDay::getLastPrice() {
        return lastPrice;
    }
    
    string TradeDay::getDate() {
        return date;
    }
    string TradeDay::getCompany() {
        return company;
    }
    
    
}
