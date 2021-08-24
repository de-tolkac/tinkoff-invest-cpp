#pragma once

#include <PortfolioPosition.h>
#include <CurrencyPosition.h>

#include <vector>

namespace ti {

struct PortfolioInfo {
    std::vector<PortfolioPosition> positions;
    std::vector<CurrencyPosition> currencies;
};

bool operator==(const PortfolioInfo&, const PortfolioInfo&);

}