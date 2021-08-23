#include <OrderBook.h>

#include <utils.h>

void to_json(Json& j, const OrderBook& orderBook) {
    j = Json {
                {"figi", orderBook.figi},
                {"depth", std::to_string(orderBook.depth)},
                {"bids", orderBook.bids},
                {"asks", orderBook.asks},
                {"tradeStatus", to_string(orderBook.tradeStatus)},
                {"minPriceIncrement", std::to_string(orderBook.minPriceIncrement)}
             };

    if (orderBook.faceValue) {
        j.push_back({"faceValue", std::to_string(*orderBook.faceValue)});
    }

    if (orderBook.lastPrice) {
        j.push_back({"lastPrice", std::to_string(*orderBook.lastPrice)});
    }

    if (orderBook.closePrice) {
        j.push_back({"closePrice", std::to_string(*orderBook.closePrice)});
    }

    if (orderBook.limitUp) {
        j.push_back({"limitUp", std::to_string(*orderBook.limitUp)});
    }

    if (orderBook.limitDown) {
        j.push_back({"limitDown", std::to_string(*orderBook.limitDown)});
    }
}

void from_json(const Json& j, OrderBook& orderBook) {
    try {
        j.at("figi").get_to(orderBook.figi);
        j.at("depth").get_to(orderBook.depth);
        j.at("bids").get_to(orderBook.bids);
        j.at("asks").get_to(orderBook.asks);
        j.at("minPriceIncrement").get_to(orderBook.minPriceIncrement);

        orderBook.tradeStatus = toTradeStatus(j.at("tradeStatus"));

        if (j.contains("faceValue")) {
            orderBook.faceValue = j["faceValue"].get<double>();
        }

        if (j.contains("lastPrice")) {
            orderBook.lastPrice = j["lastPrice"].get<double>();
        }

        if (j.contains("closePrice")) {
            orderBook.closePrice = j["closePrice"].get<double>();        
        }

        if (j.contains("limitUp")) {
            orderBook.limitUp = j["limitUp"].get<double>();
        }

        if (j.contains("limitDown")) {
            orderBook.limitDown = j["limitDown"].get<double>();
        }
    }
    catch(std::string& error) {
        throw error;
    }
    catch(...) {
        std::string message = "Impossible to parse JSON to OrderBook structure";
        throw message;
    }
}

bool operator==(const OrderBook& lhs, const OrderBook& rhs) {
    if (lhs.bids.size() != rhs.bids.size()) {
        return false;
    }

    for (size_t i = 0; i < lhs.bids.size(); ++i) {
        if (!(lhs.bids[i] == rhs.bids[i])) {
            return false;
        }
    }

    if (lhs.asks.size() != rhs.asks.size()) {
        return false;
    }

    for (size_t i = 0; i < lhs.asks.size(); ++i) {
        if (!(lhs.asks[i] == rhs.asks[i])) {
            return false;
        }
    }
    
    return  lhs.figi == rhs.figi && lhs.depth == rhs.depth &&
            lhs.tradeStatus == rhs.tradeStatus && lhs.minPriceIncrement == rhs.minPriceIncrement &&
            lhs.faceValue == rhs.faceValue && lhs.lastPrice == rhs.lastPrice &&
            lhs.closePrice == rhs.closePrice && lhs.limitUp == rhs.limitUp && 
            lhs.limitDown == rhs.limitDown;
}