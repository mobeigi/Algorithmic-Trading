//
//  Reader.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "Reader.h"

namespace std {
      Reader::Reader(string dataFile) {
            at = 0;
            string line;
            ifstream data = ifstream(dataFile, ios::in);
            if(data.is_open()) {
                  while(getline(data, line)) {
                        file.push_back(line);
                  }
            }
      }
      bool Reader::nextTrade() {
            if(at + 1 < file.size()) {
                  at = at + 1;
                  return true;
            }
            return false;
      }
      vector<string> Reader::getTrade() {
            vector<string> temp;
            string line;
            line = file.at(at);
            for(unsigned i = 0; i < line.length(); i++) {
                  unsigned b = i;
                  for(; line[i] != ',' && i + 1 != line.length(); i++);
                  temp.push_back(line.substr(b, i - b));
            }
            return temp;
      }
}
