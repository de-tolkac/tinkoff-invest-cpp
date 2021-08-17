#pragma once 

#include <OperationType.h>
#include <OrderStatus.h>
#include <MoneyAmount.h>

#include <string>
#include <optional>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;


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

void to_json(Json&, const PlacedOrder&);
void from_json(const Json&, PlacedOrder&);

bool operator==(const PlacedOrder&, const PlacedOrder&);