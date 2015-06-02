#include "ParseInputCSVData.h"

namespace std {

ParseInputCSVData::ParseInputCSVData(string fileStr) {

    ifstream file(fileStr);

    if (file.is_open()) {
        int colCompany = -1;
        int colDate = -1;
        int colQualifier = -1;
        int colOpen = -1;
        int colHigh = -1;
        int colLow = -1;
        int colLast = -1;

        string line;

        if (std::getline(file, line)) {

            vector<string> columnTitles = parseCSVLine(line);

            //find the columns
            int index = 0;

            for (string strCol : columnTitles) {
                if (strCol.compare("#RIC") == 0) colCompany = index;
                else if (strCol.compare("Date[L]") == 0) colDate = index;
                else if (strCol.compare("Qualifiers") == 0) colQualifier = index;
                else if (strCol.compare("Open") == 0) colOpen = index;
                else if (strCol.compare("High") == 0) colHigh = index;
                else if (strCol.compare("Low") == 0) colLow = index;
                else if (strCol.compare("Last") == 0) colLast = index;
                index++;
            }

            if (colCompany != -1 && colDate != -1
                    && colQualifier != -1 && colOpen != -1
                    && colHigh != -1 && colLow != -1 && colLast != -1) {

                //Loop through data rows
                while (std::getline(file, line)) {
                    vector<string> row = parseCSVLine(line);

                    //Create tradedaydata struct for this row
                    TradeDayData tdd;
                    tdd.date = row[colDate];

                    if (row[colQualifier] == "No Trades") {
                      //If no trades, simply ignore the data
                      continue;
                    }

                    //If any of the value fields are empty, ignore row
                    if (row[colHigh].empty() || row[colLast].empty() || row[colLow].empty() || row[colOpen].empty())
                        continue;

                    tdd.high = std::stod(row[colHigh]);
                    tdd.last = std::stod(row[colLast]);
                    tdd.low = std::stod(row[colLow]);
                    tdd.open = std::stod(row[colOpen]);


                    //Check if map exists for this eqType
                    if (data.find(row[colCompany]) != data.end()) {
                        this->data.at(row[colCompany]).push_back(tdd);
                    }
                    //Else vector does not exist
                    else {
                        std::vector<TradeDayData> entry = std::vector<TradeDayData>();
                        entry.push_back(tdd);
                        this->data[row[colCompany]] = entry;
                    }
                }

            }
        }

        file.close();
    }
}

vector<string> ParseInputCSVData::parseCSVLine(string line) {
    vector<string> parsed;
    for(unsigned i = 0; i < line.length(); i++) {
        while(line[i] == ' ') ++i;
        unsigned b = i;
        for(; line[i] != __CSV_DELIM && i != line.length(); i++);
        string parsedComponent = line.substr(b, i - b);
        parsed.push_back(Helper::trim(parsedComponent));
    }
    return parsed;
}


}
