#include "gtest/gtest.h"

#include <Candle.h>
#include <utils.h>

#include <string>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

using namespace ti;

TEST(json_test, Candle_get) {
    Json j = R"(
        {
            "figi": "testFigi123456789",
            "interval": "1min",
            "o": 10.0,
            "c": 20.1,
            "h": 30.2,
            "l": 40.3,
            "v": 50.4,
            "time": "2019-08-19T18:38:33+03:00"
        }
    )"_json;

    Candle candle1;
    candle1.figi = "testFigi123456789";
    candle1.interval = CandleInterval::_1min;
    candle1.openPrice = 10.0;
    candle1.closePrice = 20.1;
    candle1.highPrice = 30.2;
    candle1.lowPrice = 40.3;
    candle1.volume = 50.4;
    candle1.time = toDate("2019-08-19T18:38:33+03:00");

    Candle candle2 = j.get<Candle>();

    ASSERT_EQ(candle1, candle2);    
}

TEST(json_test, Candle_Parse) {
    Candle candle1;
    candle1.figi = "testFigi123456789";
    candle1.interval = CandleInterval::_1min;
    candle1.openPrice = 10.0;
    candle1.closePrice = 20.1;
    candle1.highPrice = 30.2;
    candle1.lowPrice = 40.3;
    candle1.volume = 50.4;
    candle1.time = toDate("2019-08-19T18:38:33+03:00");

    std::string text = R"(
        {
            "figi": "testFigi123456789",
            "interval": "1min",
            "o": 10.0,
            "c": 20.1,
            "h": 30.2,
            "l": 40.3,
            "v": 50.4,
            "time": "2019-08-19T18:38:33+03:00"
        }
    )";
    Candle candle2 = Json::parse(text);

    ASSERT_EQ(candle1, candle2); 
}

TEST(json_test, Candle_Exception_figi) {
    Json j = R"(
        {
            "interval": "1min",
            "o": 10.0,
            "c": 20.1,
            "h": 30.2,
            "l": 40.3,
            "v": 50.4,
            "time": "2019-08-19T18:38:33+03:00"
        }
    )"_json;

    ASSERT_THROW(j.get<Candle>(), std::string);  
}

TEST(json_test, Candle_Exception_interval) {
    Json j = R"(
        {
            "figi": "testFigi123456789",
            "o": 10.0,
            "c": 20.1,
            "h": 30.2,
            "l": 40.3,
            "v": 50.4,
            "time": "2019-08-19T18:38:33+03:00"
        }
    )"_json;

    ASSERT_THROW(j.get<Candle>(), std::string);  
}

TEST(json_test, Candle_Exception_o) {
    Json j = R"(
        {
            "figi": "testFigi123456789",
            "interval": "1min",
            "c": 20.1,
            "h": 30.2,
            "l": 40.3,
            "v": 50.4,
            "time": "2019-08-19T18:38:33+03:00"
        }
    )"_json;

    ASSERT_THROW(j.get<Candle>(), std::string);  
}

TEST(json_test, Candle_Exception_c) {
    Json j = R"(
        {
            "figi": "testFigi123456789",
            "interval": "1min",
            "o": 10.0,
            "h": 30.2,
            "l": 40.3,
            "v": 50.4,
            "time": "2019-08-19T18:38:33+03:00"
        }
    )"_json;

    ASSERT_THROW(j.get<Candle>(), std::string);  
}

TEST(json_test, Candle_Exception_h) {
    Json j = R"(
        {
            "figi": "testFigi123456789",
            "interval": "1min",
            "o": 10.0,
            "c": 20.1,
            "l": 40.3,
            "v": 50.4,
            "time": "2019-08-19T18:38:33+03:00"
        }
    )"_json;

    ASSERT_THROW(j.get<Candle>(), std::string);  
}

TEST(json_test, Candle_Exception_l) {
    Json j = R"(
        {
            "figi": "testFigi123456789",
            "interval": "1min",
            "o": 10.0,
            "c": 20.1,
            "h": 30.2,
            "v": 50.4,
            "time": "2019-08-19T18:38:33+03:00"
        }
    )"_json;

    ASSERT_THROW(j.get<Candle>(), std::string);  
}

TEST(json_test, Candle_Exception_v) {
    Json j = R"(
        {
            "figi": "testFigi123456789",
            "interval": "1min",
            "o": 10.0,
            "c": 20.1,
            "h": 30.2,
            "l": 40.3,
            "time": "2019-08-19T18:38:33+03:00"
        }
    )"_json;

    ASSERT_THROW(j.get<Candle>(), std::string);  
}

TEST(json_test, Candle_Exception_time) {
    Json j = R"(
        {
            "figi": "testFigi123456789",
            "interval": "1min",
            "o": 10.0,
            "c": 20.1,
            "h": 30.2,
            "l": 40.3,
            "v": 50.4
        }
    )"_json;

    ASSERT_THROW(j.get<Candle>(), std::string);  
}