#include "gtest/gtest.h"

#include <MarketInstrument.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

TEST(json_test, MarketInstrument_get) {
    Json j = R"(
        {
            "figi": "testFigi1234567890",
            "ticker": "TEST",
            "isin": "TestISIN",
            "minPriceIncrement": 1200,
            "lot": 250000,
            "minQuantity": 20,
            "currency": "USD",
            "name": "TestName!",
            "type": "Stock"
        }
    )"_json;

    MarketInstrument instrument1;
    instrument1.figi = "testFigi1234567890";
    instrument1.ticker = "TEST";
    instrument1.isin = "TestISIN";
    instrument1.minPriceIncrement = 1200;
    instrument1.lot = 250000;
    instrument1.minQuantity = 20;
    instrument1.currency = Currency::USD;
    instrument1.name = "TestName!";
    instrument1.type = InstrumentType::Stock;

    MarketInstrument instrument2 = j.get<MarketInstrument>();

    ASSERT_EQ(instrument1, instrument2);
}

TEST(json_test, MarketInstrument_Parse) {
    std::string text = R"(
        {
            "figi": "testFigi1234567890",
            "ticker": "TEST",
            "isin": "TestISIN",
            "minPriceIncrement": 1200,
            "lot": 250000,
            "minQuantity": 20,
            "currency": "USD",
            "name": "TestName!",
            "type": "Stock"
        }
    )";

    MarketInstrument instrument1;
    instrument1.figi = "testFigi1234567890";
    instrument1.ticker = "TEST";
    instrument1.isin = "TestISIN";
    instrument1.minPriceIncrement = 1200;
    instrument1.lot = 250000;
    instrument1.minQuantity = 20;
    instrument1.currency = Currency::USD;
    instrument1.name = "TestName!";
    instrument1.type = InstrumentType::Stock;

    MarketInstrument instrument2 = Json::parse(text);

    ASSERT_EQ(instrument1, instrument2);
}