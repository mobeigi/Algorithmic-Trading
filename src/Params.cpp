//
//  Params.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "Params.h"

#define __PARAM_DELIM ((char)0x5C) //"\"
#define __PARAM_ID_START ((char)0x3A) //":"
#define __PARAM_VALUE_START ((char)0x3A) //":"


namespace std {
    
    Params::Params(string paramFileDir, bool *foundFile) : params() {

        ifstream paramFile = ifstream(paramFileDir, ios::in);
        *foundFile = false;
        
        if (paramFile.is_open()) {
            *foundFile = true;
            
            //parsing setup
            bool waitingForIdStart = true; //waiting for initial start character
            bool readingParamId = true;
            bool lastCharWasDelim = false;
            string currentParamId = "";
            string currentParamBody = "";
            
            int ic = paramFile.get();
            while (ic != EOF) {
                char c = (char)ic;
                
                //do nothing in the interum of waiting for start character
                if (waitingForIdStart) {
                    if (c == __PARAM_ID_START) {
                        waitingForIdStart = false;
                        readingParamId = true;
                    }
                    ic = paramFile.get();
                    continue;
                }
            
                if (readingParamId) {
                    if (c == __PARAM_VALUE_START) {
                        readingParamId = false;
                    } else {
                        currentParamId.append(1, c);
                    }
                } else {
                    
                    //delim; double delim = use as character, single = forget, new character after delim then add param
                    if (lastCharWasDelim) {
                        lastCharWasDelim = false;
                        if (c != __PARAM_DELIM) {
                            addParam(currentParamId, currentParamBody);
                            currentParamId = "";
                            currentParamBody = "";
                            waitingForIdStart = true;
                        } else {
                            currentParamBody.append(1, c);
                        }
                    } else if (c == __PARAM_DELIM) {
                        lastCharWasDelim = true;
                       
                    } else {
                        currentParamBody.append(1, c);
                    }
                    
                }
                
                ic = paramFile.get();
            }
            
            //add param at end of file
            if (lastCharWasDelim) {
                addParam(currentParamId, currentParamBody);
            }
            
            paramFile.close();
            
        }
    }
    

    void Params::addParam(string paramId, string paramValue) {
        
        Param param;
        param.isNull = false;
        param.stringVal = paramValue;
        
        //defaults
        param.intVal = -1;
        param.doubleVal = -1;
        param.isNumber = false;
        
        try {
            string::size_type sz;
            double dval = stod(paramValue, &sz);
            param.isNumber = true;
            param.doubleVal = dval;
            param.intVal = static_cast<int>(round(dval));
            
        } catch (invalid_argument) {
        } catch (out_of_range) {}
        
        params[paramId] = param;
    }
    
    
    Param Params::getParam(string paramId) {
        
        if (params.find(paramId) == params.end()) {
            return nullParam();
        }
        
        return params[paramId];
    }
    
    Param Params::nullParam() {
        Param np;
        np.isNull = true;
        return np;
    }


}






