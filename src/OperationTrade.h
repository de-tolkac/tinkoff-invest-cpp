#pragma once

#include <string>
#include <ctime>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

struct OperationTrade {
    std::string tradeId;

    time_t date;

    double price;

    int quantity;
};

void to_json(Json&, const OperationTrade&);
void from_json(const Json&, OperationTrade&);

bool operator==(const OperationTrade&, const OperationTrade&);