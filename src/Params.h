//
//  Params.h
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//


#ifndef __Algorithmic_Trading__Params__
#define __Algorithmic_Trading__Params__

namespace std {
    class Params;
}

#include "GlobalIncludes.h"

#include <map>


namespace std {
    
    struct Param {
        bool isNull;
        bool isNumber;
        
        string stringVal;
        int intVal;
        double doubleVal;
    };
    
    class Params {
        
    private:
        map<string, Param> params;
        void addParam(string paramId, string paramValue);
        
    public:
        Params(string paramFileDir, bool *foundFile);
        Param getParam(string paramId);
        static Param nullParam();
    };
    
}



#endif 

