//
//  Logger.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "Logger.h"

#include <fstream>

namespace std {

    Logger::Logger() {
          loggerLock = true;
   }

    void Logger::startLogger() {
          loggerLock = false;
   }
    Logger Logger::standardLogger() {
        return Logger();
    }
    void Logger::addCSVLine(string companyName, string date, double price, bool signal) {
          if(loggerLock == true) return;
          stringstream ss;
          ss << companyName << __CSV_DELIM;
          ss << date << __CSV_DELIM;
          ss << Helper::formatPrice(price) << __CSV_DELIM;
          ss << 100 << __CSV_DELIM;
          ss << Helper::formatPrice(100 * price) << __CSV_DELIM;
          if(signal) ss << 'S' << endl;
          else ss << 'B' << endl;
          csvData.push_back(ss.str());
   }

   void Logger::addLogLine() {
         if(loggerLock == true) return;

   }
   void Logger::writeCSV(string filename) {
         ofstream outputCSV = ofstream(filename, ios::app | ios::trunc);
         if(outputCSV.is_open()) {
               for(string line : csvData) outputCSV << line;
         }
         outputCSV.close();
   }

   void Logger::writeLog(string filename) {
         ofstream outputLog = ofstream(filename, ios::app | ios::trunc);
         if(outputLog.is_open()) {
               for(string line : logData) outputLog << line;
         }
         outputLog.close();
   }
    void Logger::log(string msg) {
        cout << msg + "\n";
    }


    void Logger::stopLogger() {
          loggerLock = true;
          writeCSV("output.csv");
          writeLog("output.log");
   }

}
