#pragma once

#include <Currency.h>
#include <InstrumentType.h>

#include <string>

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