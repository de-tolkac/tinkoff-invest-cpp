#include <RestProvider.h>
#include <UrlLib.h>
#include <utils.h>
#include <Http.h>

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
std::pair<OrderList, Error> RestProvider::Orders(const char* url, std::string& id) const {
    cpr::Parameters params{{"brokerAccountId", id}};

    return handleGetRequest<OrderList>(url, "", token, params);
}

std::pair<PlacedOrder, Error> RestProvider::LimitOrder(const char* url, std::string& id, std::string& figi, int lots, OperationType operation, double price) const {
    std::string body = "{\"lots\": ";
    body += std::to_string(lots);
    body += ", \"operation\": \"";
    body += toString(operation);
    body += "\", \"price\": ";
    body += std::to_string(price);
    body += "}";

    cpr::Parameters params{{"figi", figi}};
    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }
    
    return handlePostRequest<PlacedOrder>(url, "", token, body, params);
}

std::pair<PlacedOrder, Error> RestProvider::MarketOrder(const char* url, std::string& id, std::string& figi, int lots, OperationType operation) const {
    std::string body = "{\"lots\": ";
    body += std::to_string(lots);
    body += ", \"operation\": \"";
    body += toString(operation);
    body += "\"}";

    cpr::Parameters params{{"figi", figi}};
    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }

    return handlePostRequest<PlacedOrder>(url, "", token, body, params);
}

Error RestProvider::OrderCancel(const char* url, std::string& id, std::string& orderId) const {
    cpr::Parameters params{{"orderId", orderId}};
    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }

    std::string body;

    return handlePostRequest(url, "", token, body, params);
}


// Portfolio
std::pair<PortfolioInfo, Error> RestProvider::Portfolio(const char* url1, const char* url2, std::string& id) const {
    std::pair<PortfolioInfo, Error> result;

    auto [positions, err1] = RestProvider::PortfolioPositions(url1, id);
    if (err1) {
        result.second = err1;

        return result;
    }

    auto [currencies, err2] = RestProvider::PortfolioCurrencies(url2, id);
    if (err2) {
        result.second = err2;

        return result;
    }

    result.first.positions = positions;
    result.first.currencies = currencies;
    result.second.code = "Ok";

    return result;
}

std::pair<PortfolioPositionList, Error> RestProvider::PortfolioPositions(const char* url, std::string& id) const {
    cpr::Parameters params{{"brokerAccountId", id}};

   return handleGetRequest<PortfolioPositionList>(url, "positions", token, params);
}

std::pair<CurrencyPositionList, Error> RestProvider::PortfolioCurrencies(const char* url, std::string& id) const {
    cpr::Parameters params{{"brokerAccountId", id}};

    return handleGetRequest<CurrencyPositionList>(url, "currencies", token, params);
}


// Market
std::pair<MarketInstrumentList, Error> RestProvider::GetInstruments(const char* url) const {
    cpr::Parameters params{};

    return handleGetRequest<MarketInstrumentList>(url, "instruments", token, params);
}

std::pair<OrderBook, Error> RestProvider::Orderbook(const char* url, std::string& figi, int depth) const {
    cpr::Parameters params{{"figi", figi}, {"depth", std::to_string(depth)}};

    return handleGetRequest<OrderBook>(url, "", token, params);
}

std::pair<CandleList, Error> RestProvider::Candles(const char* url, std::string& figi, std::string& from, std::string& to, CandleInterval& interval) const {
    cpr::Parameters params{{"figi", figi}, {"from", from}, {"to", to},{"interval", toString(interval)}};
    
    return handleGetRequest<CandleList>(url, "candles", token, params);
}

std::pair<SearchMarketInstrument, Error> RestProvider::GetIntsrumentByFIGI(const char* url, std::string& figi) const {
    cpr::Parameters params{{"figi", figi}};
    
    return handleGetRequest<SearchMarketInstrument>(url, "", token, params);
}

std::pair<MarketInstrumentList, Error> RestProvider::GetInstrumentByTicker(const char* url, std::string& ticker) const {
    cpr::Parameters params{{"ticker", ticker}};
    
    return handleGetRequest<MarketInstrumentList>(url, "instruments", token, params);
}


// Operations
std::pair<OperationList, Error> RestProvider::Operations(const char* url, std::string& id, std::string& figi, std::string& from, std::string& to) const {
    cpr::Parameters params{{"from", from}, {"to", to}};

    if (figi.length()) {
        params.Add({"figi", figi});
    }

    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }

    return handleGetRequest<OperationList>(url, "operations", token, params);
}


// User
std::pair<UserAccountList, Error> RestProvider::Accounts(const char* url) const {
    cpr::Parameters params{};

    return handleGetRequest<UserAccountList>(url, "accounts", token, params);
}