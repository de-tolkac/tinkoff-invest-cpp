#pragma once

#include <InstrumentType.h>
#include <MoneyAmount.h>

#include <string>

struct PortfolioPosition {
    std::string figi;
    std::string ticker;
    std::string isin;

    InstrumentType instrumentType;

    double balance;
    double blocked;

    MoneyAmount expectedYield;

    int lots;

    MoneyAmount averagePositionPrice;
    MoneyAmount averagePositionPriceNoNkd;

    std::string name;
};