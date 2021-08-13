#pragma once

#include <Currency.h>
#include <InstrumentType.h>

#include <string>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

struct MarketInstrument {
    std::string figi;
    std::string ticker;
    std::string isin;
    std::string name;

    double minPriceIncrement;

    int lot;
    int minQuantity;

    Currency currency;

    InstrumentType type;
};

void to_json(Json&, const MarketInstrument&);
void from_json(const Json&, MarketInstrument&);

bool operator==(const MarketInstrument&, const MarketInstrument&);