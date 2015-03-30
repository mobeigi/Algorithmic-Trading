//
//  CSVWriter.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "CSVWriter.h"

namespace std {
      CSVWriter::CSVWriter() {}
      void CSVWriter::startWriting(string fileName) {
            output = ofstream(fileName, ios::trunc);
            if(output.is_open()) {
                  output << "#Company, Date, Price, Volume, Value, Signal" << endl;
                  isOpen = true;
            }
      }
      void CSVWriter::addCSVLine(string companyName, string date, double price, char signal) {
            if(isOpen) {
                  stringstream ss;
                  ss << companyName << __CSV_DELIM;
                  ss << date << __CSV_DELIM;
                  ss << setprecision(2) << std::fixed << price << __CSV_DELIM;
                  ss << 100 << __CSV_DELIM;
                  ss << setprecision(2) << std::fixed << 100 * price << __CSV_DELIM;
                  ss << signal;
                  output << ss.str() << endl;
            }
      }
      void CSVWriter::stopWriting() {
            if(isOpen) output.close();
            isOpen = false;
      }
}
