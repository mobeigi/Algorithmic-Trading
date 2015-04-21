//
//  main.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
//

#include <iostream>
#include <cstdlib>

#include "GlobalIncludes.h"
#include "MomentumStrategy.h"
#include "Logger.h"
#include "TradeDay.h"
#include "Params.h"
#include "CSVReader.h"
#include "UnitTester.h"

void run(std::Logger &logger, std::CSVReader &reader, std::Strategy *strategy) {
    while(reader.nextTrade()) {
        std::vector<std::string> temp = reader.getTrade();
        if(temp.at(4).compare("No Trades") == 0) continue;
        try {
            double lastPrice = std::stod(temp.at(8));
            double lowPrice = std::stod(temp.at(7));
            double highPrice = std::stod(temp.at(6));
            double openPrice = std::stod(temp.at(5));
            std::TradeDay trade(openPrice, highPrice, lowPrice, lastPrice, temp.at(0), temp.at(1));
            strategy->nextDay(trade);
        } catch(std::invalid_argument) {}
    }
}

int main(int argc, const char * argv[]) {
    
    int returnsValue = 4;
    double thresholdValue = 0.001;

#ifdef DEBUG
    std::UnitTester tester;
    tester.testAll();
#endif // DEBUG
    
    // Ensure we have the corrent number of arguments
    // or the nasty seg fault monster will come and steal all the sugar
    if(argc < 2) {
        std::cerr << "usage: " << argv[0] << " [parameter file]" << std::endl;
        return 0;
    }

    //Check to see if we can find parameter file
    bool foundFile;
    std::Params parameters(argv[argc], &foundFile);
    if(!foundFile) {
      std::cerr << "Fatal Error: The parameter file was not found." << std::endl;
        return 0;
    }

    //Check to see if outputLogfile exists
    std::Param outputLogFile = parameters.getParam("output_logFile");
    if(outputLogFile.isNull) {
        std::cerr << "Fatal Error: Failed to load file specified in 'output_logFile' parameter." << std::endl;
        return 0;
    }

    //Check to see if  csv file exists
    std::Param outputCSVFile = parameters.getParam("output_csvFile");
    if(outputCSVFile.isNull) {
        std::cerr << "Fatal Error: Failed to load file specified in 'output_csvFile' parameter." << std::endl;
        return 0;
    }

    //Check to see if input csv file exists
    std::Param inputCSVFile = parameters.getParam("input_csvFile");
    if (inputCSVFile.isNull) {
      std::cerr << "Fatal Error: Failed to load file specified in 'input_csvFile' parameter." << std::endl;
      return 0;
    }

    //Check if outputCSV is equal to inputCSV and fail if it is (to prevent overwriting input)
    if (outputCSVFile.stringVal.compare(inputCSVFile.stringVal) == 0) {
      std::cerr << "Fatal Error: 'input_csvFile' parameter and 'output_csvFile' parameter must be different." << std::endl;
      return 0;
    }

    //Check if outputLog is the inputCSV file (we don't want to output csv to the log file)
    if (outputLogFile.stringVal.compare(inputCSVFile.stringVal) == 0) {
      std::cerr << "Fatal Error: 'input_csvFile' parameter and 'output_logFile' parameter must be different." << std::endl;
      return 0;
    }

    //Check if outputlog and outCSV are the same, we don't want to output log and CSV to same file
    if (outputLogFile.stringVal.compare(outputCSVFile.stringVal) == 0) {
      std::cerr << "Fatal Error: 'output_csvFile' parameter and 'output_logFile' parameter must be different." << std::endl;
      return 0;
    }
    
    //Set up logger
    std::Logger logger(outputLogFile.stringVal, outputCSVFile.stringVal, false, parameters.paramList(), inputCSVFile.stringVal);
    
    logger.log("Parameter: 'output_csvFile' Value: " + outputCSVFile.stringVal);
    logger.log("Parameter: 'output_logFile' Value: " + outputLogFile.stringVal);
    logger.log("Parameter: 'input_csvFile' Value: " + inputCSVFile.stringVal);
    
    
    std::Param returns = parameters.getParam("returnsInCalculation");
    if(returns.isNull || !returns.isNumber) {
        logger.logError("'returnsInCalculation' parameter not found\n", false);
    } else {
        returnsValue = returns.intVal;
        logger.log("Parameter: 'returnsInCalculation' Value: " + std::to_string(returnsValue));
    }
    std::Param threshold = parameters.getParam("threshold");
    if(threshold.isNull || !threshold.isNumber) {
        logger.logError("'threshold' parameter not found\n", false);
    } else {
        thresholdValue = threshold.doubleVal;
        logger.log("Parameter: 'threshold' Value: " + std::to_string(thresholdValue));
    }
    
    std::Param startDate = parameters.getParam("startDate");
    std::Param endDate = parameters.getParam("endDate");
    
    std::MomentumStrategy *strategy = nullptr;
    
    if (startDate.isNull || endDate.isNull) {
        strategy = new std::MomentumStrategy(logger, "", "", returnsValue, thresholdValue);
    } else {
        strategy = new std::MomentumStrategy(logger, startDate.stringVal, endDate.stringVal, returnsValue, thresholdValue);
    }
    std::CSVReader reader(inputCSVFile.stringVal, & foundFile);
    if(!foundFile) logger.logError("'input_csvFile' not found\n", true);
    
    run(logger, reader, strategy);
    
    logger.log("Execution Status: Success!");
    logger.stopLogging();
    
    delete strategy;
    
    return 0;
}






