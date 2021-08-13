#include "gtest/gtest.h"

#include <CurrencyPosition.h>

#include <string>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

TEST(json_test, CurrencyPosition_get) {
    Json j = R"(
        {
            "currency": "RUB",
            "balance": 1000.25,
            "blocked": 25.0
        }
    )"_json;

    CurrencyPosition curPosition1;
    curPosition1.currency = Currency::RUB;
    curPosition1.balance = 1000.25;
    curPosition1.blocked = 25.0;

    CurrencyPosition curPosition2 = j.get<CurrencyPosition>();

    ASSERT_EQ(curPosition1, curPosition2);
}

TEST(json_test, CurrencyPosition_Parse) {
    std::string text = "{\"currency\":\"RUB\",\"balance\":1000.25,\"blocked\":25.0}";

    CurrencyPosition curPosition1;
    curPosition1.currency = Currency::RUB;
    curPosition1.balance = 1000.25;
    curPosition1.blocked = 25.0;

    CurrencyPosition curPosition2 = Json::parse(text);

    ASSERT_EQ(curPosition1, curPosition2);
}