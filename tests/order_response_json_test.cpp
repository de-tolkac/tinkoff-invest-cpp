#include <gtest/gtest.h>

#include <OrderResponse.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

TEST(json_test, OrderResponse_get) {
    Json j = R"(
        {
            "price": 1000,
            "quantity": 10000000
        }
    )"_json;

    OrderResponse orderResponse1;
    orderResponse1.price = 1000;
    orderResponse1.quantity = 10000000;

    OrderResponse orderResponse2 = j.get<OrderResponse>();

    ASSERT_EQ(orderResponse1, orderResponse2);
}

TEST(json_test, OrderResponse_Parse) {
    std::string text = R"(
        {
            "price": 1000,
            "quantity": 10000000
        }
    )";

    OrderResponse orderResponse1;
    orderResponse1.price = 1000;
    orderResponse1.quantity = 10000000;

    OrderResponse orderResponse2 = Json::parse(text);

    ASSERT_EQ(orderResponse1, orderResponse2);
}