#include <RestProvider.h>
#include <UrlLib.h>
#include <utils.h>

#include <nlohmann/json.hpp>
#include <cpr/cpr.h> 

#include <string>
#include <iostream>

using Json = nlohmann::json;

RestProvider::RestProvider(char* _token)
    : token(_token)
{}

RestProvider::RestProvider(std::string& _token)
    : token(_token)
{}

// Orders
std::pair<std::vector<Order>, Error> RestProvider::Orders(const char* _url, std::string& id) {
    std::pair<std::vector<Order>, Error> result;

    std::string url = _url;
    if (id.length()) {
        url += "?brokerAccountId=";
        url += id;
    }

    cpr::Response response = cpr::Get(cpr::Url{url},
                                      cpr::Bearer{token},
                                      cpr::VerifySsl{false});

    if (response.status_code == 200) {
        Json json = Json::parse(response.text);

        for (auto& o : json["payload"]) {
            try {
                Order order = o.get<Order>();
                result.first.push_back(order);
            } catch (std::string error) {
                result.first.clear();
                
                result.second.message = error;
                result.second.code = "Error";

                return result;
            }
        }

        result.second.code = "Ok";

        return result;
    } else if (response.status_code == 500) {
        Json json = Json::parse(response.text);
        
        result.second.message = json["payload"]["message"];
        result.second.code = json["payload"]["code"];

        return result;
    }

    result.second.message = "Invalid Response";
    result.second.code = "Error";

    return result;
}

std::pair<PlacedLimitOrder, Error> RestProvider::LimitOrder(const char* url, std::string& id, std::string& figi, int lots, OperationType operation, double price) {

}

std::pair<PlacedMarketOrder, Error> RestProvider::MarketOrder(const char* url, std::string& id, std::string& figi, int lots, OperationType operation) {
}

Error RestProvider::OrderCancel(const char* url, std::string& id, std::string& orderId) {
}


// Portfolio
std::pair<PortfolioInfo, Error> RestProvider::Portfolio(const char* url1, const char* url2, std::string& id) {
}

std::pair<std::vector<PortfolioPosition>, Error> RestProvider::PortfolioPositions(const char* url, std::string& id) {
}

std::pair<std::vector<CurrencyPosition>, Error> RestProvider::PortfolioCurrencies(const char* url, std::string& id) {
}


// Market
std::pair<std::vector<MarketInstrument>, Error> RestProvider::Stocks(const char* url) {
}

std::pair<std::vector<MarketInstrument>, Error> RestProvider::Bonds(const char* url) {
}

std::pair<std::vector<MarketInstrument>, Error> RestProvider::ETFs(const char* url) {
}

std::pair<std::vector<MarketInstrument>, Error> RestProvider::Currencies(const char* url) {
}

std::pair<OrderBook, Error> RestProvider::Orderbook(const char* url, std::string& figi, int depth) {
}

std::pair<std::vector<Candle>, Error> RestProvider::Candles(const char* url, std::string& figi, time_t& from, time_t& to, CandleInterval& interval) {
}

std::pair<SearchMarketInstrument, Error> RestProvider::GetIntsrumentByFIGI(const char* url, std::string& figi) {
}

std::pair<std::vector<MarketInstrument>, Error> RestProvider::GetInstrumentByTicker(const char* url, std::string& ticker) {
}


// Operations
std::pair<std::vector<Operation>, Error> RestProvider::Operations(const char* url, std::string& id, std::string& figi, time_t& from, time_t& to) {
}


// User
std::pair<std::vector<UserAccount>, Error> RestProvider::Accounts(const char* url) {
}