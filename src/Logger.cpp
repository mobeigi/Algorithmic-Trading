//
//  Logger.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "Logger.h"
#include "CSVWriter.h"

namespace std {

    Logger::Logger() {
          isLogging = true;
          logData.push_back("Revitpo Version: 1.00\n");
          logData.push_back("Developed By: Samuel Whitton, Mohammad Ghasembegi, Ian Wong, Jason Ng and Antheny Yu\n");

   }
    // Logger Logger::standardLogger() {
    //     return Logger("devTeam", "ModName", "params");
    // }
   void Logger::log(int type, string message) {
         if(isLogging) {
               stringstream ss;
               switch(type) {
                     case __LOG_INFO:
                     ss << "[INFO] ";
                     break;
                     case __LOG_ERROR:
                     ss << "[ERROR] ";
                     break;
                     case __LOG_DEBUG:
                     ss << "[DEBUG] ";
                     break;
               }
               ss << Helper::datetime() << ' ';
               ss << message << endl;
               logData.push_back(ss.str());
         }
   }

    // void Logger::log(string msg) {
    //     cout << msg + "\n";
    // }


    void Logger::stopLogging() {
         isLogging  = false;
         Helper::writeFile("output.log", logData);
   }

}
