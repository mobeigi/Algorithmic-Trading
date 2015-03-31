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
                  std::TradeDay trade = std::TradeDay(openPrice, highPrice, lowPrice, lastPrice, temp.at(0), temp.at(1));
                  strategy.nextDay(trade);
            } catch(std::invalid_argument) {}
      }
}

int main(int argc, const char * argv[]) {


      std::UnitTester tester = std::UnitTester();
      tester.testAll();

      bool foundFile;
      std::Param parameters = std::Param(argv[1] &foundFile);
      if(!foundFile) {
            // well fuck you
      }
      Param outputLogFile = parameters.getParam('output_logFile');
      if(outputLogFile.isNull) {
            // well fuck you too
      }

      std::Logger logger = std::Logger(outputLogFile.stringVal, outputCSVFile.stringVal, false);
      Param outputLogFile = parameters.getParam('output_csvFile');
      if(outputLogFile.isNull) {
            log.logError('\'output_csvfile\' parameter not found', true);
      }
      Param returns = parameters.getParam('returnsInCalculation');
      if(returns.isNull || !returns.isNumber) {
            log.logError('\'returnsInCalculation\' parameter not found', true);
      }
      Param threshold = parameters.getParam('threshold');
      if(threshold.isNull || !threshold.isNumber) {
            log.logError('\'threshold\' parameter not found', true);
      }
      Param inputCSVFile = parameters.getParam('input_csvFile');
      if(inputCSVFile.isNull) {
            log.logError('\'input_csvFile\' parameter not found', true);
      }

      std::MomentumStrategy strategy(logger, returns.intVal, threshold.doubleVal);
      std::CSVReader reader = std::CSVReader(inputCSVFile.stringVal);

      run(logger, reader, strategy);

      //To keep window open in visual studio
      //Remove before compiling release builds
      #ifdef _MSC_VER
      std::cin.get();
      std::cin.ignore();
      #endif
      logger.stopLogging();
      return 0;
}
