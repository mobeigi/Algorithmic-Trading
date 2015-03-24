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
		  //Returns a date as a string in format HH:MM:SS DD:MM:YYYY
          static string datetime() {
          time_t t = time(0);
          struct tm * now = localtime(&t);
          stringstream ss;
		  ss << padDigit(now->tm_hour) << ':';
		  ss << padDigit(now->tm_min) << ':';
		  ss << padDigit(now->tm_sec) << ' ';
		  ss << padDigit(now->tm_mday) << ':';
		  ss << padDigit(now->tm_mon + 1) << ':';
		  ss << now->tm_year + 1900;
          return ss.str();
		}
		
		//Pad digits smaller than 10 with zeros to maintain length of components such as dates
		static inline string padDigit(int number) {
			return ((number < 10) ? ("0" + to_string(number)) : to_string(number));
		}

        static string formatPrice(double price) {
			stringstream ss;
			ss << setprecision(2) << std::fixed << "$" << price;
			return ss.str();
        }
        static string formatDouble(double price) {
			stringstream ss;
			ss << setprecision(4) << std::fixed << price;
			return ss.str();
        }
    };
}

#endif
