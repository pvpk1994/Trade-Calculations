#include <climits>
//
// Created by Pavan Kumar  Paluri  on 3/20/21.
//
// Author: Pavan Kumar Paluri
// DayTrade C++
#include "DayTrade.h"

Day_trade::Day_trade(unsigned long timeSt, string &sym,
                     unsigned long Qty, unsigned long pr): timeStamp(timeSt),
                                                           symbol(sym), price(pr), qty(Qty)
{}

