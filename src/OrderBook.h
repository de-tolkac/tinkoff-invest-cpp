#pragma once

#include <OrderResponse.h>
#include <TradeStatus.h>

#include <string>
#include <vector>

struct OrderBook {
    std::string figi;

    int depth;

    std::vector<OrderResponse> bids;
    std::vector<OrderResponse> asks;

    TradeStatus tradeStatus;

    double minPriceIncrement;
    double faceValue;
    double lastPrice;
    double closePrice;
    double limitUp;
    double limitDown;    
};