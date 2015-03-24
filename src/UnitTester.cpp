//
//  UnitTester.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 24/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "UnitTester.h"
#include "GlobalIncludes.h"

#include <iostream>

namespace std 
{
	//Function Declarations
	bool testGlobalIncludes();

	UnitTester::UnitTester() {}

	//Test all components using this function
	bool UnitTester::testAll() {
		testGlobalIncludes();
		return true;
	}

	//GlobalIncludes.h
	bool testGlobalIncludes() {
		//Test Formating functions
		//assert(Helper::formatPrice(1) == "$1.00");
		//assert(Helper::formatPrice(1) == "$1.00");

		std::cout << Helper::formatPrice(1);
		return true;
	}

}