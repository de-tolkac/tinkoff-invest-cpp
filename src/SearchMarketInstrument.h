#pragma once

#include <Currency.h>
#include <InstrumentType.h>

#include <string>
#include <optional>

#include <nlohmann/json.hpp>

namespace ti {

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

void to_json(nlohmann::json&, const SearchMarketInstrument&);
void from_json(const nlohmann::json&, SearchMarketInstrument&);

bool operator==(const SearchMarketInstrument&, const SearchMarketInstrument&);

}