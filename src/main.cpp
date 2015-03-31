//
//  main.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
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

void run(std::Logger &logger, std::CSVReader &reader, std::Strategy &strategy) {
      while(reader.nextTrade()) {
            std::vector<std::string> temp = reader.getTrade();
            try {
                  double lastPrice = std::stod(temp.at(8));
                  double lowPrice = std::stod(temp.at(7));
                  double highPrice = std::stod(temp.at(6));
                  double openPrice = std::stod(temp.at(5));
                  std::TradeDay trade(openPrice, highPrice, lowPrice, lastPrice, temp.at(0), temp.at(1));
                  strategy.nextDay(trade);
            } catch(std::invalid_argument) {}
      }
}

int main(int argc, const char * argv[]) {

      int returnsValue = 4;
      double thresholdValue = 0.001;
      std::UnitTester tester;
      tester.testAll();

	  //Ensure we have the corrent number of arguments
      if(argc < 2) {
            return 1;
      }
      bool foundFile;
      std::Params parameters(argv[1], &foundFile);
      if(!foundFile) {
            return 1;
      }
      std::Param outputLogFile = parameters.getParam("output_logFile");
      if(outputLogFile.isNull) {
            return 1;
      }
      std::Param outputCSVFile = parameters.getParam("output_csvFile");
      if(outputCSVFile.isNull) {
            return 1;
      }

      std::Logger logger(outputLogFile.stringVal, outputCSVFile.stringVal, false);
      std::Param inputCSVFile = parameters.getParam("input_csvFile");
      if(inputCSVFile.isNull) {
            logger.logError("'input_csvFile' parameter not found\n", true);
      }
      std::Param returns = parameters.getParam("returnsInCalculation");
      if(returns.isNull || !returns.isNumber) {
            logger.logError("'returnsInCalculation' parameter not found\n", false);
      } else returnsValue = returns.intVal;
      std::Param threshold = parameters.getParam("threshold");
      if(threshold.isNull || !threshold.isNumber) {
            logger.logError("'threshold' parameter not found\n", false);
      } else thresholdValue = threshold.doubleVal;

      std::MomentumStrategy strategy(logger, returnsValue, thresholdValue);
      std::CSVReader reader(inputCSVFile.stringVal, & foundFile);
      if(!foundFile) logger.logError("'input_csvFile' not found\n", true);

      run(logger, reader, strategy);
      logger.stopLogging();

	  //To keep window open in visual studio
	  //Remove before compiling release builds
	  #ifdef _MSC_VER
	  std::cin.get();
	  std::cin.ignore();
	  #endif

      return 0;
}
