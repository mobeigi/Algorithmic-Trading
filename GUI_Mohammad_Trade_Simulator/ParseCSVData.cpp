#include "ParseCSVData.h"

namespace std {

ParseCSVData::ParseCSVData(string fileStr) {
    ifstream file(fileStr);

    if (file.is_open()) {

        int colSignal = -1;
        int colDate = -1;
        int colPrice = -1;
        int colVolume = -1;
        int colCompany = -1;

        string line;

        if (std::getline(file, line)) {

            vector<string> columnTitles = parseCSVLine(line);

            //find the columns
            int index = 0;
            for (string strCol : columnTitles) {
                if (strCol.compare("#Company") == 0 || strCol.compare("Company Name") == 0) colCompany = index;
                else if (strCol.compare("Date") == 0 || strCol.compare("Date/Time") == 0) colDate = index;
                else if (strCol.compare("Price") == 0) colPrice = index;
                else if (strCol.compare("Volume") == 0) colVolume = index;
                else if (strCol.compare("Signal") == 0 || strCol.compare("Bid/ask") == 0) colSignal = index;
                index++;
            }

            if (colSignal != -1 && colDate != -1
                    && colPrice != -1 && colVolume != -1
                    && colCompany != -1) {

                while (std::getline(file, line)) {
                    vector<string> row = parseCSVLine(line);

                    AnalysisData *data = nullptr;
                    if (allData.find(row[colCompany]) == allData.end()) {
                        allData[row[colCompany]] = new AnalysisData(row[colCompany]);
                        equityTypes.push_back(row[colCompany]);
                    }
                    data = allData[row[colCompany]];

                    signal sig = BUY;
                    if (row[colSignal].compare("S") == 0 || row[colSignal].compare("Sell") == 0)
                        sig = SELL;

                    data->addNextTradeData(sig, row[colDate], stod(row[colPrice]), stoi(row[colVolume]));
                }

            }
        }



        file.close();
    }
}

ParseCSVData::~ParseCSVData() {
    for (auto data : allData) {
        delete data.second;
    }
}


vector<string> ParseCSVData::getAllEquityTypes() {
    return equityTypes;
}

AnalysisData *ParseCSVData::getDataForEquityType(string equityType) {
    if (allData.find(equityType) == allData.end())
        return nullptr;
    return allData[equityType];
}

vector<string> ParseCSVData::parseCSVLine(string line) {
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
