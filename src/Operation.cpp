#include <Operation.h>

#include <utils.h>

void to_json(Json& j, const Operation& operation) {
    try {
        j = Json {
                    {"id", operation.id},
                    {"status", toString(operation.status)},
                    {"currency", toString(operation.currency)},
                    {"payment", std::to_string(operation.payment)},
                    {"isMarginCall", std::to_string(operation.isMarginCall)},
                    {"date", toString(operation.date)},
                };

        if (operation.trades) {
            j.push_back({"trades", *operation.trades});
        }

        if (operation.commission) {
            j.push_back({"commission", *operation.commission});
        }

        if (operation.price) {
            j.push_back({"price", std::to_string(*operation.price)});
        }

        if (operation.quantity) {
            j.push_back({"quantity", std::to_string(*operation.quantity)});
        }

        if (operation.quantityExecuted) {
            j.push_back({"quantityExecuted", std::to_string(*operation.quantityExecuted)});
        }

        if (operation.figi) {
            j.push_back({"figi", *operation.figi});
        }

        if (operation.instrumentType) {
            j.push_back({"trades", toString(*operation.instrumentType)});
        }

        if (operation.operationType) {
            j.push_back({"operationType", toString(*operation.operationType)});
        }
    }
    catch(...) {
        std::string message = "Impossible to parse Operation to JSON";
        throw message;
    }
}

void from_json(const Json& j, Operation& operation) {
    try {
        j.at("id").get_to(operation.id);
        operation.status = toOperationStatus(j.at("status"));

        operation.currency = toCurrency(j.at("currency"));

        j.at("payment").get_to(operation.payment);

        j.at("isMarginCall").get_to(operation.isMarginCall);

        operation.date = toDate(j.at("date"));

    
        if (j.contains("trades")) {
            operation.trades = j["trades"].get<std::vector<OperationTrade>>();
        }

        if (j.contains("commission")) {
            operation.commission = j["commission"].get<MoneyAmount>();
        }

        if (j.contains("price")) {
            operation.price = j["price"].get<double>();
        }
        
        if (j.contains("quantity")) {
            operation.quantity = j["quantity"].get<int>();
        }

        if (j.contains("quantityExecuted")) {
            operation.quantityExecuted = j["quantityExecuted"].get<int>();
        }
    
        if (j.contains("figi")) {
            operation.figi = j["figi"].get<std::string>();
        }

        if (j.contains("instrumentType")) {
            operation.instrumentType = toInstrumentType(j["instrumentType"]);
        }

        if (j.contains("operationType")) {
            operation.operationType = toOperationTypeWithCommission(j["operationType"]);
        }
    }
    catch(std::string error) {
        throw error;
    }
    catch(...) {
        std::string message = "Impossible to parse JSON to Operation structure";
        throw message;
    }
}

bool operator==(const Operation& lhs, const Operation& rhs) {
    if ((*lhs.trades).size() != (*rhs.trades).size()) {
        return false;
    }

    for (size_t i = 0; i < (*lhs.trades).size(); ++i) {
        if (!((*lhs.trades)[i] == (*rhs.trades)[i])) {
            return false;
        }
    }

    return  lhs.id == rhs.id && lhs.figi == rhs.figi &&
            lhs.status == rhs.status && lhs.commission == rhs.commission &&
            lhs.currency == rhs.currency && lhs.payment == rhs.payment &&
            lhs.price == rhs.price && lhs.quantity == rhs.quantity &&
            lhs.quantityExecuted == rhs.quantityExecuted && 
            lhs.instrumentType == rhs.instrumentType && 
            lhs.isMarginCall == rhs.isMarginCall && lhs.date == rhs.date &&
            lhs.operationType == rhs.operationType;
}