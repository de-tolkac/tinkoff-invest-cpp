#include <gtest/gtest.h>

#include <Operation.h>
#include <utils.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;


TEST(json_test, Operation_get) {
    Json j = R"(
        {
            "id": "testId",
            "status": "Done",
            "trades": [
            {
                "tradeId": "testTradeId",
                "date": "2019-08-19T18:38:33+03:00",
                "price": 1000,
                "quantity": 200
            }
            ],
            "commission": {
                "currency": "RUB",
                "value": 2050
            },
            "currency": "RUB",
            "payment": 10,
            "price": 20.5,
            "quantity": 1000,
            "quantityExecuted": 20,
            "figi": "testFIGI!",
            "instrumentType": "Stock",
            "isMarginCall": true,
            "date": "2019-08-19T18:38:33+03:00",
            "operationType": "Buy"
        }
    )"_json;

    std::cout << "HERE1" << std::endl;

    Operation operation1;
    operation1.id = "testId";
    operation1.status = OperationStatus::Done;
    std::vector<OperationTrade> tr;
    tr.push_back({"testTradeId", toDate("2019-08-19T18:38:33+03:00"), 1000, 200});
    operation1.trades.emplace(tr);
    operation1.commission = {Currency::RUB, 2050};
    operation1.currency = Currency::RUB;
    operation1.payment = 10;
    operation1.price = 20.5;
    operation1.quantity = 1000;
    operation1.quantityExecuted = 20;
    operation1.figi = "testFIGI!";
    operation1.instrumentType = InstrumentType::Stock;
    operation1.isMarginCall = true;
    operation1.date = toDate("2019-08-19T18:38:33+03:00");
    operation1.operationType = OperationTypeWithCommission::Buy;

    std::cout << "HERE2" << std::flush << std::endl;
    Operation operation2 = j.get<Operation>();

    ASSERT_EQ(operation1, operation2);
}

TEST(json_test, Operation_Parse) {
    std::string text = R"(
        {
            "id": "testId",
            "status": "Done",
            "trades": [
            {
                "tradeId": "testTradeId",
                "date": "2019-08-19T18:38:33+03:00",
                "price": 1000,
                "quantity": 200
            }
            ],
            "commission": {
                "currency": "RUB",
                "value": 2050
            },
            "currency": "RUB",
            "payment": 10,
            "price": 20.5,
            "quantity": 1000,
            "quantityExecuted": 20,
            "figi": "testFIGI!",
            "instrumentType": "Stock",
            "isMarginCall": true,
            "date": "2019-08-19T18:38:33+03:00",
            "operationType": "Buy"
        }
    )";

    Operation operation1;
    operation1.id = "testId";
    operation1.status = OperationStatus::Done;
    std::vector<OperationTrade> tr;
    tr.push_back({"testTradeId", toDate("2019-08-19T18:38:33+03:00"), 1000, 200});
    operation1.trades.emplace(tr);
    operation1.commission = {Currency::RUB, 2050};
    operation1.currency = Currency::RUB;
    operation1.payment = 10;
    operation1.price = 20.5;
    operation1.quantity = 1000;
    operation1.quantityExecuted = 20;
    operation1.figi = "testFIGI!";
    operation1.instrumentType = InstrumentType::Stock;
    operation1.isMarginCall = true;
    operation1.date = toDate("2019-08-19T18:38:33+03:00");
    operation1.operationType = OperationTypeWithCommission::Buy;

    Operation operation2 = Json::parse(text);

    ASSERT_EQ(operation1, operation2);
}