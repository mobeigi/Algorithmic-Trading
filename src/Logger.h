//
//  Logger.h
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//


#ifndef __Algorithmic_Trading__Logger__
#define __Algorithmic_Trading__Logger__


namespace std {
    class Logger;
}

#include "GlobalIncludes.h"
#include <iostream>


namespace std {


    class Logger {

    private:
        void writeFile(string filename, vector<string> data);
        vector<string> logData;
        ~Logger();
        bool isLogging;

    public:
        void stopLogging();
      //   static Logger standardLogger();
        void log(int type, string message);
        Logger(string devTeam, string modName, string params);
      //   void log(string msg);
    };

}



#endif
