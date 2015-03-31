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
#include "CSVWriter.h"
#include <map>
#include <iostream>

namespace std {


    class Logger {

    private:
        CSVWriter *csvFile;
        ofstream *logFile;
        bool debug;
        
        unsigned long startTimeEpoch;
        //map<string, CSVWriter> csvData;
        //bool isLogging, isCSV;
        //ofstream output;
    public:
        Logger(string logFile, string csvFile, bool debug, string paramsDescr, string inputFileName);
        ~Logger();
        
        void stopLogging();
        
        void logDebug(string log);
        void logError(string errorDescr, bool fatal);
        
        void log(string log);
        void writeToCSV(string companyName, string date, double price, char signal);
        
        //void log(int type, string message);
        
    };

}



#endif
