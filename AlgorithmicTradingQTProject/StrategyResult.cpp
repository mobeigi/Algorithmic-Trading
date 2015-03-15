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
        transferAmount = 0.0;
        type = ResultType::Nothing;
    }
    
    StrategyResult::StrategyResult(ResultType type, double equityTransfer) {
        isNullResult = false;
        transferAmount = equityTransfer;
        this->type = type;
    }
    
    StrategyResult StrategyResult::nullResult() {
        return StrategyResult();
    }
    
    /*StrategyResult StrategyResult::buyEquity() {
        return StrategyResult(ResultType::Buy, 0);
    }
    StrategyResult StrategyResult::sellEquity() {
        return StrategyResult(ResultType::Sell, 0);
    }
    StrategyResult StrategyResult::buyEquity(double amount) {
        if (amount == 0.0)
            return doNothing();
        return StrategyResult(ResultType::Buy, amount);
    }
    StrategyResult StrategyResult::sellEquity(double amount) {
        if (amount == 0.0)
            return doNothing();
        return StrategyResult(ResultType::Sell, amount);
    }
    StrategyResult StrategyResult::doNothing() {
        return StrategyResult(ResultType::Nothing, 0);
    }*/
    
    bool StrategyResult::isNull() {
        return isNullResult;
    }
    
    string StrategyResult::description() {
        if (isNull())
            return "NULL";
        if (type == Nothing)
            return "Dont buy or sell";
        string actDescr = "Sell";
        if (type == Buy)
            actDescr = "Buy";
        
        if (transferAmount != 0.0) {
            return actDescr + " " + Helper::formatPrice(transferAmount) + " of equity";
        }
        return actDescr + " equity";
    }

}


