#include "QuantPara.h"

namespace std
{

QuantPara::QuantPara(string paramName) : paramName(paramName) {

}

QuantPara::~QuantPara() {

}

string QuantPara::getName() {
    return paramName;
}

double QuantPara::calculateParam(double rawVal, double max, double min, double avg) {
    if (rawVal > avg) {
        if (max == avg)
            return 1.0;
        return (rawVal - avg) / (max - avg);
    }
    if (min == avg)
        return -1.0;
    return -((avg - rawVal) / (avg - min));
}

ParaReturns::ParaReturns() : QuantPara("Returns") {}
double ParaReturns::calculateParam(double rawVal, double max, double min, double avg) {
    return QuantPara::calculateParam(rawVal, max, min, avg);
}

ParaGranality::ParaGranality() : QuantPara("Granality") {}
double ParaGranality::calculateParam(double rawVal, double max, double min, double avg) {
    return -QuantPara::calculateParam(rawVal, max, min, avg);
}

ParaVolatility::ParaVolatility() : QuantPara("Volatility") {}
double ParaVolatility::calculateParam(double rawVal, double max, double min, double avg) {
    return QuantPara::calculateParam(rawVal, max, min, avg);
}


}
