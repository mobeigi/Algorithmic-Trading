#ifndef QUANTPARA_H
#define QUANTPARA_H

#include "GlobalIncludes.h"

#include <string>

//use the static objects paraReturns, paraGranality and paraVolatility
/*
 * Raw Values:
 * paraReturns - % made in returns
 * paraGranality - average days between each trade
 * paraVolatility - sum number of gains minus the sum number of times loss occured (using pairs)
 * */

namespace std
{

class QuantPara
{
private:
    string paramName;
protected:
    QuantPara(string paramName);
public:
    ~QuantPara();
    string getName();
    virtual double calculateParam(double rawVal, double max, double min, double avg);
};

class ParaReturns : public QuantPara
{
public:
    ParaReturns();
    virtual double calculateParam(double rawVal, double max, double min, double avg);
};

class ParaGranality : public QuantPara
{
public:
    ParaGranality();
    virtual double calculateParam(double rawVal, double max, double min, double avg);
};

class ParaVolatility : public QuantPara
{
public:
    ParaVolatility();
    virtual double calculateParam(double rawVal, double max, double min, double avg);
};

static ParaReturns* paraReturns = new ParaReturns();
static ParaGranality* paraGranality = new ParaGranality();
static ParaVolatility* paraVolatility = new ParaVolatility();

}

#endif // QUANTPARA_H
