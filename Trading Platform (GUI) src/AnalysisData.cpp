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
    if (tradeDataAvailable() == 0) {
        trade.tradeDayOffset = 0;
        totalDaysTrading = 1;
    } else {
        trade.tradeDayOffset = daysDifference(lastTradeDate(), trade.date) + totalDaysTrading - 1;
        totalDaysTrading = trade.tradeDayOffset + 1; //offset to lastest day + 1
    }
    tradeData.push_back(trade);
}

int AnalysisData::tradeDataAvailable() {
    return tradeData.size();
}

TradeData AnalysisData::getData(int index) {
    return tradeData[index];
}

string AnalysisData::firstTradeDate() {
    return tradeData[0].date;
}

string AnalysisData::lastTradeDate() {
    return tradeData[tradeDataAvailable() - 1].date;
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

    Date from = Helper::parseDate(dateFrom);
    Date to = Helper::parseDate(dateTo);

    if (from.day == -1 || to.day == -1 || from.month == -1 || to.month == -1 || from.year == -1 || to.year == -1) {
        return -1; //error, date parse failed
    }

    int diff = 0;

    while (from.year < to.year || (from.year == to.year && (from.month < to.month || (from.month == to.month && from.day < to.day)) ) ) {
        diff++;
        from.day++;
        if (from.day > Helper::daysInMonth(from.month, from.year)) {
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


}
