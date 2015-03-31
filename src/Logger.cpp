//
//  Logger.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "Logger.h"


namespace std {
    
	Logger::Logger(string logFile, string csvFile, bool debug, string paramsDescr, string inputFileName) {
        
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
        
        startTimeEpoch = Helper::sysTimeUS();
        
        log("Revitpo: Version " __PRODUCT_RELEASE_VERSION);
        log("Antheny Yu, Ian Wong, Jason Ng, Mohammad Ghasembegi and Samuel Whitton");
        log("Parameters parsed: " + paramsDescr);
        log("Input CSV file: " + inputFileName);
        log("Output Log file: " + logFile);
        log("Output CSV file: " + csvFile);
        log("Started Execution: " + Helper::datetime());

	}
    
    Logger::~Logger() {
        stopLogging();
    }
    
    
    
    void Logger::logDebug(string log) {
        if (debug) {
            cout << "[DEBUG] " + log << endl;
        }
    }
    
    void Logger::logError(string errorDescr, bool fatal) {
        if (fatal) {
            log("[FATAL ERROR] " + errorDescr);
            cout << "[FATAL ERROR] " + errorDescr;
            stopLogging();
            exit(1);
        }
        log("[ERROR] " + errorDescr);
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
            log("Elapsed Time: " + to_string(Helper::sysTimeUS() - startTimeEpoch) + " us");
            
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




