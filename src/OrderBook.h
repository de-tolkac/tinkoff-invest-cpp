#pragma once

#include <OrderResponse.h>
#include <TradeStatus.h>

#include <string>
#include <vector>
#include <optional>

#include <nlohmann/json.hpp>



struct OrderBook {
    std::string figi;

    int depth;

    std::vector<OrderResponse> bids;
    std::vector<OrderResponse> asks;

    TradeStatus tradeStatus;

    double minPriceIncrement;

    std::optional<double> faceValue;
    std::optional<double> lastPrice;
    std::optional<double> closePrice;
    std::optional<double> limitUp;
    std::optional<double> limitDown;    
};

void to_json(nlohmann::json&, const OrderBook&);
void from_json(const nlohmann::json&, OrderBook&);

bool operator==(const OrderBook&, const OrderBook&);