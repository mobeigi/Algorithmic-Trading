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
    std::vector<std::TradeDay> trades = {std::TradeDay(), std::TradeDay(), std::TradeDay()};
    std::MomentumStrategy(logger, trades).execute();
}

int main(int argc, const char * argv[]) {
    test();
    return 0;
}





