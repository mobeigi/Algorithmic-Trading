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

int main(int argc, const char * argv[]) {
      std::Logger logger = std::Logger("output.log");
      std::MomentumStrategy strategy = std::MomentumStrategy(logger, 4, 0.001);
      std::CSVReader reader = std::CSVReader("../BHP_Daily_Since2000.csv");
      while(reader.nextTrade()) {
            std::vector<std::string> temp = reader.getTrade();
            try {
                  double lastPrice = std::stod(temp.at(8));
                  std::TradeDay trade = std::TradeDay(lastPrice, temp.at(0), temp.at(1));
                  strategy.nextDay(trade);
            } catch(std::invalid_argument) {}
      }

      //To keep window open in visual studio
      //Remove before compiling release builds
      #ifdef _MSC_VER
      std::cin.get();
      std::cin.ignore();
      #endif
      logger.stopLogging();
      return 0;
}
