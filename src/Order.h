#pragma once

#include <OperationType.h>
#include <OrderStatus.h>
#include <OrderType.h>

#include <string>

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