#pragma once

#include <nlohmann/json.hpp>



struct OrderResponse {
    double price;
    int quantity;
};


void to_json(nlohmann::json&, const OrderResponse&);
void from_json(const nlohmann::json&, OrderResponse&);

bool operator==(const OrderResponse&, const OrderResponse&);