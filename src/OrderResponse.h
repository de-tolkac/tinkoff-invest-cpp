#pragma once

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

struct OrderResponse {
    double price;
    int quantity;
};


void to_json(Json&, const OrderResponse&);
void from_json(const Json&, OrderResponse&);

bool operator==(const OrderResponse&, const OrderResponse&);