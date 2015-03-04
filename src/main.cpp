//
//  main.cpp
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "GlobalIncludes.h"

#include <iostream>

#include <ifstream>
#include <vector>

#include "MomentumStrategy.h"
#include "Logger.h"
#include "TradeDay.h"


void test() {
    std::Logger logger = std::Logger::standardLogger();
    std::vector<std::TradeDay> trades = {
        std::TradeDay(30.0),
        std::TradeDay(30.34),
        std::TradeDay(30.71),
        std::TradeDay(31.09),
        std::TradeDay(31.29),
        std::TradeDay(31.54),
        std::TradeDay(31.76),
        std::TradeDay(31.98),
        std::TradeDay(32.58)};
    std::StrategyResult result = std::MomentumStrategy(logger, trades, 3).execute();
    logger.log(result.description());
}

int main(int argc, const char * argv[]) {
    test();

    // if(argc != 2) return false;
    std::ifstream file;
    std::string line, tmp;
    std::vector<std::string> data;
    std::vector<std::vector<std::string> > tradingData;
    file.open("BHP_Daily_Since2000.csv");
    if(file.is_open()) {
          while(getline(file, line)) {
                if(line.at(0) == '#') continue;
                for(unsigned i = 0; i < line.length(); i++) {
                      if(line[i] != ',' && i + 1 != line.length()) {
                            tmp += line[i];
                            continue;
                      }
                      data.push_back(tmp);
                      tmp = "";
                }
                tradingData.push_back(data);
          }
    }
    file.close();
    // for(unsigned n = 0; n != tradingData.size(); n++) {
    //       data = tradingData.at(n);
    //       for(unsigned o = 0; o != data.size(); o++) {
    //             if(data.at(o).empty()) std::cout << "(null)" << '\n';
    //             else std::cout << data.at(o) << '\n';
    //       }
    // }


    return 0;
}
