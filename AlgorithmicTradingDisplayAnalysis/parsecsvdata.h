#ifndef PARSECSVDATA_H
#define PARSECSVDATA_H

#include "AnalysisData.h"

#include <map>
#include <string>
#include <vector>
#include <fstream>

#define __CSV_DELIM ','

namespace std {

class ParseCSVData
{
private:
    vector<string> equityTypes;
    map<string, AnalysisData*> allData;

    vector<string> parseCSVLine(string line);

public:
    ParseCSVData(string fileStr);
    ~ParseCSVData();

    vector<string> getAllEquityTypes();
    AnalysisData *getDataForEquityType(string equityType);
};


}

#endif // PARSECSVDATA_H


