#pragma once

#include <Currency.h>
#include <InstrumentType.h>

#include <string>
#include <optional>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

struct SearchMarketInstrument {
    std::string figi;
    std::string ticker;
    std::string name;

    int lot;

    InstrumentType type;

    std::optional<std::string> isin;
    std::optional<double> minPriceIncrement;
    std::optional<Currency> currency;
};

void to_json(Json&, const SearchMarketInstrument&);
void from_json(const Json&, SearchMarketInstrument&);

bool operator==(const SearchMarketInstrument&, const SearchMarketInstrument&);