#pragma once

#include <optional>

#include <Currency.h>

#include <nlohmann/json.hpp>

namespace ti {

struct CurrencyPosition {
    Currency currency;

    double balance;
    std::optional<double> blocked;
};

void to_json(nlohmann::json&, const CurrencyPosition&);
void from_json(const nlohmann::json&, CurrencyPosition&);

bool operator==(const CurrencyPosition&, const CurrencyPosition&);

using CurrencyPositionList = std::vector<CurrencyPosition>;

}