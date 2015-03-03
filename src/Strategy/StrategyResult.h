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
    
    class StrategyResult {
        
    private:
        StrategyResult();
        
        bool isNullResult;

    public:
        
        static StrategyResult nullResult();
        
        bool isNull();
        
    };
    
}



#endif 

