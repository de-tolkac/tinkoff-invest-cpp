#pragma once

#include <Currency.h>
#include <InstrumentType.h>

#include <string>

struct SearchMarketInstrument {
    std::string figi;
    std::string ticker;
    std::string isin;
    std::string name;

    double minPriceIncrement;

    int lot;

    Currency currency;

    InstrumentType type;
};