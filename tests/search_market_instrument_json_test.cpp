#include <gtest/gtest.h>

#include <SearchMarketInstrument.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

TEST(json_test, SearchMarketInstrument_get) {
    Json j = R"(
        {
            "figi": "testFigi",
            "ticker": "testTicker",
            "isin": "testISIN",
            "minPriceIncrement": 1000,
            "lot": 250000,
            "currency": "RUB",
            "name": "test-name",
            "type": "Stock"
        }
    )"_json;

    SearchMarketInstrument instrument1;
    instrument1.figi = "testFigi";
    instrument1.ticker = "testTicker";
    instrument1.isin = "testISIN";
    instrument1.minPriceIncrement = 1000;
    instrument1.lot = 250000;
    instrument1.currency = Currency::RUB;
    instrument1.name = "test-name";
    instrument1.type = InstrumentType::Stock;

    SearchMarketInstrument instrument2 = j.get<SearchMarketInstrument>();

    ASSERT_EQ(instrument1, instrument2);
}

TEST(json_test, SearchMarketInstrument_Parse) {
    std::string text = R"(
        {
            "figi": "testFigi",
            "ticker": "testTicker",
            "isin": "testISIN",
            "minPriceIncrement": 1000,
            "lot": 250000,
            "currency": "RUB",
            "name": "test-name",
            "type": "Stock"
        }
    )";

    SearchMarketInstrument instrument1;
    instrument1.figi = "testFigi";
    instrument1.ticker = "testTicker";
    instrument1.isin = "testISIN";
    instrument1.minPriceIncrement = 1000;
    instrument1.lot = 250000;
    instrument1.currency = Currency::RUB;
    instrument1.name = "test-name";
    instrument1.type = InstrumentType::Stock;

    SearchMarketInstrument instrument2 = Json::parse(text);

    ASSERT_EQ(instrument1, instrument2);
}

TEST(json_test, SearchMarketInstrument_Missed_isin) {
    Json j = R"(
        {
            "figi": "testFigi",
            "ticker": "testTicker",
            "minPriceIncrement": 1000,
            "lot": 250000,
            "currency": "RUB",
            "name": "test-name",
            "type": "Stock"
        }
    )"_json;

    SearchMarketInstrument instrument1;
    instrument1.figi = "testFigi";
    instrument1.ticker = "testTicker";
    instrument1.minPriceIncrement = 1000;
    instrument1.lot = 250000;
    instrument1.currency = Currency::RUB;
    instrument1.name = "test-name";
    instrument1.type = InstrumentType::Stock;

    SearchMarketInstrument instrument2 = j.get<SearchMarketInstrument>();

    ASSERT_EQ(instrument1, instrument2);
}

TEST(json_test, SearchMarketInstrument_Missed_minPriceIncrement) {
    Json j = R"(
        {
            "figi": "testFigi",
            "ticker": "testTicker",
            "isin": "testISIN",
            "lot": 250000,
            "currency": "RUB",
            "name": "test-name",
            "type": "Stock"
        }
    )"_json;

    SearchMarketInstrument instrument1;
    instrument1.figi = "testFigi";
    instrument1.ticker = "testTicker";
    instrument1.isin = "testISIN";
    instrument1.lot = 250000;
    instrument1.currency = Currency::RUB;
    instrument1.name = "test-name";
    instrument1.type = InstrumentType::Stock;

    SearchMarketInstrument instrument2 = j.get<SearchMarketInstrument>();

    ASSERT_EQ(instrument1, instrument2);
}

TEST(json_test, SearchMarketInstrument_Missed_currency) {
    Json j = R"(
        {
            "figi": "testFigi",
            "ticker": "testTicker",
            "isin": "testISIN",
            "minPriceIncrement": 1000,
            "lot": 250000,
            "name": "test-name",
            "type": "Stock"
        }
    )"_json;

    SearchMarketInstrument instrument1;
    instrument1.figi = "testFigi";
    instrument1.ticker = "testTicker";
    instrument1.isin = "testISIN";
    instrument1.minPriceIncrement = 1000;
    instrument1.lot = 250000;
    instrument1.name = "test-name";
    instrument1.type = InstrumentType::Stock;

    SearchMarketInstrument instrument2 = j.get<SearchMarketInstrument>();

    ASSERT_EQ(instrument1, instrument2);
}

TEST(json_test, SearchMarketInstrument_Exception_figi) {
    Json j = R"(
        {
            "ticker": "testTicker",
            "isin": "testISIN",
            "minPriceIncrement": 1000,
            "lot": 250000,
            "currency": "RUB",
            "name": "test-name",
            "type": "Stock"
        }
    )"_json;

    ASSERT_THROW(j.get<SearchMarketInstrument>(), std::string);
}

TEST(json_test, SearchMarketInstrument_Exception_ticker) {
    Json j = R"(
        {
            "figi": "testFigi",
            "isin": "testISIN",
            "minPriceIncrement": 1000,
            "lot": 250000,
            "currency": "RUB",
            "name": "test-name",
            "type": "Stock"
        }
    )"_json;

    ASSERT_THROW(j.get<SearchMarketInstrument>(), std::string);
}

TEST(json_test, SearchMarketInstrument_Exception_lot) {
    Json j = R"(
        {
            "figi": "testFigi",
            "ticker": "testTicker",
            "isin": "testISIN",
            "minPriceIncrement": 1000,
            "currency": "RUB",
            "name": "test-name",
            "type": "Stock"
        }
    )"_json;

    ASSERT_THROW(j.get<SearchMarketInstrument>(), std::string);
}

TEST(json_test, SearchMarketInstrument_Exception_name) {
    Json j = R"(
        {
            "figi": "testFigi",
            "ticker": "testTicker",
            "isin": "testISIN",
            "minPriceIncrement": 1000,
            "lot": 250000,
            "currency": "RUB",
            "type": "Stock"
        }
    )"_json;

    ASSERT_THROW(j.get<SearchMarketInstrument>(), std::string);
}

TEST(json_test, SearchMarketInstrument_Exception_type) {
    Json j = R"(
        {
            "figi": "testFigi",
            "ticker": "testTicker",
            "isin": "testISIN",
            "minPriceIncrement": 1000,
            "lot": 250000,
            "currency": "RUB",
            "name": "test-name"
        }
    )"_json;

    ASSERT_THROW(j.get<SearchMarketInstrument>(), std::string);
}