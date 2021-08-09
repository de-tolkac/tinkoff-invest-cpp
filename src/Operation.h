#pragma once

#include <OperationStatus.h>
#include <OperationTrade.h>
#include <MoneyAmount.h>
#include <Currency.h>
#include <InstrumentType.h>
#include <OperationTypeWithCommission.h>

#include <string>
#include <vector>
#include <ctime>

struct Operation {
    std::string id;
    std::string figi;

    OperationStatus status;

    std::vector<OperationTrade> trades;

    MoneyAmount commission;

    Currency currency;

    double payment;
    double price;

    int quantity;
    int quantityExecuted;

    InstrumentType instrumentType;

    bool isMarginCall;

    time_t date;

    OperationTypeWithCommission operationType;
};