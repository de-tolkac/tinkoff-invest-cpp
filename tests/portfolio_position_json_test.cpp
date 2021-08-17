#include <gtest/gtest.h>

#include <PortfolioPosition.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

TEST(json_test, PortfolioPosition_get) {
    Json j = R"(
        {
            "figi": "testFIGI",
            "ticker": "ticker-test",
            "isin": "tets-isin",
            "instrumentType": "Stock",
            "balance": 1000,
            "blocked": 20,
            "expectedYield": {
                "currency": "RUB",
                "value": 10
            },
            "lots": 220,
            "averagePositionPrice": {
                "currency": "USD",
                "value": 20
            },
            "averagePositionPriceNoNkd": {
                "currency": "RUB",
                "value": 30
            },
            "name": "testName"
        }
    )"_json;

    PortfolioPosition position1;
    position1.figi = "testFIGI";
    position1.ticker = "ticker-test";
    position1.isin = "tets-isin";
    position1.instrumentType = InstrumentType::Stock;
    position1.balance = 1000;
    position1.blocked = 20;
    position1.lots = 220;
    position1.name = "testName";
    position1.expectedYield = {Currency::RUB, 10};
    position1.averagePositionPrice = {Currency::USD, 20};
    position1.averagePositionPriceNoNkd = {Currency::RUB, 30};

    PortfolioPosition position2 = j.get<PortfolioPosition>();

    ASSERT_EQ(position1, position2);
}

TEST(json_test, PortfolioPosition_Parse) {
    std::string text = R"(
        {
            "figi": "testFIGI",
            "ticker": "ticker-test",
            "isin": "tets-isin",
            "instrumentType": "Stock",
            "balance": 1000,
            "blocked": 20,
            "expectedYield": {
                "currency": "RUB",
                "value": 10
            },
            "lots": 220,
            "averagePositionPrice": {
                "currency": "USD",
                "value": 20
            },
            "averagePositionPriceNoNkd": {
                "currency": "RUB",
                "value": 30
            },
            "name": "testName"
        }
    )";

    PortfolioPosition position1;
    position1.figi = "testFIGI";
    position1.ticker = "ticker-test";
    position1.isin = "tets-isin";
    position1.instrumentType = InstrumentType::Stock;
    position1.balance = 1000;
    position1.blocked = 20;
    position1.lots = 220;
    position1.name = "testName";
    position1.expectedYield = {Currency::RUB, 10};
    position1.averagePositionPrice = {Currency::USD, 20};
    position1.averagePositionPriceNoNkd = {Currency::RUB, 30};

    PortfolioPosition position2 = Json::parse(text);

    ASSERT_EQ(position1, position2);
}