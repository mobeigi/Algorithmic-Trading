//
//  main.cpp
//  Algorithmic Trading SENG3011
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
#include "Reader.h"
#include "UnitTester.h"

void test(std::vector<std::TradeDay> trades) {
    std::Logger logger = std::Logger::standardLogger();
    std::MomentumStrategy strategy = std::MomentumStrategy(logger, 4, 0.001);
    for (std::TradeDay tradeDay : trades) {
        strategy.nextDay(tradeDay);
    }
    //logger.log(result.description());
}

int main(int argc, const char * argv[]) {

	//Test our application using the unit tester
	std::UnitTester ut;
	bool isErrorFree = ut.testAll();

	if (!isErrorFree)
		std::cout << "Warning: There are errors present in the code.";

	std::Reader reader = std::Reader("BHP_Daily_Since2000.csv");
      while(reader.nextTrade()) {
          std::vector<std::string> line = reader.getTrade();
          std::cout << line.at(8) << std::endl;
      }

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

    if (!params.getParam("test_string").isNull) {
        std::cout << params.getParam("test_string").stringVal << "\n";
    }

    if (    !params.getParam("test_integer").isNull
        &&  !params.getParam("test_double").isNull
        &&  params.getParam("test_integer").isNumber
        &&  params.getParam("test_double").isNumber) {

        double val = params.getParam("test_integer").doubleVal
                +    params.getParam("test_double").doubleVal;
        std::cout << params.getParam("test_integer").stringVal + " + " +
            params.getParam("test_double").stringVal + " = " + std::to_string(val) << "\n";
    }
	
	//To keep window open in visual studio
	//Remove before compiling release builds
	#ifdef _MSC_VER
	std::cin.get();
	std::cin.ignore();
	#endif

    return 0;
}
