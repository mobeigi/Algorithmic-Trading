//
//  CSVReader.h
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#ifndef __Algorithmic_Trading_CSVReader__
#define __Algorithmic_Trading_CSVReader__

namespace std {
      class CSVReader;
}

#include <vector>
#include "GlobalIncludes.h"

namespace std
{
    class CSVReader
    {
    private:
		ifstream &file;
        bool stillReading;
        //vector<string> file;
        //unsigned at;
    public:
        CSVReader(string dataFile);
        bool nextTrade();
        vector<string> getTrade();
        void stopReading();
    };
}

#endif
