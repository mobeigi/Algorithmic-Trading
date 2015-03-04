//
//  main.cpp
//  Algorithmic Trading COMP3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "GlobalIncludes.h"

#include <iostream>

#include <ifstream>
#include <vector>

#include "MomentumStrategy.h"
#include "Logger.h"
#include "TradeDay.h"


void test() {
    std::Logger logger = std::Logger::standardLogger();
    std::vector<std::TradeDay> trades = {
        std::TradeDay(30.0),
        std::TradeDay(30.34),
        std::TradeDay(30.71),
        std::TradeDay(31.09),
        std::TradeDay(31.29),
        std::TradeDay(31.54),
        std::TradeDay(31.76),
        std::TradeDay(31.98),
        std::TradeDay(32.58)};
    std::StrategyResult result = std::MomentumStrategy(logger, trades, 3).execute();
    logger.log(result.description());
}

int main(int argc, const char * argv[]) {
    test();

   //  std::ifstream d;
   //  std::string m, b;
   //  std::vector<std::string> c;
   //  std::vector<std::vector<std::string> > t;
   //  d.open("BHP_Daily_Since2000.csv");
   //  if(d.is_open()) {
   //       while(getline(d, m)) {
   //             if(m.at(0) == '#') continue;
   //             for(unsigned i = 0; i < m.length(); ++i) {
   //                   if(m[i] != ',' && i + 1 != m.length()) {
   //                         b += m[i];
   //                   } else {
   //                         c.push_back(b);
   //                         b = "";
   //                   }
   //             }
   //             t.push_back(c);
   //       }
   // }
   // d.close();
   // for(unsigned n = 0; n != t.size(); n++) {
   //       c = t.at(n);
   //       for(unsigned o = 0; o != c.size(); o++) {
   //             if(c.at(o).empty()) std::cout << "(null)" << '\n';
   //             else std::cout << c.at(o) << '\n';
   //       }
   // }


    return 0;
}
