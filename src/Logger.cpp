//
//  Logger.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "Logger.h"


namespace std {
    
	Logger::Logger(string logFile, string csvFile, bool debug) {
        
        this->logFile = nullptr;
        this->csvFile = nullptr;
        this->debug = debug;
        
        this->logFile = new ofstream(logFile, ios::trunc);
        this->csvFile = new CSVWriter(csvFile);
        
        if (!this->logFile->is_open()) {
            logError("Unable to write to log file: " + logFile, false);
        }
        
        if (!this->csvFile->open()) {
            logError("Unable to write to csv file: " + csvFile, false);
        }

	}
    
    Logger::~Logger() {
        stopLogging();
    }
    
    
    
    void Logger::logDebug(string log) {
        if (debug) {
            cout << "[DEBUG] " + log;
        }
    }
    
    void Logger::logError(string errorDescr, bool fatal) {
        if (fatal) {
            cout << "[FATAL ERROR] " + errorDescr;
            exit(1);
        }
        cout << "[ERROR] " + errorDescr;
    }
    
    void Logger::log(string log) {
        
        if (logFile != nullptr && logFile->is_open()) {
            stringstream ss;
            ss << log;
            *logFile << log << endl;
        }
    }
    
	void Logger::writeToCSV(string companyName, string date, double price, char signal) {
        
        if (csvFile != nullptr && csvFile->open()) {
            csvFile->addCSVLine(companyName, date, price, signal);
        }
	}
    
    
	void Logger::stopLogging() {
        
        if (logFile != nullptr) {
            log("Ended Execution: " + Helper::datetime());
            log("Elapsed Time: ");
            
            if (logFile->is_open()) logFile->close();
            delete logFile;
            logFile = nullptr;
        }
        
        if (csvFile != nullptr) {
            if (csvFile->open()) csvFile->stopWriting();
            delete csvFile;
            csvFile = nullptr;
        }
        
	}

}




