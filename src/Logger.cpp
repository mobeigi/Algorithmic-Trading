//
//  Logger.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "Logger.h"

#include <fstream>

namespace std {

    Logger::Logger() {}

    Logger Logger::standardLogger() {
        return Logger();
    }

    void Logger::log(string msg) {
        cout << msg + "\n";
    }

}
