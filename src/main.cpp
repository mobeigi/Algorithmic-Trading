//
//  main.cpp
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "GlobalIncludes.h"

#include <iostream>

#include <fstream>
#include <vector>
#include <cstdlib>

#include "MomentumStrategy.h"
#include "Logger.h"
#include "TradeDay.h"


void test(std::vector<std::TradeDay> trades) {
    std::Logger logger = std::Logger::standardLogger();
    std::StrategyResult result = std::MomentumStrategy(logger, trades, 4, 0.001).execute();
    logger.log(result.description());
}

int main(int argc, const char * argv[]) {
    // we can either store the file into memory? or just grab what we need?
    // since we need to implement different strategies later?
    /*std::ifstream d;
    std::string m;
    std::vector<std::string> tradingData, temp;
    std::vector<std::TradeDay> trades;

    //if(argc != 2) return false;
    d.open("BHP_Daily_Since2000.csv");
    if(d.is_open()) {
          while(getline(d, m)) tradingData.push_back(m);
          d.close();

          // we need to figure out what data we want to take from the parsed shit
          // i.e. should pass in the tradingData to the strategy
          for(unsigned n = 0; n != tradingData.size(); n++) {
                m = tradingData.at(n);
                for(unsigned i = 0; i < m.length(); i++) {
                      unsigned b = i;
                      for(; m[i] != ',' && i + 1 != m.length(); i++);
                      temp.push_back(m.substr(b, i - b));
                }
                //std::cout << temp.at(8) << '\n';
                if(!temp.at(8).empty()) trades.push_back(std::TradeDay(std::atof(temp.at(8).c_str())));
                temp.clear();
          }
    }*/
    
    std::vector<std::TradeDay> testTrades = {
        std::TradeDay::TradeDay(30),
        std::TradeDay::TradeDay(30.34),
        std::TradeDay::TradeDay(30.71),
        std::TradeDay::TradeDay(31.09),
        std::TradeDay::TradeDay(31.29),
        std::TradeDay::TradeDay(31.54),
        std::TradeDay::TradeDay(31.76),
        std::TradeDay::TradeDay(31.98),
        std::TradeDay::TradeDay(32.58)};
    
    test(testTrades);
    return 0;
}




