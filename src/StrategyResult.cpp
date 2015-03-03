//
//  StrategyResult.cpp
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "StrategyResult.h"


namespace std {

    StrategyResult::StrategyResult() {
        isNullResult = true;
    }
    
    StrategyResult StrategyResult::nullResult() {
        return StrategyResult::StrategyResult();
    }
    
    bool StrategyResult::isNull() {
        return isNullResult;
    }

}