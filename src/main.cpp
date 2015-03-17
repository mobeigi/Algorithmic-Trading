//
//  main.cpp
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "GlobalIncludes.h"

#include <iostream>

#include <vector>
#include <cstdlib>

#include "MomentumStrategy.h"
#include "Logger.h"
#include "TradeDay.h"
#include "Params.h"


void test(std::vector<std::TradeDay> trades) {
    std::Logger logger = std::Logger::standardLogger();
    std::MomentumStrategy strategy = std::MomentumStrategy(logger, 4, 0.001);
    for (std::TradeDay tradeDay : trades) {
        strategy.nextDay(tradeDay);
    }
    //logger.log(result.description());
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
        std::TradeDay(30, "test"),
        std::TradeDay(30.34, "test"),
        std::TradeDay(30.71, "test"),
        std::TradeDay(31.09, "test"),
        std::TradeDay(31.29, "test"),
        std::TradeDay(31.54, "test"),
        std::TradeDay(31.76, "test"),
        std::TradeDay(31.98, "test"),
        std::TradeDay(32.58, "test")};
    
    //test(testTrades);

    bool b;
    std::Params params = std::Params("paramfile.param", &b);
    
    if (!params.getParam("test_string").isNull)
        std::cout << params.getParam("test_string").stringVal << "\n";
    
    if (    !params.getParam("test_integer").isNull
        &&  !params.getParam("test_double").isNull
        &&  params.getParam("test_integer").isNumber
        &&  params.getParam("test_double").isNumber) {
        
        double val = params.getParam("test_integer").doubleVal
                +    params.getParam("test_double").doubleVal;
        std::cout << params.getParam("test_integer").stringVal + " + " +
            params.getParam("test_double").stringVal + " = " + std::to_string(val) << "\n";
    }
    
    return 0;
}




