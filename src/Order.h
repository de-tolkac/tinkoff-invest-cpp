#pragma once

#include <OperationType.h>
#include <OrderStatus.h>
#include <OrderType.h>
#include <utils.h>

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

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

void to_json(Json&, const Order&);
void from_json(const Json&, Order&);

typedef std::vector<Order> OrderList;