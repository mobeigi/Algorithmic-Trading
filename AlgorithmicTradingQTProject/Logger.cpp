//
//  Logger.cpp
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "Logger.h"


namespace std {

    Logger::Logger() {}
    
    Logger Logger::standardLogger() {
        return Logger();
    }
    
    void Logger::log(string msg) {
        cout << msg + "\n";
    }

}
