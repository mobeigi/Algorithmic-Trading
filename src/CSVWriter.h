//
//  CSVWriter.h
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#ifndef __Algorithmic_Trading_CSVWriter__
#define __Algorithmic_Trading_CSVWriter__

namespace std {
      class CSVWriter;
}

#include "GlobalIncludes.h"

namespace std
{
    class CSVWriter {
    private:
          bool isOpen;
          ofstream output;
    public:
          CSVWriter();
          void startWriting(string dateFile);
          void stopWriting();
          void addCSVLine(string companyName, string date, double price, char signal);
    };
}

#endif
