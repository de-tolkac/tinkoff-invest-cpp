#pragma once

#include <string>
#include <ctime>

struct OperationTrade {
    std::string tradeId;

    time_t date;

    double price;

    int quantity;
};