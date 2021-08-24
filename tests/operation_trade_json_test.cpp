#include <gtest/gtest.h>

#include <OperationTrade.h>
#include <utils.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

using namespace ti;

TEST(json_test, OperationTrade_get) {
    Json j = R"(
            {
                "tradeId": "testTradeId",
                "date": "2019-08-19T18:38:33+03:00",
                "price": 1000,
                "quantity": 200
            }
    )"_json;

    OperationTrade operationTrade1 = {"testTradeId", toDate("2019-08-19T18:38:33+03:00"), 1000, 200};
    OperationTrade operationTrade2 = j.get<OperationTrade>();

    ASSERT_EQ(operationTrade1, operationTrade2);
}

TEST(json_test, OperationTrade_Parse) {
    std::string text = R"(
            {
                "tradeId": "testTradeId",
                "date": "2019-08-19T18:38:33+03:00",
                "price": 1000,
                "quantity": 200
            }
    )";

    OperationTrade operationTrade1 = {"testTradeId", toDate("2019-08-19T18:38:33+03:00"), 1000, 200};
    OperationTrade operationTrade2 = Json::parse(text);

    ASSERT_EQ(operationTrade1, operationTrade2);
}

TEST(json_test, OperationTrade_Exception_tradeId) {
    Json j = R"(
            {
                "date": "2019-08-19T18:38:33+03:00",
                "price": 1000,
                "quantity": 200
            }
    )"_json;

    ASSERT_THROW(j.get<OperationTrade>(), std::string);
}

TEST(json_test, OperationTrade_Exception_date) {
    Json j = R"(
            {
                "tradeId": "testTradeId",
                "price": 1000,
                "quantity": 200
            }
    )"_json;

    ASSERT_THROW(j.get<OperationTrade>(), std::string);
}

TEST(json_test, OperationTrade_Exception_price) {
    Json j = R"(
            {
                "tradeId": "testTradeId",
                "date": "2019-08-19T18:38:33+03:00",
                "quantity": 200
            }
    )"_json;

    ASSERT_THROW(j.get<OperationTrade>(), std::string);
}

TEST(json_test, OperationTrade_Exception_quantity) {
    Json j = R"(
            {
                "tradeId": "testTradeId",
                "date": "2019-08-19T18:38:33+03:00",
                "price": 1000
            }
    )"_json;

    ASSERT_THROW(j.get<OperationTrade>(), std::string);
}