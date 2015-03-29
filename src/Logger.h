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

namespace std {


    class Logger {

    private:
        CSVWriter * csv;
        map<string, CSVWriter> csvData;
        bool isLogging, isCSV;
        ofstream output;

    public:
        void stopLogging();
        void log(int type, string message);
        void startCSV(string dataFile);
        void stopCSV();
        void writeToCSV(string companyName, string date, double price, char signal);
        Logger(string dataFile);
    };

}



#endif
