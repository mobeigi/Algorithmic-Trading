#include "ReturnsAnalysis.h"

void ReturnsAnalysis::returnsAnalysis(std::AnalysisData *data) {

    //maintain queues of trades, one for buy and one for sell
    // int is for maintaining which one came first
    vector<tuple<TradeData, int>> buy_trades;
    vector<tuple<TradeData, int>> sell_trades;

    //maintain total return percentage
    double net_return_perc = 0;

    //read the trade orders line by line
    for (int i = 0; i < data->tradeDataAvailable(); i++) {

        //load the vectors as appropriate
        if (data->getData(i).tradeSignal == BUY) {
            buy_trades.push_back(tuple<TradeData,int>(data->getData(i),i));
        } else {
            sell_trades.push_back(tuple<TradeData,int>(data->getData(i),i));
        }

        //Determine whether there is a buy-sell / sell-buy pair
        if (buy_trades.size() > 0 && sell_trades.size() > 0) {
            tuple<TradeData,int> buy_trade = buy_trades.front();
            tuple<TradeData,int> sell_trade = sell_trades.front();

            if (get<1>(sell_trade) > get<1>(buy_trade)) {
                //a buy-sell pair
                printf("Buy@%lf,", get<0>(buy_trade).price);
                printf("Sell@%lf. ", get<0>(sell_trade).price);
                printf("Date: %s. ",get<0>(sell_trade).date.c_str());
            } else {
                //a sell-buy pair
                printf("Buy@%lf,", get<0>(sell_trade).price);
                printf("Sell@%lf. ", get<0>(buy_trade).price);
                printf("Date: %s. ",get<0>(buy_trade).date.c_str());
            }

            //Calculate return
            double return_perc = (get<0>(sell_trade).price - get<0>(buy_trade).price) / get<0>(buy_trade).price;
            printf("Return: %lf",return_perc);

            //update total return
            net_return_perc += return_perc;

            //Remove the first trades from both queues
            buy_trades.erase(buy_trades.begin(),buy_trades.begin()+1);
            sell_trades.erase(sell_trades.begin(),sell_trades.begin()+1);
        }


    }

}
