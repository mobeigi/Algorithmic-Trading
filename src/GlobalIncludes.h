//
//  GlobalIncludes.h
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//


#ifndef __Algorithmic_Trading__GlobalIncludes__
#define __Algorithmic_Trading__GlobalIncludes__



#include <string>
#include <vector>
#include <stdio.h>

namespace std {
    class Helper {
    public:
        static string formatPrice(double price) {
            char buff[100];
            snprintf(buff, 100, "$%.2f", price);
            string amountStr = string(buff);
            return amountStr;
        }
        static string formatDouble(double price) {
            char buff[100];
            snprintf(buff, 100, "%.4f", price);
            string amountStr = string(buff);
            return amountStr;
        }
    };
}


#endif 

