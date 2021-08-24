#pragma once

#include <InstrumentType.h>
#include <MoneyAmount.h>

#include <string>
#include <optional>

#include <nlohmann/json.hpp>



struct PortfolioPosition {
    std::string figi;
    std::string ticker;
    std::string name;

    InstrumentType instrumentType;

    double balance;

    int lots;

    std::optional<std::string> isin;
    std::optional<double> blocked;
    std::optional<MoneyAmount> expectedYield;
    std::optional<MoneyAmount> averagePositionPrice;
    std::optional<MoneyAmount> averagePositionPriceNoNkd;
};

void to_json(nlohmann::json&, const PortfolioPosition&);
void from_json(const nlohmann::json&, PortfolioPosition&);

bool operator==(const PortfolioPosition&, const PortfolioPosition&);

using PortfolioPositionList = std::vector<PortfolioPosition>;