#pragma once

#include <CandleInterval.h>

#include <string>
#include <ctime>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

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

void to_json(Json&, const Candle&);
void from_json(const Json&, Candle&);

bool operator==(const Candle&, const Candle&);