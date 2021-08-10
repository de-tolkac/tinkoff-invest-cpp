#include <Order.h>

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

        if (j.at("operation") == "Buy") {
            order.operation = OperationType::Buy;
        } else if (j.at("operation")  == "Sell") {
            order.operation = OperationType::Sell;
        } else {
            std::string message = "Invalid Response (Invalid Operation Type - \"";
            message += j.at("operation");
            message += "\")";

            throw message;
        }

        try {
            order.status = toOrderStatus(j.at("status"));
        } catch (...) {
            std::string message = "Invalid Response (Invalid Order Status - \"";
            message += j.at("status");
            message += "\")";

            throw message;
        }

        try {
            order.requestedLots = std::stoi(j.at("requestedLots").get<std::string>());
        } catch(...) {
            std::string message = "Invalid Response (Invalid requestedLots number - \"";
            message += j.at("requestedLots");
            message += "\")";

            throw message;
        }

        try {
            order.executedLots = std::stoi(j.at("executedLots").get<std::string>());
        } catch(...) {
            std::string message = "Invalid Response (Invalid executedLots number - \"";
            message += j.at("executedLots");
            message += "\")";

            throw message;
        }

        if (j.at("type") == "Limit") {
            order.type = OrderType::Limit;
        } else if (j.at("type") == "Market") {
            order.type = OrderType::Market;
        } else {
            std::string message = "Invalid Response (Invalid Order Type - \"";
            message += j.at("type");
            message += "\")";

            throw message;
        }

        try {
            order.price = std::stod(j.at("price").get<std::string>());
        } catch(...) {
            std::string message = "Invalid Response (Invalid Price - \"";
            message += j.at("price");
            message += "\")";

            throw message;;
        }
    } 
    catch(std::string error) {
        throw error;
    } 
    catch(...) {
        std::string message = "Invalid Response. It is impossible to parse JSON";

        throw message;
    }
}