//
//  Logger.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "Logger.h"

namespace std {

    Logger::Logger(string devTeam, string modName, string params) {
          logData.push_back(devTeam);
          logData.push_back(modName);
          logData.push_back(params);

    }
    Logger Logger::standardLogger() {
        return Logger("devTeam", "ModName", "params");
    }
   void Logger::addLogLine(int type, string message) {
         stringstream ss;
         switch(type) {
               case __LOG_INFO:
               ss << "[INFO] ";
               break;
               case __LOG_ERROR:
               ss << "[ERROR] ";
               break;
         }
         ss << Helper::datetime() << ' ';
         ss << message << endl;
         logData.push_back(ss.str());
   }

    void Logger::log(string msg) {
        cout << msg + "\n";
    }
    Logger::~Logger() {
          Helper::writeFile("output.log", logData);
   }

}
