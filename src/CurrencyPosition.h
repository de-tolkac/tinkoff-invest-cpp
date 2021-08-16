#pragma once

#include <optional>

#include <Currency.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

struct CurrencyPosition {
    Currency currency;

    double balance;
    std::optional<double> blocked;
};

void to_json(Json&, const CurrencyPosition&);
void from_json(const Json&, CurrencyPosition&);

bool operator==(const CurrencyPosition&, const CurrencyPosition&);