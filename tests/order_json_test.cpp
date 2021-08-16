#include <gtest/gtest.h>

#include <Order.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

TEST(json_test, Order_get) {
    Json j = R"(
        {
            "orderId": "testId",
            "figi": "testFIGI123",
            "operation": "Buy",
            "status": "New",
            "requestedLots": 10,
            "executedLots": 255,
            "type": "Limit",
            "price": 1000.2
        }
    )"_json;

    Order order1;
    order1.orderId = "testId";
    order1.figi = "testFIGI123";
    order1.operation = OperationType::Buy;
    order1.status = OrderStatus::New;
    order1.requestedLots = 10;
    order1.executedLots = 255;
    order1.type = OrderType::Limit;
    order1.price = 1000.2;

    Order order2 = j.get<Order>();

    ASSERT_EQ(order1, order2);
}

TEST(json_test, Order_Parse) {
    std::string text = R"(
        {
            "orderId": "testId",
            "figi": "testFIGI123",
            "operation": "Buy",
            "status": "New",
            "requestedLots": 10,
            "executedLots": 255,
            "type": "Limit",
            "price": 1000.2
        }
    )";

    Order order1;
    order1.orderId = "testId";
    order1.figi = "testFIGI123";
    order1.operation = OperationType::Buy;
    order1.status = OrderStatus::New;
    order1.requestedLots = 10;
    order1.executedLots = 255;
    order1.type = OrderType::Limit;
    order1.price = 1000.2;

    Order order2 = Json::parse(text);

    ASSERT_EQ(order1, order2);
}