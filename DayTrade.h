// Author: Pavan Kumar Paluri
// Day Trade Class and it's Method Inits
#include<iostream>
#include<string>
#include<map>
using namespace std;
#ifndef QUANTLAB_INTERVIEW_DAYTRADE_H
#define QUANTLAB_INTERVIEW_DAYTRADE_H
class Day_trade {
private:
    // the basic params of trade: <timestamp>, <symbol>, <price>, <Qty>
    unsigned long timeStamp;
    const string symbol;
    unsigned long price;
    unsigned long qty;

public:
    // Retreive the params with inline function defns
    unsigned long get_timeStamp() const {return this->timeStamp;}
    string get_symbol() const {return this->symbol;}
    unsigned long get_price() const {return this->price;}
    unsigned long get_qty() const {return this->qty;}


    // Constructor
    Day_trade(unsigned long, string&, unsigned long, unsigned long);
    // Destructor
    ~Day_trade() = default;
};
#endif
