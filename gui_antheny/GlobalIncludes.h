//
//  GlobalIncludes.h
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//


#ifndef __Algorithmic_Trading__GlobalIncludes__
#define __Algorithmic_Trading__GlobalIncludes__

#define ERR_FATAL(info) printf(info);exit(1)
#define ERR(info) printf(info)


#include <string>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <algorithm>

namespace std {

struct Date {
    int day;
    int month;
    int year;
};

    class Helper {
    public:

        //trtim functions from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
        //self explainitory

        // trim from start
        static inline std::string &ltrim(std::string &s) {
                s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
                return s;
        }

        // trim from end
        static inline std::string &rtrim(std::string &s) {
                s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
                return s;
        }

        // trim from both ends
        static inline std::string &trim(std::string &s) {
                return ltrim(rtrim(s));
        }

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

        static Date addDays(Date date, int days) {
            //hopefull we are not adding many days...
            for (int i = 0; i != days; ++i) {
                date.day++;
                if (date.day > Helper::daysInMonth(date.month, date.year)) {
                    date.day = 1;
                    date.month++;
                    if (date.month > 12) {
                        date.month = 1;
                        date.year++;
                    }
                }
            }
            return date;
        }

        static string dateString(Date date) {
            string date_str;

            //construct the day
            if (date.day < 10) {
                date_str.append("0" + to_string(date.day));
            } else {
                date_str.append(to_string(date.day));
            }
            date_str.append("-");

            //construct the month
            switch (date.month) {
                case 1: date_str.append("JAN"); break;
                case 2: date_str.append("FEB"); break;
                case 3: date_str.append("MAR"); break;
                case 4: date_str.append("APR"); break;
                case 5: date_str.append("MAY"); break;
                case 6: date_str.append("JUN"); break;
                case 7: date_str.append("JUL"); break;
                case 8: date_str.append("AUG"); break;
                case 9: date_str.append("SEP"); break;
                case 10: date_str.append("OCT"); break;
                case 11: date_str.append("NOV"); break;
                case 12: date_str.append("DEC"); break;
            }
            date_str.append("-");

            //construct the year
            date_str.append(to_string(date.year));

            return date_str;
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

