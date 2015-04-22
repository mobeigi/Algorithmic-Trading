//
//  GlobalIncludes.h
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
//

#ifndef __Algorithmic_Trading__GlobalIncludes__
#define __Algorithmic_Trading__GlobalIncludes__

// define DEBUG for debugging (remove for production releases)
#define DEBUG 0

#define __PRODUCT_RELEASE_VERSION "1.10"

#define __CSV_DELIM ((char)0x2c)

#define __BUY_SIGNAL ((char)0x42)
#define __SELL_SIGNAL ((char)0x53)

#define __LOG_INFO 0
#define __LOG_ERROR 1
#define __LOG_DEBUG 2
#define __LOG_FATAL 3

#include <string>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cmath>


#ifdef _WIN32 //windows 32 and 64bit
#include <Windows.h>
#else

#ifdef __MACH__ //OS X
#include <mach/clock.h>
#include <mach/mach.h>

#else //linux/unix
#include <time.h>
#include <sys/time.h>
#endif

#endif

namespace std {
    
    struct Date {
        int day;
        int month;
        int year;
    };
    
    enum DateComparisonResult {
        dateSame,
        dateBefore,
        dateAfter,
        dateError
    };
    
    class Helper {
    public:
        
        
        
        static Date parseDate(string dateStr) {
            
            Date date;
            date.day = -1;
            date.month = -1;
            date.year = -1;
            
            if (dateStr.size() == 11) {
                
                date.day = stoi(dateStr.substr(0,2).c_str());
                date.year = stoi(dateStr.substr(7,4).c_str());
                
                string strMonth = dateStr.substr(3, 3);
                if (strMonth.compare("JAN") == 0)
                    date.month = 1;
                else if (strMonth.compare("FEB") == 0)
                    date.month = 2;
                else if (strMonth.compare("MAR") == 0)
                    date.month = 3;
                else if (strMonth.compare("APR") == 0)
                    date.month = 4;
                else if (strMonth.compare("MAY") == 0)
                    date.month = 5;
                else if (strMonth.compare("JUN") == 0)
                    date.month = 6;
                else if (strMonth.compare("JUL") == 0)
                    date.month = 7;
                else if (strMonth.compare("AUG") == 0)
                    date.month = 8;
                else if (strMonth.compare("SEP") == 0)
                    date.month = 9;
                else if (strMonth.compare("OCT") == 0)
                    date.month = 10;
                else if (strMonth.compare("NOV") == 0)
                    date.month = 11;
                else if (strMonth.compare("DEC") == 0)
                    date.month = 12;
            }
            
            return date;
        }
        
        static DateComparisonResult compareDates(string dateRef, string dateComp) {
            
            Date ref = Helper::parseDate(dateRef);
            Date comp = Helper::parseDate(dateComp);
            
            if (comp.day == -1 || ref.day == -1 || comp.month == -1 || ref.month == -1 || comp.year == -1 || ref.year == -1) {
                return dateError; //error, date parse failed
            }
            
            if (comp.year == ref.year && comp.month == ref.month == comp.month && ref.day == comp.day)
                return dateSame;
            
            if (comp.year < ref.year || (comp.year == ref.year && (comp.month < ref.month || (comp.month == ref.month && comp.day < ref.day)) ) ) {
                return dateBefore;
            }
            
            return dateAfter;
        }
        
        static int daysInMonth(int month, int year) {
            month--; //change from 1-12 to 0-11
            int numberOfDays;
            if (month == 4 || month == 6 || month == 9 || month == 11) {
                numberOfDays = 30;
            } else if (month == 2) {
                bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
                if (isLeapYear)
                    numberOfDays = 29;
                else
                    numberOfDays = 28;
            } else {
                numberOfDays = 31;
            }
            return numberOfDays;
        }
        
        //Returns a date as a string in format HH:MM:SS DD:MM:YYYY
        static string datetime() {
            time_t t = time(0);
            struct tm * now = localtime(&t);
            stringstream ss;
            ss << padDigit(now->tm_hour) << ':';
            ss << padDigit(now->tm_min) << ':';
            ss << padDigit(now->tm_sec) << ' ';
            ss << padDigit(now->tm_mday) << '/';
            ss << padDigit(now->tm_mon + 1) << '/';
            ss << now->tm_year + 1900;
            return ss.str();
        }
        
        //Pad digits smaller than 10 with zeros to maintain length of components such as dates
        static inline string padDigit(int number) {
            return ((number < 10) ? ("0" + to_string(number)) : to_string(number));
        }
        
        static string formatPrice(double price) {
            stringstream ss;
            ss << setprecision(2) << std::fixed << ((price < 0) ? "-$" : "$") << abs(price);
            return ss.str();
        }
        static string formatDouble(double price) {
            stringstream ss;
            ss << setprecision(4) << std::fixed << price;
            return ss.str();
        }
        
        static unsigned long sysTimeUS() {
            
            
#ifdef _WIN32 //windows 32 and 64bit
            SYSTEMTIME st;
            GetSystemTime(&st);
            return (unsigned long)(st.wMilliseconds + (st.wSecond * 1000));
#else
            
#ifdef __MACH__ //OS X
            struct timespec ts;
            clock_serv_t cclock;
            mach_timespec_t mts;
            host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
            clock_get_time(cclock, &mts);
            mach_port_deallocate(mach_task_self(), cclock);
            ts.tv_sec = mts.tv_sec;
            ts.tv_nsec = mts.tv_nsec;
            return (unsigned long)(ts.tv_nsec + ts.tv_sec*1000000000L) / 1000;
            
#else //linux/unix
            struct timespec ts;
            clock_gettime(CLOCK_REALTIME, &ts);
            return (unsigned long)(ts.tv_nsec + ts.tv_sec*1000000000L) / 1000;
#endif
            
#endif
            
        }
    };
}

#endif



