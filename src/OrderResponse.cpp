#include <OrderResponse.h>

#include <string>

void to_json(Json& j, const OrderResponse& orderResponse) {
    j = Json {
                {"price", std::to_string(orderResponse.price)},
                {"quantity", std::to_string(orderResponse.quantity)}
             };
}

void from_json(const Json& j, OrderResponse& orderResponse) {
    try {
        j.at("price").get_to(orderResponse.price);
        j.at("quantity").get_to(orderResponse.quantity);
    }
    catch(...) {
        std::string message = "Impossible to parse JSON to OrderResponse structure";
        throw message;
    }
}

bool operator==(const OrderResponse& lhs, const OrderResponse& rhs) {

}