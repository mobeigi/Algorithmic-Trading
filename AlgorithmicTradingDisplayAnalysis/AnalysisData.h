#ifndef ANALYSISDATA_H
#define ANALYSISDATA_H

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

struct Date {
    int day;
    int month;
    int year;
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
    int daysInMonth(int month, int year);
    Date parseDate(string dateStr); //day, month, year

public:
    AnalysisData(string company);
    ~AnalysisData();

    void addNextTradeData(signal tradeSignal, string date, double price, int volume);

    int tradeDataAvaliable();
    TradeData getData(int index);

    string firstTradeDate();
    string lastTradeDate();

    int daysTrading(); //total days, first - last trade date

    string getCompany();

    double highestPrice();
    double lowestPrice();

};

}

#endif // ANALYSISDATA_H


