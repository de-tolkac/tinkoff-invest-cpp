#include <gtest/gtest.h>

#include <Order.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

using namespace ti;

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

TEST(json_test, Order_Exception_orderId) {
    Json j = R"(
        {
            "figi": "testFIGI123",
            "operation": "Buy",
            "status": "New",
            "requestedLots": 10,
            "executedLots": 255,
            "type": "Limit",
            "price": 1000.2
        }
    )"_json;

    ASSERT_THROW(j.get<Order>(), std::string);
}

TEST(json_test, Order_Exception_figi) {
    Json j = R"(
        {
            "orderId": "testId",
            "operation": "Buy",
            "status": "New",
            "requestedLots": 10,
            "executedLots": 255,
            "type": "Limit",
            "price": 1000.2
        }
    )"_json;

    ASSERT_THROW(j.get<Order>(), std::string);
}

TEST(json_test, Order_Exception_operation) {
    Json j = R"(
        {
            "orderId": "testId",
            "figi": "testFIGI123",
            "status": "New",
            "requestedLots": 10,
            "executedLots": 255,
            "type": "Limit",
            "price": 1000.2
        }
    )"_json;

    ASSERT_THROW(j.get<Order>(), std::string);
}

TEST(json_test, Order_Exception_status) {
    Json j = R"(
        {
            "orderId": "testId",
            "figi": "testFIGI123",
            "operation": "Buy",
            "requestedLots": 10,
            "executedLots": 255,
            "type": "Limit",
            "price": 1000.2
        }
    )"_json;

    ASSERT_THROW(j.get<Order>(), std::string);
}

TEST(json_test, Order_Exception_requestedLots) {
    Json j = R"(
        {
            "orderId": "testId",
            "figi": "testFIGI123",
            "operation": "Buy",
            "status": "New",
            "executedLots": 255,
            "type": "Limit",
            "price": 1000.2
        }
    )"_json;

    ASSERT_THROW(j.get<Order>(), std::string);
}

TEST(json_test, Order_Exception_executedLots) {
    Json j = R"(
        {
            "orderId": "testId",
            "figi": "testFIGI123",
            "operation": "Buy",
            "status": "New",
            "requestedLots": 10,
            "type": "Limit",
            "price": 1000.2
        }
    )"_json;

    ASSERT_THROW(j.get<Order>(), std::string);
}

TEST(json_test, Order_Exception_type) {
    Json j = R"(
        {
            "orderId": "testId",
            "figi": "testFIGI123",
            "operation": "Buy",
            "status": "New",
            "requestedLots": 10,
            "executedLots": 255,
            "price": 1000.2
        }
    )"_json;

    ASSERT_THROW(j.get<Order>(), std::string);
}

TEST(json_test, Order_Exception_price) {
    Json j = R"(
        {
            "orderId": "testId",
            "figi": "testFIGI123",
            "operation": "Buy",
            "status": "New",
            "requestedLots": 10,
            "executedLots": 255,
            "type": "Limit"
        }
    )"_json;

    ASSERT_THROW(j.get<Order>(), std::string);
}