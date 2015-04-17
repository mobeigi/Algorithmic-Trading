#include "AnalysisData.h"

namespace std {

AnalysisData::AnalysisData(string company) : company(company) {
    totalDaysTrading = 0;
    priceLow = -1;
    priceHigh = -1;
}

AnalysisData::~AnalysisData() {

}

void AnalysisData::addNextTradeData(signal tradeSignal, string date, double price, int volume) {
    TradeData trade;
    trade.date = date;
    trade.tradeSignal = tradeSignal;
    trade.price = price;
    if (price > priceHigh || priceHigh == -1) {
        priceHigh = price;
    } else if (price < priceLow || priceLow == -1) {
        priceLow = price;
    }
    if (tradeDataAvaliable() == 0) {
        trade.tradeDayOffset = 0;
        totalDaysTrading = 1;
    } else {
        trade.tradeDayOffset = daysDifference(lastTradeDate(), trade.date) + totalDaysTrading - 1;
        totalDaysTrading = trade.tradeDayOffset + 1; //offset to lastest day + 1
    }
    tradeData.push_back(trade);
}

int AnalysisData::tradeDataAvaliable() {
    return tradeData.size();
}

TradeData AnalysisData::getData(int index) {
    return tradeData[index];
}

string AnalysisData::firstTradeDate() {
    return tradeData[0].date;
}

string AnalysisData::lastTradeDate() {
    return tradeData[tradeDataAvaliable() - 1].date;
}

string AnalysisData::getCompany() {
    return company;
}

int AnalysisData::daysTrading() {
    return totalDaysTrading;
}

double AnalysisData::highestPrice() {
    return priceHigh;
}

double AnalysisData::lowestPrice() {
    return priceLow;
}

int AnalysisData::daysDifference(string dateFrom, string dateTo) {

    Date from = parseDate(dateFrom);
    Date to = parseDate(dateTo);

    if (from.day == -1 || to.day == -1 || from.month == -1 || to.month == -1 || from.year == -1 || to.year == -1) {
        return -1; //error, date parse failed
    }

    int diff = 0;

    while (from.year < to.year || (from.year == to.year && from.month < to.month || (from.month == to.month && from.day < to.day) ) ) {
        diff++;
        from.day++;
        if (from.day > daysInMonth(from.month, from.year)) {
            from.day = 1;
            from.month++;
            if (from.month > 12) {
                from.month = 1;
                from.year++;
            }
        }
    }

    return diff;
}

//day, month, year
Date AnalysisData::parseDate(string dateStr) {

    Date date;
    date.day = -1;
    date.month = -1;
    date.year = -1;

    if (dateStr.size() == 11) {

        date.day = stoi(dateStr.substr(0,2).c_str());
        date.year = stoi(dateStr.substr(7,4).c_str());

        string strMonth = dateStr.substr(3, 3);
        if (strMonth.compare("JAN") == 0)
            date.month = 1;
        else if (strMonth.compare("FEB") == 0)
                date.month = 2;
        else if (strMonth.compare("MAR") == 0)
                date.month = 3;
        else if (strMonth.compare("APR") == 0)
                date.month = 4;
        else if (strMonth.compare("MAY") == 0)
                date.month = 5;
        else if (strMonth.compare("JUN") == 0)
                date.month = 6;
        else if (strMonth.compare("JUL") == 0)
                date.month = 7;
        else if (strMonth.compare("AUG") == 0)
                date.month = 8;
        else if (strMonth.compare("SEP") == 0)
                date.month = 9;
        else if (strMonth.compare("OCT") == 0)
                date.month = 10;
        else if (strMonth.compare("NOV") == 0)
                date.month = 11;
        else if (strMonth.compare("DEC") == 0)
                date.month = 12;
    }

    return date;
}

int AnalysisData::daysInMonth(int month, int year) {
    month--; //change from 1-12 to 0-11
    int numberOfDays;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        numberOfDays = 30;
    } else if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear)
            numberOfDays = 29;
        else
            numberOfDays = 28;
    } else {
        numberOfDays = 31;
    }
    return numberOfDays;
}

}
