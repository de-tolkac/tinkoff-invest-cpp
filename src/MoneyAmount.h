#pragma once

#include <Currency.h>

#include <nlohmann/json.hpp>


struct MoneyAmount {
    Currency currency;
    double value;
};

void to_json(nlohmann::json&, const MoneyAmount&);
void from_json(const nlohmann::json&, MoneyAmount&);

bool operator==(const MoneyAmount&, const MoneyAmount&);