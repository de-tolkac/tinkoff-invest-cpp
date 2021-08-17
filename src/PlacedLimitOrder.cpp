#include <PlacedLimitOrder.h>

#include <utils.h>

void to_json(Json& j, const PlacedLimitOrder& order) {
    j = Json {
                {"oderId", order.orderId},
                {"operation", toString(order.operation)},
                {"status", toString(order.status)},
                {"requestedLots", std::to_string(order.requestedLots)},
                {"executedLots", std::to_string(order.executedLots)},
            };

    if (order.rejectReason) {
        j.push_back({"rejectReason", *order.rejectReason});
    }

    if (order.message) {
        j.push_back({"message", *order.message});
    }

    if (order.commission) {
        j.push_back({"commission", *order.commission});
    }
}

void from_json(const Json& j, PlacedLimitOrder& order) {
    try {
        j.at("orderId").get_to(order.orderId);
        j.at("requestedLots").get_to(order.requestedLots);
        j.at("executedLots").get_to(order.executedLots);

        order.operation = toOperationType(j.at("operation"));
        order.status = toOrderStatus(j.at("status"));

        if (j.contains("rejectReason")) {
            order.rejectReason = j["rejectReason"].get<std::string>();
        }

        if (j.contains("message")) {
            order.message = j["message"].get<std::string>();
        }

        if (j.contains("commission")) {
            order.commission = j["commission"].get<MoneyAmount>();
        }
    } 
    catch(std::string error) {
        throw error;
    } 
    catch(...) {
        std::string message = "Impossible to parse JSON to PlacedLimitOrder structure";
        throw message;
    }
}


bool operator==(const PlacedLimitOrder& lhs, const PlacedLimitOrder& rhs) {
    return  lhs.orderId == rhs.orderId && lhs.operation == rhs.operation &&
            lhs.status == rhs.status && lhs.requestedLots == rhs.requestedLots &&
            lhs.executedLots == rhs.executedLots && lhs.rejectReason == rhs.rejectReason &&
            lhs.message == rhs.message && lhs.commission == rhs.commission;
}