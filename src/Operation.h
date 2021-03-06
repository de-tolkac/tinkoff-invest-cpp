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
#include <optional>

#include <nlohmann/json.hpp>

namespace ti {

struct Operation {
    std::string id;

    OperationStatus status;

    Currency currency;

    double payment;

    bool isMarginCall;

    time_t date;


    std::optional<std::vector<OperationTrade>> trades;
    std::optional<MoneyAmount> commission;
    std::optional<double> price;
    std::optional<int> quantity;
    std::optional<int> quantityExecuted;
    std::optional<std::string> figi;
    std::optional<InstrumentType> instrumentType;
    std::optional<OperationTypeWithCommission> operationType;

    Operation();
};

void to_json(nlohmann::json&, const Operation&);
void from_json(const nlohmann::json&, Operation&);

bool operator==(const Operation&, const Operation&);

using OperationList = std::vector<Operation>;

}