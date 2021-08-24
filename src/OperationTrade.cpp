#include <OperationTrade.h>

#include <utils.h>

using Json = nlohmann::json;

namespace ti {

void to_json(Json& j, const OperationTrade& op) {
    try {
        j = Json {
                    {"tradeId", op.tradeId},
                    {"date", toString(op.date)},
                    {"price", std::to_string(op.price)},
                    {"quantity", std::to_string(op.quantity)}
                 };
    }
    catch(...) {
        std::string message = "Impossible to parse OperationTrade to JSON";
        throw message;
    }
}
void from_json(const Json& j, OperationTrade& op) {
    try {
        j.at("tradeId").get_to(op.tradeId);
        j.at("price").get_to(op.price);
        j.at("quantity").get_to(op.quantity);
        
        op.date = toDate(j.at("date"));
    }
    catch(std::string& error) {
        throw error;
    }
    catch(...) {
        std::string message = "Impossible to parse JSON to OperationTrade structure";
        throw message;
    }
}

bool operator==(const OperationTrade& lhs, const OperationTrade& rhs) {
    return  lhs.tradeId == rhs.tradeId && lhs.date == rhs.date &&
            lhs.price == rhs.price && lhs.quantity == rhs.quantity;
}

}