#pragma once

#include <Currency.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

struct MoneyAmount {
    Currency currency;
    double value;
};

void to_json(Json&, const MoneyAmount&);
void from_json(const Json&, MoneyAmount&);

bool operator==(const MoneyAmount&, const MoneyAmount&);