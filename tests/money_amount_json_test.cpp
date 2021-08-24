#include "gtest/gtest.h"

#include <MoneyAmount.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

using namespace ti;

TEST(json_test, MoneyAmount_get) {
    Json j = R"(
        {
            "currency": "USD",
            "value": 250000.19
        }
    )"_json;

    MoneyAmount amount1;
    amount1.currency = Currency::USD;
    amount1.value = 250000.19;

    MoneyAmount amount2 = j.get<MoneyAmount>();

    ASSERT_EQ(amount1, amount2);
}

TEST(json_test, MoneyAmount_Parse) {
    std::string text = R"(
        {
            "currency": "USD",
            "value": 250000.19
        }
    )";

    MoneyAmount amount1;
    amount1.currency = Currency::USD;
    amount1.value = 250000.19;

    MoneyAmount amount2 = Json::parse(text);

    ASSERT_EQ(amount1, amount2);
}

TEST(json_test, MoneyAmount_Exception_currency) {
    Json j = R"(
        {
            "value": 250000.19
        }
    )"_json;

    ASSERT_THROW(j.get<MoneyAmount>(), std::string);
}

TEST(json_test, MoneyAmount_Exception_value) {
    Json j = R"(
        {
            "currency": "USD"
        }
    )"_json;

    ASSERT_THROW(j.get<MoneyAmount>(), std::string);
}