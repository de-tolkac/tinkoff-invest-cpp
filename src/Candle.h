#pragma once

#include <CandleInterval.h>

#include <string>
#include <ctime>

#include <nlohmann/json.hpp>

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

void to_json(nlohmann::json&, const Candle&);
void from_json(const nlohmann::json&, Candle&);

bool operator==(const Candle&, const Candle&);

using CandleList = std::vector<Candle>;