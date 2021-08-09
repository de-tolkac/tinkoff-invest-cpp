#pragma once 

#include <OperationType.h>
#include <OrderStatus.h>
#include <MoneyAmount.h>

#include <string>

struct PlacedMarketOrder {
    std::string orderId;

    OperationType operation;
    OrderStatus status;

    std::string rejectReason;
    std::string message;

    int requestedLots;
    int executedLots;

    MoneyAmount commission;
};