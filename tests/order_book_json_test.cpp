#include <gtest/gtest.h>

#include <OrderBook.h>
#include <utils.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

/*
void printOrderBook(OrderBook& o) {
    std::cout << o.figi << std::endl;
    std::cout << o.depth << std::endl;
    std::cout << toString(o.tradeStatus) << std::endl;
    std::cout << o.minPriceIncrement << std::endl;
    std::cout << *o.faceValue << std::endl;
    std::cout << *o.lastPrice << std::endl;
    std::cout << *o.closePrice << std::endl;
    std::cout << *o.limitDown << std::endl;
    std::cout << *o.limitUp << std::endl;
    std::cout << "Bids:\n";
    for (auto& b : o.bids) {
        std::cout << b.price << " - " << b.quantity << std::endl;
    }
    std::cout << "Asks:\n";
    for (auto& a : o.asks) {
        std::cout << a.price << " - " << a.quantity << std::endl;
    }
}
*/

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

    //printOrderBook(orderBook1);
    //printOrderBook(orderBook2);

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

    //printOrderBook(orderBook1);
    //printOrderBook(orderBook2);

    ASSERT_EQ(orderBook1, orderBook2);
}