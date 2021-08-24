#pragma once

#include <OperationType.h>
#include <OrderStatus.h>
#include <OrderType.h>

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

namespace ti {

struct Order {
    std::string orderId;
    std::string figi;
    
    OperationType operation;
    OrderStatus status;

    int requestedLots;
    int executedLots;

    OrderType type;

    double price;
};

void to_json(nlohmann::json&, const Order&);
void from_json(const nlohmann::json&, Order&);

bool operator==(const Order&, const Order&);

using OrderList = std::vector<Order>;

}