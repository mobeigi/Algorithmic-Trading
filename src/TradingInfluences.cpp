//
//  TradingInfluences.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
//

#include "TradingInfluences.h"


namespace std {
    
    TradingInfluences::TradingInfluences() {
        
    }
    
    //-1.0 (most sell influence) to 1.0 (most buy influence)
    double TradingInfluences::tradeDayInfluence(TradeDay tradeDay) {
        return 0.0; //default no influence
    }
    
    
}
