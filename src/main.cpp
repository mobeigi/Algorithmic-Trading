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

/*<<<<<<< HEAD
int main(int argc, const char * argv[]) {
      std::Logger logger("output.log", "cvsOut.csv", false);
      std::MomentumStrategy strategy = std::MomentumStrategy(logger, 4, 0.001);
      std::CSVReader reader = std::CSVReader("BHP_Daily_Since2000.csv");
=======*/
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
      
 
        std::Logger logger("output.log", "cvsOut.csv", false);
      std::MomentumStrategy strategy(logger, 4, 0.001);
      std::CSVReader reader = std::CSVReader("../BHP_Daily_Since2000.csv");

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
