//
//  UnitTester.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 24/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "UnitTester.h"
#include "GlobalIncludes.h"
#include "Strategy.h"
#include "StrategyResult.h"
#include "Logger.h"

#include <iostream>

namespace std 
{
	//Function Declarations
	bool testGlobalIncludes();
	bool testStrategyResult();

	UnitTester::UnitTester() {}

	//Test all components using this function
	bool UnitTester::testAll() {
		assert(testGlobalIncludes());
		assert(testStrategyResult());
		return true;
	}

	//GlobalIncludes.h
	bool testGlobalIncludes() {
		//Test Formating functions

		//Price format
		assert(Helper::formatPrice(0) == "$0.00");
		assert(Helper::formatPrice(1) == "$1.00");
		assert(Helper::formatPrice(2.33) == "$2.33");
		assert(Helper::formatPrice(-500.88) == "-$500.88");
		assert(Helper::formatPrice(-20.3041) == "-$20.30"); //round down
		assert(Helper::formatPrice(-20.3061) == "-$20.31"); //round up

		//Double format
		assert(Helper::formatDouble(0) == "0.0000");
		assert(Helper::formatDouble(1) == "1.0000");
		assert(Helper::formatDouble(2.33) == "2.3300");
		assert(Helper::formatDouble(-500.88) == "-500.8800");
		assert(Helper::formatDouble(-2344.5673) == "-2344.5673");
		assert(Helper::formatDouble(345465.23423546) == "345465.2342");

		return true;
	}

	//StrategyResult
	bool testStrategyResult() {
		assert(StrategyResult::nullResult().isNull()); //check static nullResult is actually null
		return true;
	}
}