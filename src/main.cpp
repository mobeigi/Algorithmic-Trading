//
//  main.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "GlobalIncludes.h"

#include <iostream>

#include <cstdlib>

#include "MomentumStrategy.h"
#include "Logger.h"
#include "TradeDay.h"
#include "Params.h"
#include "CSVReader.h"
#include "UnitTester.h"

void test(std::vector<std::TradeDay> trades) {
    std::Logger logger = std::Logger("output.log");
    std::MomentumStrategy strategy = std::MomentumStrategy(logger, 4, 0.001);
    for (std::TradeDay tradeDay : trades) {
        strategy.nextDay(tradeDay);
    }
    logger.stopCSV();
    //logger.log(result.description());
    logger.stopLogging();
}

int main(int argc, const char * argv[]) {

	// //Test our application using the unit tester
	// std::UnitTester ut;
	// bool isErrorFree = ut.testAll();
      //
	// if (!isErrorFree)
	// 	std::cout << "Warning: There are errors present in the code.";



    std::vector<std::TradeDay> testTrades = {
        std::TradeDay(30, "test", "10-04-1990"),
        std::TradeDay(30.34, "test", "11-04-1990"),
        std::TradeDay(30.71, "test", "12-04-1990"),
        std::TradeDay(31.09, "test", "13-04-1990"),
        std::TradeDay(31.29, "test", "14-04-1990"),
        std::TradeDay(31.54, "test", "15-04-1990"),
        std::TradeDay(31.76, "test", "16-04-1990"),
        std::TradeDay(31.98, "test", "17-04-1990"),
        std::TradeDay(32.58, "test", "18-04-1990")};

    test(testTrades);

    // bool b;
    // std::Params params = std::Params("paramfile.param", &b);
    //
    // if (!params.getParam("test_string").isNull) {
    //     std::cout << params.getParam("test_string").stringVal << "\n";
    // }
    //
    // if (    !params.getParam("test_integer").isNull
    //     &&  !params.getParam("test_double").isNull
    //     &&  params.getParam("test_integer").isNumber
    //     &&  params.getParam("test_double").isNumber) {
    //
    //     double val = params.getParam("test_integer").doubleVal
    //             +    params.getParam("test_double").doubleVal;
    //     std::cout << params.getParam("test_integer").stringVal + " + " +
    //         params.getParam("test_double").stringVal + " = " + std::to_string(val) << "\n";
    // }

	//To keep window open in visual studio
	//Remove before compiling release builds
	#ifdef _MSC_VER
	std::cin.get();
	std::cin.ignore();
	#endif

    return 0;
}
