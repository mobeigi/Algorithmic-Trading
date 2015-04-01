//
//  UnitTester.h
//  Algorithmic Trading SENG3011
//
//  Created on 24/03/15.
//  Copyright (c) Trock. All rights reserved.
//

#ifndef __Algorithmic_Trading__UnitTester__
#define __Algorithmic_Trading__UnitTester__

//Includes
#include <cassert>

namespace std
{
    class UnitTester
    {
        
    public:
        UnitTester(); // Constructor
        
        /*
         * Returns true if all components passed all tests. False otherwise.
         */
        bool testAll(); // Test all components
    };
}

#endif