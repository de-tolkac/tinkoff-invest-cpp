#pragma once

#include <Currency.h>
#include <InstrumentType.h>

#include <string>
#include <optional>

#include <nlohmann/json.hpp>

namespace ti {

struct MarketInstrument {
    std::string figi;
    std::string ticker;
    std::string name;

    int lot;

    InstrumentType type;

    std::optional<std::string> isin;
    std::optional<double> minPriceIncrement;
    std::optional<int> minQuantity;
    std::optional<Currency> currency;
};

void to_json(nlohmann::json&, const MarketInstrument&);
void from_json(const nlohmann::json&, MarketInstrument&);

bool operator==(const MarketInstrument&, const MarketInstrument&);

using MarketInstrumentList = std::vector<MarketInstrument>;

}