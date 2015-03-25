//
//  CSVWriter.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "CSVWriter.h"

namespace std {
      CSVWriter::CSVWriter() {
            csvData.push_back("#Company, Date, Price, Volume, Value, Signal\n");
            isOpen = true;
      }
      void CSVWriter::addCSVLine(string companyName, string date, double price, char signal) {
            if(isOpen) {
                  stringstream ss;
                  ss << companyName << __CSV_DELIM;
                  ss << date << __CSV_DELIM;
                  ss << price << __CSV_DELIM;
                  ss << 100 << __CSV_DELIM;
                  ss << 100 * price << __CSV_DELIM;
                  ss << signal << endl;
                  csvData.push_back(ss.str());
            }
      }
      CSVWriter::stopWriting() {
            isOpen = false;
      }
      CSVWriter::~CSVWriter() {
            Helper::writeFile("output.csv", csvData);
      }
}
