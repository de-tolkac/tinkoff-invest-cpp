#pragma once

#include <InstrumentType.h>
#include <MoneyAmount.h>

#include <string>
#include <optional>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

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

void to_json(Json&, const PortfolioPosition&);
void from_json(const Json&, PortfolioPosition&);

bool operator==(const PortfolioPosition&, const PortfolioPosition&);

using PortfolioPositionList = std::vector<PortfolioPosition>;