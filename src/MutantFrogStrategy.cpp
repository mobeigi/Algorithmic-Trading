//
//  MutantFrogStrategy.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
//

#include "MutantFrogStrategy.h"


#define INITIAL_RETURNS_IN_CALCULATION MIN_RETURNS_IN_CALCULATION
#define INITIAL_THRESHOLD 0.001 //arbitrary

#define RETURNS_WINDOW_MOD 0.78

#define THRESHOLD_PERCENT_RANGE 0.1

#define MIN_RETURNS_IN_CALCULATION 7
#define RETURNS_DIFFERENCE_PERCENT 0.35

#define EQUITY_LOSS_PERCENT_ALLOWANCE 0.035

namespace std {
    
    MutantFrogStrategy::MutantFrogStrategy(Logger &logger, string startDate, string endDate, double threshold) :
    super(logger, startDate, endDate, INITIAL_RETURNS_IN_CALCULATION, threshold), influences() {}
    
    void MutantFrogStrategy::nextTradeDay(TradeDay tradeDay, bool enableTrading) {
        
        double thisPrice = tradeDay.getLastPrice();
        
        MomentumStrategyData *superData = super::dataForTradeDay(tradeDay);
        
        //enable on odd trades
        bool enableBuyTrades = enableTrading && !superData->lastSignalOdd;
        
        //dont enable selling on first trade, and enable on all even trades
        bool enableSellTrades = enableTrading && superData->lastSignalOdd;
        
        
        //inc returns in calc
        //if (superData->returnsInCalculation <= (int)superData->returns.size()) {
        //    superData->returnsInCalculation += 1;
        //}
        
        //if (!superData->lastSignalOdd && superData->returns.size() >= MIN_RETURNS_IN_CALCULATION) {
        //    superData->returnsInCalculation = MIN_RETURNS_IN_CALCULATION;
        //}
        
        //sum returns and check if we should move avg window to 2/3rd of current window
        //only before the odd trade
        /*if (!superData->lastSignalOdd && superData->returns.size() >= MIN_RETURNS_IN_CALCULATION) {
            
            int thirdOfReturnWindow = superData->returnsInCalculation / 3;
            
            double recentThirdSumRt = 0.0;
            double firstThirdSumRt = 0.0;
            for (unsigned long i = superData->returns.size() - thirdOfReturnWindow; i < superData->returns.size(); i++) {
                recentThirdSumRt += superData->returns[i];
            }
            for (unsigned long i = 0; i < thirdOfReturnWindow; i++) {
                firstThirdSumRt += superData->returns[i];
            }
            
            double currentThirdChangePercent = recentThirdSumRt / firstThirdSumRt - 1.0;
            if (currentThirdChangePercent > RETURNS_DIFFERENCE_PERCENT || currentThirdChangePercent < -RETURNS_DIFFERENCE_PERCENT) {
                superData->returnsInCalculation = thirdOfReturnWindow * 2;
            }
            
        }*/
        
        /*if (superData->returns.size() >= MIN_RETURNS_IN_CALCULATION) {
            //calculate threshold based on max and min and avg in returns window
            double wTotalPrice = 0.0;
            double wMinPrice = 0.0, wMaxPrice = 0.0;
            for (unsigned long i = superData->priceAtReturn.size() - superData->returnsInCalculation; i < superData->priceAtReturn.size(); i++) {
                double thisPrice = superData->priceAtReturn[i];
                wTotalPrice += thisPrice;
                if (i == superData->priceAtReturn.size() - superData->returnsInCalculation) {
                    //first price
                    wMinPrice = thisPrice;
                    wMaxPrice = thisPrice;
                } else {
                    if (thisPrice > wMaxPrice) {
                        wMaxPrice = thisPrice;
                    }
                    if (thisPrice < wMinPrice) {
                        wMinPrice = thisPrice;
                    }
                }
            }
            double wAvgPrice = wTotalPrice / superData->returnsInCalculation;
            if (enableBuyTrades) {
                superData->threshold = THRESHOLD_PERCENT_RANGE * ((wMaxPrice - wAvgPrice) / wAvgPrice);
            } else {
                superData->threshold = THRESHOLD_PERCENT_RANGE * ((wAvgPrice - wMinPrice) / wAvgPrice);
            }
            cout << superData->threshold << "\n";
        }*/
        
        
        bool forcedTradeMade = false;
        
        //manage the risk for allowance only on the even trade
        if (superData->lastSignalOdd && (superData->previousSignal == __BUY_SIGNAL || superData->previousSignal == __SELL_SIGNAL)) {
            
            double tradeDirection = (superData->previousSignal == __SELL_SIGNAL) ? -1.0 : 1.0;
            
            double negativePriceMovement = superData->previousPriceOnSignal / thisPrice - 1.0;
            
            //if (tradeDirection * negativePriceMovement > EQUITY_LOSS_PERCENT_ALLOWANCE
            //|| ( tradeDirection*(superData->previousPriceOnSignal - superData->previousPrice) > 0.0
            //&& tradeDirection*(superData->previousPrice - thisPrice) > 0.0 )) {
            
            if (tradeDirection * negativePriceMovement > EQUITY_LOSS_PERCENT_ALLOWANCE) {
                    
                forcedTradeMade = true;
                if (superData->previousSignal == __BUY_SIGNAL) {
                    super::nextTradeDay(tradeDay, enableBuyTrades, enableSellTrades, 0.0, __SELL_SIGNAL);
                } else {
                    super::nextTradeDay(tradeDay, enableBuyTrades, enableSellTrades, 0.0, __BUY_SIGNAL);
                }
                
            }
                
            
            
        }
        
        bool madeTrade = forcedTradeMade;
        
        if (!forcedTradeMade) {
            //biased based on threshold and influences
            double threshBias = superData->threshold * influences.tradeDayInfluence(tradeDay);
            int signal = super::nextTradeDay(tradeDay, enableBuyTrades, enableSellTrades, threshBias, -1);
            madeTrade = (madeTrade || signal == __BUY_SIGNAL || signal == __SELL_SIGNAL);
        }
        
        if (madeTrade) {
            superData->returnsInCalculation = (int)((double)superData->lastTradeDaysAgo * RETURNS_WINDOW_MOD);
            if (superData->returnsInCalculation < MIN_RETURNS_IN_CALCULATION) {
                superData->returnsInCalculation = MIN_RETURNS_IN_CALCULATION;
            }
        }
    }
    
    
}




