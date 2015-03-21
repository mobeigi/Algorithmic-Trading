//
//  Logger.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "Logger.h"

#include <fstream>

#define __CSV_SELL_SIGNAL ((char)0x42)
#define __CSV_BUY_SIGNAL ((char)0x53)

namespace std {

    Logger::Logger() {}

    Logger Logger::standardLogger() {
        return Logger();
    }
    void Logger::addCSVLine(string companyName, string date, double price, bool signal) {
          stringstream ss;
          ss << companyName << __CSV_DELIM;
          ss << date << __CSV_DELIM;
          ss << price << __CSV_DELIM;
          ss << 100 << __CSV_DELIM;
          ss << 100 * price << __CSV_DELIM;
          if(signal) ss << __CSV_SELL_SIGNAL << endl;
          else ss << __CSV_BUY_SIGNAL << endl;
          csvData.push_back(ss.str());
   }

   void Logger::addLogLine() {
         stringstream ss;

   }
   void Logger::writeFile(string filename, vector<string> data) {
         ofstream output = ofstream(filename, ios::trunc);
         if(output.is_open()) {
               for(string line : data) output << line;
         }
         output.close();
   }
    void Logger::log(string msg) {
        cout << msg + "\n";
    }


    void Logger::stopLogger() {
          writeFile("output.csv", csvData);
          writeFile("output.log", logData);
   }

}
