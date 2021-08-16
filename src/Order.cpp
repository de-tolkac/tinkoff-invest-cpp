#include <Order.h>

#include <utils.h>

void to_json(Json& j, const Order& order) {
    j = Json {
                {"orderId", order.orderId},
                {"figi", order.figi},
                {"operation", toString(order.operation)},
                {"status", toString(order.status)},
                {"requestedLots", std::to_string(order.requestedLots)},
                {"executedLots", std::to_string(order.executedLots)},
                {"type", toString(order.type)},
                {"price", std::to_string(order.price)}
             };
}

void from_json(const Json& j, Order& order) {
    try {
        j.at("orderId").get_to(order.orderId);
        j.at("figi").get_to(order.figi);
        j.at("requestedLots").get_to(order.requestedLots);
        j.at("executedLots").get_to(order.executedLots);
        j.at("price").get_to(order.price);

        order.operation = toOperationType(j.at("operation"));
        order.status = toOrderStatus(j.at("status"));
        order.type = toOrderType(j.at("type"));
    }
    catch(std::string error) {
        throw error;
    } 
    catch(...) {
        std::string message = "Impossible to parse JSON to Order structure";
        throw message;
    }
}

bool operator==(const Order& lhs, const Order& rhs) {
    return  lhs.orderId == rhs.orderId && lhs.figi == rhs.figi && 
            lhs.operation == rhs.operation && lhs.status == rhs.status &&
            lhs.requestedLots == rhs.requestedLots && lhs.executedLots == rhs.executedLots &&
            lhs.type == rhs.type && lhs.price == rhs.price;
}