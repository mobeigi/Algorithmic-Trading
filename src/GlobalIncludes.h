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
#define __CSV_BUY_SIGNAL ((char)0x42)
#define __CSV_SELL_SIGNAL ((char)0x53)

#define __LOG_INFO 0
#define __LOG_ERROR 1

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
          static string datetime() {
          time_t t = time(0);
          struct tm * now = localtime(&t);
          stringstream ss;
          ss << (now->tm_hour) << ':';
          ss << (now->tm_min) << ':';
          ss << (now->tm_sec) << ' ';
          ss << (now->tm_mday) << ':';
          ss << (now->tm_mon + 1) << ':';
          ss << (now->tm_year + 1900);
          return ss.str();
    }
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
