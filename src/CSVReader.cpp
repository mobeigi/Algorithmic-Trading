//
//  CSVReader.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Trock. All rights reserved.
//

#include "CSVReader.h"

namespace std
{
    
    CSVReader::CSVReader(string dataFile, bool * foundFile) {
        
        file = new ifstream(dataFile, ios::in);
        * foundFile = false;
        hasNextLine = false;
        
        if (file->is_open() && getline(*file, currentLine)) {
            * foundFile = true;
            hasNextLine = true;
        } else {
            if (file->is_open())
                file->close();
            delete file;
            file = nullptr;
        }
    }
    
    bool CSVReader::open() {
        return (file != nullptr && file->is_open());
    }
    
    CSVReader::~CSVReader() {
        stopReading();
    }
    
    bool CSVReader::nextTrade() {
        return hasNextLine;
    }
    
    vector<string> CSVReader::getTrade() {
        
        if (!nextTrade()) return vector<string>();
        
        vector<string> temp;
        string line;
        line = currentLine;
        for(unsigned i = 0; i < line.length(); i++) {
            unsigned b = i;
            for(; line[i] != __CSV_DELIM && i + 1 != line.length(); i++);
            temp.push_back(line.substr(b, i - b));
        }
        
        if ( !(file != nullptr && file->is_open() && getline(*file, currentLine)) ) {
            stopReading(); //close file or no more
        }
        
        return temp;
    }
    
    void CSVReader::stopReading() {
        hasNextLine = false;
        if (file != nullptr) {
            file->close();
            delete file;
            file = nullptr;
        }
        
    }
    
}
