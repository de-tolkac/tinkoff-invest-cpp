#pragma once 

#include <OperationType.h>
#include <OrderStatus.h>
#include <MoneyAmount.h>

#include <string>
#include <optional>

#include <nlohmann/json.hpp>



struct PlacedOrder {
    std::string orderId;

    OperationType operation;
    OrderStatus status;

    int requestedLots;
    int executedLots;

    std::optional<std::string> rejectReason;
    std::optional<std::string> message;
    std::optional<MoneyAmount> commission;
};

void to_json(nlohmann::json&, const PlacedOrder&);
void from_json(const nlohmann::json&, PlacedOrder&);

bool operator==(const PlacedOrder&, const PlacedOrder&);