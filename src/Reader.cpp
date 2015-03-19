#include "Reader.h"

#include <ifstream>
namespace std {
      Reader::Reader(string dataFile) {
            at = 0;
            ifstream dataFile = ifstream(dataFile, ios::in);
            if(dataFile.is_open()) {
                  while(getline(dataFile, line)) {
                        file.push_back(line);
                  }
            }
      }
      bool Reader::nextTrade() {
            if(at != file.size()) {
                  at = at + 1;
                  return true;
            }
            return false;
      }
      vector<string> Reader::getTrade() {
            vector<string> temp;
            line = file.at(at);
            for(unsigned i = 0; i < line.length(); i++) {
                  unsigned b = i;
                  for(; line[i] != ',' && i + 1 != line.length(); i++);
                  temp.push_back(line.substr(b, i - b));
            }
            return temp;
      }
}
