#ifndef ANALYSISDATA_H
#define ANALYSISDATA_H

#include "GlobalIncludes.h"

#include <string>
#include <vector>


namespace std {

enum signal {
    BUY,
    SELL
};

struct TradeData {
    signal tradeSignal;
    string date;
    double price;
    int tradeDayOffset; //days from the start of trading
    //int volume; not needed atm
    //double value; not needed atm
};


class AnalysisData
{

private:
    vector<TradeData> tradeData;
    string company;
    int totalDaysTrading;
    double priceLow;
    double priceHigh;

    int daysDifference(string dateFrom, string dateTo);

public:
    AnalysisData(string company);
    ~AnalysisData();

    void addNextTradeData(signal tradeSignal, string date, double price, int volume);

    int tradeDataAvailable();
    inline TradeData getData(int index) {return tradeData[index];}

    string firstTradeDate();
    string lastTradeDate();

    int daysTrading(); //total days, first - last trade date

    string getCompany();

    double highestPrice();
    double lowestPrice();

};

}

#endif // ANALYSISDATA_H


