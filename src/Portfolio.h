#pragma once

#include <PortfolioPosition.h>
#include <CurrencyPosition.h>

#include <vector>

struct PortfolioInfo {
    std::vector<PortfolioPosition> positions;
    std::vector<CurrencyPosition> currencies;
};