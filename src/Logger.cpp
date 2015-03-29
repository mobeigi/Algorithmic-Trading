//
//  Logger.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "Logger.h"

namespace std {
	Logger::Logger(string dataFile) {
		output = ofstream(dataFile, ios::trunc);
		if(output.is_open()) {
			isLogging = true;
			output << "Revitpo Version: 1.00" << endl;
			output << "Developed By: Samuel Whitton, Mohammad Ghasembegi, Ian Wong, Jason Ng and Antheny Yu" << endl;
			log(__LOG_INFO, "Output LOG File: " + dataFile);
			log(__LOG_INFO, "Started Execution: " + Helper::datetime());
		}
	}
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
				case __LOG_FATAL:
				ss << "[FATAL] ";
				exit(1);
				break;
#ifdef DEBUG
				case __LOG_DEBUG:
				ss << "[DEBUG] ";
				break;
#endif
				default:
					return;
				break;
			}
			ss << message;
			output << ss.str() << endl;
		}
	}
	void Logger::startCSV(string companyName) {
		if(csvData.find(companyName) == csvData.end()) {
			csvData[companyName] = CSVWriter();
			csvData[companyName].startWriting(companyName);
			log(__LOG_INFO, "Output DATA File: " + companyName + ".csv");
		}
		csv = &csvData[companyName];
		isCSV = true;
	}
	void Logger::writeToCSV(string companyName, string date, double price, char signal) {
		if(isCSV) csv->addCSVLine(companyName, date, price, signal);
	}
	void Logger::stopCSV() {
		if(isCSV) csv->stopWriting();
		isCSV = false;
	}
	void Logger::stopLogging() {
		if(isLogging) {
			log(__LOG_INFO, "Ended Execution: " + Helper::datetime());
			log(__LOG_INFO, "Elapsed Time: ");
			isLogging  = false;
			for(auto const& p : csvData) csvData[p.first].stopWriting();
			output.close();
		}
	}

}
