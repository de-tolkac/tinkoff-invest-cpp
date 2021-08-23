#include <SandboxRestClient.h>
#include <UrlLib.h>
#include <utils.h>
#include <Http.h>

#include <nlohmann/json.hpp>
#include <cpr/cpr.h> 

#include <string>

using Json = nlohmann::json;

SandboxRestClient::SandboxRestClient(char* _token) 
    : RestProvider(_token)
    , token(_token)
{}

SandboxRestClient::SandboxRestClient(std::string& _token) 
    : RestProvider(_token)
    , token(_token)
{}

SandboxRestClient::~SandboxRestClient() {}

std::pair<SandboxAccount, Error> SandboxRestClient::Register(BrokerAccountType t) const {
    cpr::Parameters params;
    
    std::string body = "{\"brokerAccountType\": \"" + to_string(t) + "\"}";

    return handlePostRequest<SandboxAccount>(URL::Sandbox::Register, "", token, body, params);
}

Error SandboxRestClient::SetCurrencyBalance(std::string id, Currency cur, double val) const {
    cpr::Parameters params;
    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }

    std::string body = "{\"currency\": \"";
    body += to_string(cur);
    body += "\", \"balance\": ";
    body += std::to_string(val);
    body += "}";

    return handlePostRequest(URL::Sandbox::CurrenciesBalance, "", token, body, params);
}

Error SandboxRestClient::SetPositionsBalance(std::string id, std::string figi, double val) const {
    cpr::Parameters params;
    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }

    std::string body = "{\"figi\": \"";
    body += figi;
    body += "\", \"balance\": ";
    body += std::to_string(val);
    body += "}";

    return handlePostRequest(URL::Sandbox::PositionsBalance, "", token, body, params);
}

Error SandboxRestClient::Remove(std::string id) const {
    cpr::Parameters params;
    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }

    std::string body;

    return handlePostRequest(URL::Sandbox::Remove, "", token, body, params);
}

Error SandboxRestClient::Clear(std::string id) const {
    cpr::Parameters params;
    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }

    std::string body;

    return handlePostRequest(URL::Sandbox::Clear, "", token, body, params);
}

// Orders
std::pair<OrderList, Error> SandboxRestClient::Orders(std::string id) const {
    return RestProvider::Orders(URL::Sandbox::Orders, id);
}

std::pair<PlacedOrder, Error> SandboxRestClient::LimitOrder(std::string id, std::string figi, int lots, OperationType operation, double price) const {
    return RestProvider::LimitOrder(URL::Sandbox::OrdersLimitOrder, id, figi, lots, operation, price);
}

std::pair<PlacedOrder, Error> SandboxRestClient::MarketOrder(std::string id, std::string figi, int lots, OperationType operation) const {
    return RestProvider::MarketOrder(URL::Sandbox::OrdersMarketOrder, id, figi, lots, operation);
}

Error SandboxRestClient::OrderCancel(std::string id, std::string orderId) const {
    return RestProvider::OrderCancel(URL::Sandbox::OrdersCancel, id, orderId);
}

// Portfolio
std::pair<PortfolioInfo, Error> SandboxRestClient::Portfolio(std::string id) const {
    return RestProvider::Portfolio(URL::Sandbox::Portfolio, URL::Sandbox::PortfolioCurrencies, id);
}

std::pair<PortfolioPositionList, Error> SandboxRestClient::PortfolioPositions(std::string id) const {
    return RestProvider::PortfolioPositions(URL::Sandbox::Portfolio, id);
}

std::pair<CurrencyPositionList, Error> SandboxRestClient::PortfolioCurrencies(std::string id) const {
    return RestProvider::PortfolioCurrencies(URL::Sandbox::PortfolioCurrencies, id);
}

// Market
std::pair<MarketInstrumentList, Error> SandboxRestClient::Stocks() const {
    return RestProvider::GetInstruments(URL::Sandbox::MarketStocks);
}

std::pair<MarketInstrumentList, Error> SandboxRestClient::Bonds() const {
    return RestProvider::GetInstruments(URL::Sandbox::MarketBonds);
}

std::pair<MarketInstrumentList, Error> SandboxRestClient::ETFs() const {
    return RestProvider::GetInstruments(URL::Sandbox::MarketETFs);
}

std::pair<MarketInstrumentList, Error> SandboxRestClient::Currencies() const {
    return RestProvider::GetInstruments(URL::Sandbox::MarketCurrencies);
}

std::pair<OrderBook, Error> SandboxRestClient::Orderbook(std::string figi, int depth) const {
    return RestProvider::Orderbook(URL::Sandbox::MarketOrderbook, figi, depth);
}

std::pair<CandleList, Error> SandboxRestClient::Candles(std::string figi, time_t& from, time_t& to, CandleInterval interval) const {
    std::string from_str = toString(from);
    std::string to_str = toString(to);
    return RestProvider::Candles(URL::Sandbox::MarketCandles, figi, from_str, to_str, interval);
}

std::pair<CandleList, Error> SandboxRestClient::Candles(std::string figi, std::string from, std::string to, CandleInterval interval) const {
    return RestProvider::Candles(URL::Sandbox::MarketCandles, figi, from, to, interval);
}

std::pair<SearchMarketInstrument, Error> SandboxRestClient::GetIntsrumentByFIGI(std::string figi) const {
    return RestProvider::GetIntsrumentByFIGI(URL::Sandbox::MarketSearchByFigi, figi);
}

std::pair<MarketInstrumentList, Error> SandboxRestClient::GetInstrumentByTicker(std::string ticker) const {
    return RestProvider::GetInstrumentByTicker(URL::Sandbox::MarketSearchByTicker, ticker);
}

// Operations
std::pair<OperationList, Error> SandboxRestClient::Operations(std::string id, std::string figi, time_t from, time_t to) const {
    std::string from_str = toString(from);
    std::string to_str = toString(to);
    return RestProvider::Operations(URL::Sandbox::Operations, id, figi, from_str, to_str);
}

std::pair<OperationList, Error> SandboxRestClient::Operations(std::string id, std::string figi, std::string from, std::string to) const {
    return RestProvider::Operations(URL::Sandbox::Operations, id, figi, from, to);
}

// User
std::pair<UserAccountList, Error> SandboxRestClient::Accounts() const {
    return RestProvider::Accounts(URL::Sandbox::UserAccounts);
}