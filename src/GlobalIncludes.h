//
//  GlobalIncludes.h
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//


#ifndef __Algorithmic_Trading__GlobalIncludes__
#define __Algorithmic_Trading__GlobalIncludes__

#define __CSV_DELIM ((char)0x2c)

#include <string>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cmath>

namespace std {
    class Helper {
    public:
        static string formatPrice(double price) {
			stringstream ss;
			ss << setprecision(2) << std::fixed << "$" << price;
			return ss.str();
        }
        static string formatDouble(double price) {
			stringstream ss;
			ss << setprecision(4) << std::fixed << "" << price;
			return ss.str();
        }
    };
}

#endif
