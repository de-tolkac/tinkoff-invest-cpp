#pragma once

#include <string>
#include <ctime>

#include <nlohmann/json.hpp>



struct OperationTrade {
    std::string tradeId;

    time_t date;

    double price;

    int quantity;
};

void to_json(nlohmann::json&, const OperationTrade&);
void from_json(const nlohmann::json&, OperationTrade&);

bool operator==(const OperationTrade&, const OperationTrade&);