//
//  StrategyResult.h
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//


#ifndef __Algorithmic_Trading__StrategyResult__
#define __Algorithmic_Trading__StrategyResult__

namespace std {
    class StrategyResult;
}

#include "GlobalIncludes.h"



namespace std {
    
    typedef enum : int {
        Buy,
        Sell,
        Nothing
    } ResultType;
    
    class StrategyResult {
        
    private:
        StrategyResult();
        StrategyResult(ResultType type, double equityTransfer);
        
        bool isNullResult;
        
        ResultType type;
        double transferAmount;
        
    public:
        
        static StrategyResult nullResult();
        
        static StrategyResult buyEquity();
        static StrategyResult sellEquity();
        static StrategyResult buyEquity(double amount);
        static StrategyResult sellEquity(double amount);
        static StrategyResult doNothing();
        
        bool isNull();
        string description();
        
    };
    
}



#endif 

