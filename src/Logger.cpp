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
				case __LOG_DEBUG:
				ss << "[DEBUG] ";
				break;
			}
			ss << Helper::datetime() << ' ';
			ss << message;
			output << ss.str() << endl;
		}
	}

	void Logger::startCSV(string companyName) {
		if(csvData.find(companyName) == csvData.end()) {
			csvData[companyName] = CSVWriter();
			csvData[companyName].startWriting(companyName);
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
			isLogging  = false;
			output.close();
		}
	}

}
