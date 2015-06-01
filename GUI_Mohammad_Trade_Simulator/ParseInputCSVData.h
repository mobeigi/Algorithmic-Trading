#ifndef PARSEINPUTCSVDATA_H
#define PARSEINPUTCSVDATA_H

#include "GlobalIncludes.h"

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#define __CSV_DELIM ','

struct TradeDayData {
    std::string date;
    double open;
    double high;
    double low;
    double last;
};

namespace std {

class ParseInputCSVData
{
private:

public:
    ParseInputCSVData(string fileStr);
    vector<string> parseCSVLine(string line);

    //Map equity company to a vector of its trade days
    std::map<std::string, std::vector<TradeDayData>> data;
};


}

#endif // PARSEINPUTCSVDATA_H
