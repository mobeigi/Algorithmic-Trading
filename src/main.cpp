//
//  main.cpp
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "GlobalIncludes.h"

#include <iostream>

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
    return 0;
}





