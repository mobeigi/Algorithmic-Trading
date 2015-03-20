//
//  Logger.h
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//


#ifndef __Algorithmic_Trading__Logger__
#define __Algorithmic_Trading__Logger__


namespace std {
    class Logger;
}

#include "GlobalIncludes.h"

#include <iostream>


namespace std {


    class Logger {

    private:
        Logger();
        void writeCSV(string filename);
        void writeLog(string filename);
        bool loggerLock;
        vector<string> csvData;
        vector<string> logData;
    public:
        static Logger standardLogger();
        // signal (bool) true if B and false if S
        void addCSVLine(string companyName, string date, double price, bool signal);
        void addLogLine();
        void startLogger();
        void stopLogger();

        void log(string msg);
    };

}



#endif
