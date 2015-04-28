//
//  TrockEquityDataGen.c
//  TrockEquityDataGen
//
//  Created by Samuel Whitton on 28/04/2015.
//  Copyright (c) 2015 Trock. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define IS_TRUE(__b) (__b == TRUE)

#define START_RAND srand((unsigned)time(NULL))
#define RANDOM_PERCENT ((double)(rand() % 10000) / 9999.0) //granality hack for better pseudo random variances each run

#define RANDOM_VARIENCE ((RANDOM_PERCENT - 0.5)*2.0)

#define LOWEST_PRICE 10.0
#define HIGHEST_PRICE 1000.0
#define RANDOM_PRICE_LOW 50.0
#define RANDOM_PRICE_HIGH 499.0

#define PERCENTAGE_NO_TRADES 0.1

#define CSV_TITLES "#RIC,Date[L],Time[L],Type,Qualifiers,Open,High,Low,Last,Volume,Open Interest,Settle,Data Source"
#define OPEN_DEFAULT 1.0
#define HIGH_DEFAULT 1.0
#define LOW_DEFAULT 1.0
#define VOLUME_DEFAULT 100000

#define APPLY_VARIENCE(__value,__max_varience) (__value * ((RANDOM_VARIENCE * __max_varience) + 1.0))
#define BOUND_PRICE(__price) (__price > HIGHEST_PRICE ? HIGHEST_PRICE : (__price < LOWEST_PRICE ? LOWEST_PRICE : __price)) //within highest and lowest bounds

//trend definitions
#define SPIKE_CHANCE 0.01
#define SPIKE_MAX_MAGNITUDE 0.5
#define MAX_TREND_VARIENCE 0.5
#define MAX_TREND_MAGNITUDE 0.05
#define TREND_DAYS_MIN 3
#define TREND_DAYS_MAX 20
#define MEDIAN_PRICE_TREND_BIAS_MAGNITUDE 0.3
#define COMPANY_PRODUCTIVITY 0.1


typedef int bool;

typedef struct _date {
    int day;
    int month;
    int year;
} Date;



int daysInMonth(int month, int year) {
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

Date addDays(Date date, int days) {
    //hopefull we are not adding many days...
    for (int i = 0; i != days; ++i) {
        date.day++;
        if (date.day > daysInMonth(date.month, date.year)) {
            date.day = 1;
            date.month++;
            if (date.month > 12) {
                date.month = 1;
                date.year++;
            }
        }
    }
    return date;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    
    char *months[13] = {"","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    
    bool hasFileOut = FALSE;
    FILE *file = stdout; //default
    
    if (argc == 6) {
        file = fopen(argv[5], "w");
        hasFileOut = TRUE;
        
        if (file == NULL) {
            printf("Can't open output file: %s\n", argv[5]);
            return 1;
        }
        
    } else if (argc != 5) {
        
        printf("usage: %s [num trades] [starting day] [starting month] [starting year] [optional output file]\n", argv[0]);
        return 1;
    }
    
    
    Date currDate;
    currDate.day = atoi(argv[2]);
    currDate.month = atoi(argv[3]);
    currDate.year = atoi(argv[4]);
    
    if (currDate.day < 1 || currDate.month < 1
        || currDate.year < 1 || currDate.month > 12) {
        printf("Incorrect date: %s %s %s\n", argv[2], argv[3], argv[4]);
        return 1;
    }
    
    
    fprintf(file, CSV_TITLES "\n");
    
    START_RAND;
    
    double firstPrice = RANDOM_PERCENT * (RANDOM_PRICE_HIGH - RANDOM_PRICE_LOW)
    + RANDOM_PRICE_LOW; //core of trend bias so we dont have a fatalistic model (all companies must die)
    
    int currentTrendDaysLeft = 0;
    double currentTrend = 0;
    double lastPrice = firstPrice;
    
    int numDays = atoi(argv[1]);
    for (int i = 0; i < numDays; ++i) {
        
        if (RANDOM_PERCENT < PERCENTAGE_NO_TRADES) {
            fprintf(file, "MEMPHISC,%d-%s-%d,,End Of Day,No Trades,,,,,,,,Verified\n", currDate.day, months[currDate.month], currDate.year);
        } else {
            
            //calculate next price
            
            double thisPrice = lastPrice;

            if (RANDOM_PERCENT < SPIKE_CHANCE) {
                //spike happened!
                thisPrice = APPLY_VARIENCE(lastPrice, SPIKE_MAX_MAGNITUDE);
                
            } else {
                if (currentTrendDaysLeft <= 0) {
                    //new trend
                    double trendBias = -(lastPrice / firstPrice - 1.0) * MEDIAN_PRICE_TREND_BIAS_MAGNITUDE;
                    if (trendBias < COMPANY_PRODUCTIVITY)
                        trendBias = COMPANY_PRODUCTIVITY; //dont accelerate death!
                    
                    //printf("Bias: %lf\n", trendBias);
                    
                    currentTrendDaysLeft = TREND_DAYS_MIN + (TREND_DAYS_MAX - TREND_DAYS_MIN) * RANDOM_PERCENT;
                    currentTrend = MAX_TREND_MAGNITUDE * RANDOM_VARIENCE + trendBias;
                }
                //continue trend
                currentTrendDaysLeft--;
                thisPrice = (APPLY_VARIENCE(lastPrice, APPLY_VARIENCE(currentTrend, MAX_TREND_VARIENCE)));
            }
            
            thisPrice = BOUND_PRICE(thisPrice);
            
            fprintf(file, "MEMPHISC,%d-%s-%d,,End Of Day,,%lf,%lf,%lf,%lf,%d,,,Verified\n", currDate.day, months[currDate.month], currDate.year, OPEN_DEFAULT, HIGH_DEFAULT, LOW_DEFAULT, thisPrice, VOLUME_DEFAULT);
            
            lastPrice = thisPrice;
        }
        
        currDate = addDays(currDate, 1);
    }
    
    
    if (IS_TRUE(hasFileOut)) {
        fclose(file);
    }
    
    return 0;
}