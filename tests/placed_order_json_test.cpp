#include <gtest/gtest.h>

#include <PlacedOrder.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

using namespace ti;

TEST(json_test, PlacedOrder_get) {
    Json j = R"(
        {
            "orderId": "testOrder",
            "operation": "Buy",
            "status": "New",
            "rejectReason": "reject-reason 123",
            "message": "TestMessage",
            "requestedLots": 100,
            "executedLots": 200,
            "commission": {
                "currency": "RUB",
                "value": 100
            }
        }
    )"_json;

    PlacedOrder order1;
    order1.orderId = "testOrder";
    order1.operation = OperationType::Buy;
    order1.status = OrderStatus::New;
    order1.rejectReason = "reject-reason 123";
    order1.message = "TestMessage";
    order1.requestedLots = 100;
    order1.executedLots = 200;
    order1.commission = {Currency::RUB, 100};

    PlacedOrder order2 = j.get<PlacedOrder>();

    ASSERT_EQ(order1, order2);
}

TEST(json_test, PlacedOrder_Parse) {
    std::string text = R"(
        {
            "orderId": "testOrder",
            "operation": "Buy",
            "status": "New",
            "rejectReason": "reject-reason 123",
            "message": "TestMessage",
            "requestedLots": 100,
            "executedLots": 200,
            "commission": {
                "currency": "RUB",
                "value": 100
            }
        }
    )";

    PlacedOrder order1;
    order1.orderId = "testOrder";
    order1.operation = OperationType::Buy;
    order1.status = OrderStatus::New;
    order1.rejectReason = "reject-reason 123";
    order1.message = "TestMessage";
    order1.requestedLots = 100;
    order1.executedLots = 200;
    order1.commission = {Currency::RUB, 100};

    PlacedOrder order2 = Json::parse(text);

    ASSERT_EQ(order1, order2);
}

TEST(json_test, PlacedOrder_Missed_rejectReason) {
    Json j = R"(
        {
            "orderId": "testOrder",
            "operation": "Buy",
            "status": "New",
            "message": "TestMessage",
            "requestedLots": 100,
            "executedLots": 200,
            "commission": {
                "currency": "RUB",
                "value": 100
            }
        }
    )"_json;

    PlacedOrder order1;
    order1.orderId = "testOrder";
    order1.operation = OperationType::Buy;
    order1.status = OrderStatus::New;
    order1.message = "TestMessage";
    order1.requestedLots = 100;
    order1.executedLots = 200;
    order1.commission = {Currency::RUB, 100};

    PlacedOrder order2 = j.get<PlacedOrder>();

    ASSERT_EQ(order1, order2);
}

TEST(json_test, PlacedOrder_Missed_message) {
    Json j = R"(
        {
            "orderId": "testOrder",
            "operation": "Buy",
            "status": "New",
            "rejectReason": "reject-reason 123",
            "requestedLots": 100,
            "executedLots": 200,
            "commission": {
                "currency": "RUB",
                "value": 100
            }
        }
    )"_json;

    PlacedOrder order1;
    order1.orderId = "testOrder";
    order1.operation = OperationType::Buy;
    order1.status = OrderStatus::New;
    order1.rejectReason = "reject-reason 123";
    order1.requestedLots = 100;
    order1.executedLots = 200;
    order1.commission = {Currency::RUB, 100};

    PlacedOrder order2 = j.get<PlacedOrder>();

    ASSERT_EQ(order1, order2);
}

TEST(json_test, PlacedOrder_Missed_commission) {
    Json j = R"(
        {
            "orderId": "testOrder",
            "operation": "Buy",
            "status": "New",
            "rejectReason": "reject-reason 123",
            "message": "TestMessage",
            "requestedLots": 100,
            "executedLots": 200
        }
    )"_json;

    PlacedOrder order1;
    order1.orderId = "testOrder";
    order1.operation = OperationType::Buy;
    order1.status = OrderStatus::New;
    order1.rejectReason = "reject-reason 123";
    order1.message = "TestMessage";
    order1.requestedLots = 100;
    order1.executedLots = 200;

    PlacedOrder order2 = j.get<PlacedOrder>();

    ASSERT_EQ(order1, order2);
}

TEST(json_test, PlacedOrder_Exception_orderId) {
    Json j = R"(
        {
            "operation": "Buy",
            "status": "New",
            "rejectReason": "reject-reason 123",
            "message": "TestMessage",
            "requestedLots": 100,
            "executedLots": 200,
            "commission": {
                "currency": "RUB",
                "value": 100
            }
        }
    )"_json;

    ASSERT_THROW(j.get<PlacedOrder>(), std::string);
}

TEST(json_test, PlacedOrder_Exception_operation) {
    Json j = R"(
        {
            "orderId": "testOrder",
            "status": "New",
            "rejectReason": "reject-reason 123",
            "message": "TestMessage",
            "requestedLots": 100,
            "executedLots": 200,
            "commission": {
                "currency": "RUB",
                "value": 100
            }
        }
    )"_json;

    ASSERT_THROW(j.get<PlacedOrder>(), std::string);
}

TEST(json_test, PlacedOrder_Exception_status) {
    Json j = R"(
        {
            "orderId": "testOrder",
            "operation": "Buy",
            "rejectReason": "reject-reason 123",
            "message": "TestMessage",
            "requestedLots": 100,
            "executedLots": 200,
            "commission": {
                "currency": "RUB",
                "value": 100
            }
        }
    )"_json;

    ASSERT_THROW(j.get<PlacedOrder>(), std::string);
}

TEST(json_test, PlacedOrder_Exception_requestedLots) {
    Json j = R"(
        {
            "orderId": "testOrder",
            "operation": "Buy",
            "status": "New",
            "rejectReason": "reject-reason 123",
            "message": "TestMessage",
            "executedLots": 200,
            "commission": {
                "currency": "RUB",
                "value": 100
            }
        }
    )"_json;

    ASSERT_THROW(j.get<PlacedOrder>(), std::string);
}

TEST(json_test, PlacedOrder_Exception_executedLots) {
    Json j = R"(
        {
            "orderId": "testOrder",
            "operation": "Buy",
            "status": "New",
            "rejectReason": "reject-reason 123",
            "message": "TestMessage",
            "requestedLots": 100,
            "commission": {
                "currency": "RUB",
                "value": 100
            }
        }
    )"_json;

    ASSERT_THROW(j.get<PlacedOrder>(), std::string);
}