#include <gtest/gtest.h>

#include <OrderBook.h>
#include <utils.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

using namespace ti;

TEST(json_test, OrderBook_get) {
    Json j = R"(
        {
            "figi": "testFigi",
            "depth": 10,
            "bids": [
                {
                    "price": 250,
                    "quantity": 10000
                }
            ],
            "asks": [
                {
                    "price": 251.1,
                    "quantity": 2700
                }
            ],
            "tradeStatus": "NormalTrading",
            "minPriceIncrement": 10,
            "faceValue": 20,
            "lastPrice": 30,
            "closePrice": 40,
            "limitUp": 50,
            "limitDown": 60
        }
    )"_json;

    OrderBook orderBook1;
    orderBook1.figi = "testFigi";
    orderBook1.depth = 10;
    orderBook1.tradeStatus = TradeStatus::NormalTrading;
    orderBook1.minPriceIncrement = 10;
    orderBook1.faceValue = 20;
    orderBook1.lastPrice = 30;
    orderBook1.closePrice = 40;
    orderBook1.limitUp = 50;
    orderBook1.limitDown = 60;

    orderBook1.bids.push_back({250, 10000});
    orderBook1.asks.push_back({251.1, 2700});

    OrderBook orderBook2 = j.get<OrderBook>();

    ASSERT_EQ(orderBook1, orderBook2);
}

TEST(json_test, OrderBook_Parse) {
    std::string text = R"(
        {
            "figi": "testFigi",
            "depth": 10,
            "bids": [
                {
                    "price": 250,
                    "quantity": 10000
                }
            ],
            "asks": [
                {
                    "price": 251.1,
                    "quantity": 2700
                }
            ],
            "tradeStatus": "NormalTrading",
            "minPriceIncrement": 10,
            "faceValue": 20,
            "lastPrice": 30,
            "closePrice": 40,
            "limitUp": 50,
            "limitDown": 60
        }
    )";

    OrderBook orderBook1;
    orderBook1.figi = "testFigi";
    orderBook1.depth = 10;
    orderBook1.tradeStatus = TradeStatus::NormalTrading;
    orderBook1.minPriceIncrement = 10;
    orderBook1.faceValue = 20;
    orderBook1.lastPrice = 30;
    orderBook1.closePrice = 40;
    orderBook1.limitUp = 50;
    orderBook1.limitDown = 60;

    orderBook1.bids.push_back({250, 10000});
    orderBook1.asks.push_back({251.1, 2700});

    OrderBook orderBook2 = Json::parse(text);

    ASSERT_EQ(orderBook1, orderBook2);
}

TEST(json_test, OrderBook_Missed_faceValue) {
    Json j = R"(
        {
            "figi": "testFigi",
            "depth": 10,
            "bids": [
                {
                    "price": 250,
                    "quantity": 10000
                }
            ],
            "asks": [
                {
                    "price": 251.1,
                    "quantity": 2700
                }
            ],
            "tradeStatus": "NormalTrading",
            "minPriceIncrement": 10,
            "lastPrice": 30,
            "closePrice": 40,
            "limitUp": 50,
            "limitDown": 60
        }
    )"_json;

    OrderBook orderBook1;
    orderBook1.figi = "testFigi";
    orderBook1.depth = 10;
    orderBook1.tradeStatus = TradeStatus::NormalTrading;
    orderBook1.minPriceIncrement = 10;
    orderBook1.lastPrice = 30;
    orderBook1.closePrice = 40;
    orderBook1.limitUp = 50;
    orderBook1.limitDown = 60;

    orderBook1.bids.push_back({250, 10000});
    orderBook1.asks.push_back({251.1, 2700});

    OrderBook orderBook2 = j.get<OrderBook>();

    ASSERT_EQ(orderBook1, orderBook2);
}

TEST(json_test, OrderBook_Missed_lastPrice) {
    Json j = R"(
        {
            "figi": "testFigi",
            "depth": 10,
            "bids": [
                {
                    "price": 250,
                    "quantity": 10000
                }
            ],
            "asks": [
                {
                    "price": 251.1,
                    "quantity": 2700
                }
            ],
            "tradeStatus": "NormalTrading",
            "minPriceIncrement": 10,
            "faceValue": 20,
            "closePrice": 40,
            "limitUp": 50,
            "limitDown": 60
        }
    )"_json;

    OrderBook orderBook1;
    orderBook1.figi = "testFigi";
    orderBook1.depth = 10;
    orderBook1.tradeStatus = TradeStatus::NormalTrading;
    orderBook1.minPriceIncrement = 10;
    orderBook1.faceValue = 20;
    orderBook1.closePrice = 40;
    orderBook1.limitUp = 50;
    orderBook1.limitDown = 60;

    orderBook1.bids.push_back({250, 10000});
    orderBook1.asks.push_back({251.1, 2700});

    OrderBook orderBook2 = j.get<OrderBook>();

    ASSERT_EQ(orderBook1, orderBook2);
}

TEST(json_test, OrderBook_Missed_closePrice) {
    Json j = R"(
        {
            "figi": "testFigi",
            "depth": 10,
            "bids": [
                {
                    "price": 250,
                    "quantity": 10000
                }
            ],
            "asks": [
                {
                    "price": 251.1,
                    "quantity": 2700
                }
            ],
            "tradeStatus": "NormalTrading",
            "minPriceIncrement": 10,
            "faceValue": 20,
            "lastPrice": 30,
            "limitUp": 50,
            "limitDown": 60
        }
    )"_json;

    OrderBook orderBook1;
    orderBook1.figi = "testFigi";
    orderBook1.depth = 10;
    orderBook1.tradeStatus = TradeStatus::NormalTrading;
    orderBook1.minPriceIncrement = 10;
    orderBook1.faceValue = 20;
    orderBook1.lastPrice = 30;
    orderBook1.limitUp = 50;
    orderBook1.limitDown = 60;

    orderBook1.bids.push_back({250, 10000});
    orderBook1.asks.push_back({251.1, 2700});

    OrderBook orderBook2 = j.get<OrderBook>();

    ASSERT_EQ(orderBook1, orderBook2);
}

TEST(json_test, OrderBook_Missed_limitUp) {
    Json j = R"(
        {
            "figi": "testFigi",
            "depth": 10,
            "bids": [
                {
                    "price": 250,
                    "quantity": 10000
                }
            ],
            "asks": [
                {
                    "price": 251.1,
                    "quantity": 2700
                }
            ],
            "tradeStatus": "NormalTrading",
            "minPriceIncrement": 10,
            "faceValue": 20,
            "lastPrice": 30,
            "closePrice": 40,
            "limitDown": 60
        }
    )"_json;

    OrderBook orderBook1;
    orderBook1.figi = "testFigi";
    orderBook1.depth = 10;
    orderBook1.tradeStatus = TradeStatus::NormalTrading;
    orderBook1.minPriceIncrement = 10;
    orderBook1.faceValue = 20;
    orderBook1.lastPrice = 30;
    orderBook1.closePrice = 40;
    orderBook1.limitDown = 60;

    orderBook1.bids.push_back({250, 10000});
    orderBook1.asks.push_back({251.1, 2700});

    OrderBook orderBook2 = j.get<OrderBook>();

    ASSERT_EQ(orderBook1, orderBook2);
}

TEST(json_test, OrderBook_Missed_limitDown) {
    Json j = R"(
        {
            "figi": "testFigi",
            "depth": 10,
            "bids": [
                {
                    "price": 250,
                    "quantity": 10000
                }
            ],
            "asks": [
                {
                    "price": 251.1,
                    "quantity": 2700
                }
            ],
            "tradeStatus": "NormalTrading",
            "minPriceIncrement": 10,
            "faceValue": 20,
            "lastPrice": 30,
            "closePrice": 40,
            "limitUp": 50
        }
    )"_json;

    OrderBook orderBook1;
    orderBook1.figi = "testFigi";
    orderBook1.depth = 10;
    orderBook1.tradeStatus = TradeStatus::NormalTrading;
    orderBook1.minPriceIncrement = 10;
    orderBook1.faceValue = 20;
    orderBook1.lastPrice = 30;
    orderBook1.closePrice = 40;
    orderBook1.limitUp = 50;

    orderBook1.bids.push_back({250, 10000});
    orderBook1.asks.push_back({251.1, 2700});

    OrderBook orderBook2 = j.get<OrderBook>();

    ASSERT_EQ(orderBook1, orderBook2);
}

TEST(json_test, OrderBook_Exception_figi) {
    Json j = R"(
        {
            "depth": 10,
            "bids": [
                {
                    "price": 250,
                    "quantity": 10000
                }
            ],
            "asks": [
                {
                    "price": 251.1,
                    "quantity": 2700
                }
            ],
            "tradeStatus": "NormalTrading",
            "minPriceIncrement": 10,
            "faceValue": 20,
            "lastPrice": 30,
            "closePrice": 40,
            "limitUp": 50,
            "limitDown": 60
        }
    )"_json;

    ASSERT_THROW(j.get<OrderBook>(), std::string);
}

TEST(json_test, OrderBook_Exception_depth) {
    Json j = R"(
        {
            "figi": "testFigi",
            "bids": [
                {
                    "price": 250,
                    "quantity": 10000
                }
            ],
            "asks": [
                {
                    "price": 251.1,
                    "quantity": 2700
                }
            ],
            "tradeStatus": "NormalTrading",
            "minPriceIncrement": 10,
            "faceValue": 20,
            "lastPrice": 30,
            "closePrice": 40,
            "limitUp": 50,
            "limitDown": 60
        }
    )"_json;

    ASSERT_THROW(j.get<OrderBook>(), std::string);
}

TEST(json_test, OrderBook_Exception_bids) {
    Json j = R"(
        {
            "figi": "testFigi",
            "depth": 10,
            "asks": [
                {
                    "price": 251.1,
                    "quantity": 2700
                }
            ],
            "tradeStatus": "NormalTrading",
            "minPriceIncrement": 10,
            "faceValue": 20,
            "lastPrice": 30,
            "closePrice": 40,
            "limitUp": 50,
            "limitDown": 60
        }
    )"_json;

    ASSERT_THROW(j.get<OrderBook>(), std::string);
}

TEST(json_test, OrderBook_Exception_asks) {
    Json j = R"(
        {
            "figi": "testFigi",
            "depth": 10,
            "bids": [
                {
                    "price": 250,
                    "quantity": 10000
                }
            ],
            "tradeStatus": "NormalTrading",
            "minPriceIncrement": 10,
            "faceValue": 20,
            "lastPrice": 30,
            "closePrice": 40,
            "limitUp": 50,
            "limitDown": 60
        }
    )"_json;

    ASSERT_THROW(j.get<OrderBook>(), std::string);
}

TEST(json_test, OrderBook_Exception_tradeStatus) {
    Json j = R"(
        {
            "figi": "testFigi",
            "depth": 10,
            "bids": [
                {
                    "price": 250,
                    "quantity": 10000
                }
            ],
            "asks": [
                {
                    "price": 251.1,
                    "quantity": 2700
                }
            ],
            "minPriceIncrement": 10,
            "faceValue": 20,
            "lastPrice": 30,
            "closePrice": 40,
            "limitUp": 50,
            "limitDown": 60
        }
    )"_json;

    ASSERT_THROW(j.get<OrderBook>(), std::string);
}

TEST(json_test, OrderBook_Exception_minPriceIncrement) {
    Json j = R"(
        {
            "figi": "testFigi",
            "depth": 10,
            "bids": [
                {
                    "price": 250,
                    "quantity": 10000
                }
            ],
            "asks": [
                {
                    "price": 251.1,
                    "quantity": 2700
                }
            ],
            "tradeStatus": "NormalTrading",
            "faceValue": 20,
            "lastPrice": 30,
            "closePrice": 40,
            "limitUp": 50,
            "limitDown": 60
        }
    )"_json;

    ASSERT_THROW(j.get<OrderBook>(), std::string);
}