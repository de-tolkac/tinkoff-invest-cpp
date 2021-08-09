#pragma once

#include <CandleInterval.h>

#include <string>
#include <ctime>

struct Candle {
    std::string figi;
    
    CandleInterval interval;

    double openPrice;
    double closePrice;
    double highPrice;
    double lowPrice;
    double volume;

    time_t time;
};
