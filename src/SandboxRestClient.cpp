#include <SandboxRestClient.h>
#include <UrlLib.h>
#include <utils.h>
#include <Http.h>

#include <nlohmann/json.hpp>
#include <cpr/cpr.h> 

#include <string>

using Json = nlohmann::json;

namespace ti {

SandboxRestClient::SandboxRestClient(char* _token) 
    : RestProvider(_token)
    , token(_token)
{}

SandboxRestClient::SandboxRestClient(std::string& _token) 
    : RestProvider(_token)
    , token(_token)
{}

SandboxRestClient::~SandboxRestClient() {}

// Sandbox routes
std::pair<SandboxAccount, Error> SandboxRestClient::Register(BrokerAccountType t) const {
    cpr::Parameters params;
    
    std::string body = "{\"brokerAccountType\": \"" + to_string(t) + "\"}";

    return handlePostRequest<SandboxAccount>(URL::Sandbox::Register, "", token, body, params);
}

SandboxAccount SandboxRestClient::Register(Error& error, BrokerAccountType t) const {
    SandboxAccount result;

    cpr::Parameters params;
    
    std::string body = "{\"brokerAccountType\": \"" + to_string(t) + "\"}";

    handlePostRequest<SandboxAccount>(result, error, URL::Sandbox::Register, "", token, body, params);

    return result;
}

void SandboxRestClient::Register(SandboxAccount& account, Error& error, BrokerAccountType t) const {
    cpr::Parameters params;
    
    std::string body = "{\"brokerAccountType\": \"" + to_string(t) + "\"}";

    handlePostRequest<SandboxAccount>(account, error, URL::Sandbox::Register, "", token, body, params);

    return;
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

void SandboxRestClient::SetCurrencyBalance(Error& error, std::string id , Currency cur, double val) const {
    cpr::Parameters params;
    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }

    std::string body = "{\"currency\": \"";
    body += to_string(cur);
    body += "\", \"balance\": ";
    body += std::to_string(val);
    body += "}";

    handlePostRequest(error, URL::Sandbox::CurrenciesBalance, "", token, body, params);

    return;
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

void SandboxRestClient::SetPositionsBalance(Error& error, std::string id , std::string figi, double val) const {
    cpr::Parameters params;
    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }

    std::string body = "{\"figi\": \"";
    body += figi;
    body += "\", \"balance\": ";
    body += std::to_string(val);
    body += "}";

    handlePostRequest(error, URL::Sandbox::PositionsBalance, "", token, body, params);

    return;
}


Error SandboxRestClient::Remove(std::string id) const {
    cpr::Parameters params;
    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }

    std::string body;

    return handlePostRequest(URL::Sandbox::Remove, "", token, body, params);
}

void SandboxRestClient::Remove(Error& error, std::string id) const {
    cpr::Parameters params;
    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }

    std::string body;

    handlePostRequest(error, URL::Sandbox::Remove, "", token, body, params);

    return;
}


Error SandboxRestClient::Clear(std::string id) const {
    cpr::Parameters params;
    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }

    std::string body;

    return handlePostRequest(URL::Sandbox::Clear, "", token, body, params);
}

void SandboxRestClient::Clear(Error& error, std::string id) const {
    cpr::Parameters params;
    if (id.length()) {
        params.Add({"brokerAccountId", id});
    }

    std::string body;

    handlePostRequest(error, URL::Sandbox::Clear, "", token, body, params);

    return;
}


// Orders
std::pair<OrderList, Error> SandboxRestClient::Orders(std::string id) const {
    return RestProvider::Orders(URL::Sandbox::Orders, id);
}

OrderList SandboxRestClient::Orders(Error& error, std::string id) const {
    auto result = RestProvider::Orders(URL::Sandbox::Orders, id);
    error = result.second;

    return result.first;
}

void SandboxRestClient::Orders(OrderList& orders, Error& error, std::string id) const {
    auto result = RestProvider::Orders(URL::Sandbox::Orders, id);
    error = result.second;
    orders = result.first;

    return;
}


std::pair<PlacedOrder, Error> SandboxRestClient::LimitOrder(std::string id, std::string figi, int lots, OperationType operation, double price) const {
    return RestProvider::LimitOrder(URL::Sandbox::OrdersLimitOrder, id, figi, lots, operation, price);
}

PlacedOrder SandboxRestClient::LimitOrder(Error& error, std::string id, std::string figi, int lots, OperationType operation, double price) const {
    auto result = RestProvider::LimitOrder(URL::Sandbox::OrdersLimitOrder, id, figi, lots, operation, price);
    error = result.second;

    return result.first;
}

void SandboxRestClient::LimitOrder(PlacedOrder& order, Error& error, std::string id, std::string figi, int lots, OperationType operation, double price) const {
    auto result = RestProvider::LimitOrder(URL::Sandbox::OrdersLimitOrder, id, figi, lots, operation, price);
    error = result.second;
    order = result.first;

    return;
}


std::pair<PlacedOrder, Error> SandboxRestClient::MarketOrder(std::string id, std::string figi, int lots, OperationType operation) const {
    return RestProvider::MarketOrder(URL::Sandbox::OrdersMarketOrder, id, figi, lots, operation);
}

PlacedOrder SandboxRestClient::MarketOrder(Error& error, std::string id, std::string figi, int lots, OperationType operation) const {
    auto result = RestProvider::MarketOrder(URL::Sandbox::OrdersMarketOrder, id, figi, lots, operation);
    error = result.second;

    return result.first;
}

void SandboxRestClient::MarketOrder(PlacedOrder& order, Error& error, std::string id, std::string figi, int lots, OperationType operation) const {
    auto result = RestProvider::MarketOrder(URL::Sandbox::OrdersMarketOrder, id, figi, lots, operation);
    error = result.second;
    order = result.first;

    return;
}


Error SandboxRestClient::OrderCancel(std::string id, std::string orderId) const {
    return RestProvider::OrderCancel(URL::Sandbox::OrdersCancel, id, orderId);
}

void SandboxRestClient::OrderCancel(Error& error, std::string id, std::string orderId) const {
    error = RestProvider::OrderCancel(URL::Sandbox::OrdersCancel, id, orderId);
}


// Portfolio
std::pair<PortfolioInfo, Error> SandboxRestClient::Portfolio(std::string id) const {
    return RestProvider::Portfolio(URL::Sandbox::Portfolio, URL::Sandbox::PortfolioCurrencies, id);
}

PortfolioInfo SandboxRestClient::Portfolio(Error& error, std::string id) const {
    auto result = RestProvider::Portfolio(URL::Sandbox::Portfolio, URL::Sandbox::PortfolioCurrencies, id);
    error = result.second;

    return result.first;
}

void SandboxRestClient::Portfolio(PortfolioInfo& portfolio, Error& error, std::string id) const {
    auto result = RestProvider::Portfolio(URL::Sandbox::Portfolio, URL::Sandbox::PortfolioCurrencies, id);
    error = result.second;
    portfolio = result.first;

    return;
}


std::pair<PortfolioPositionList, Error> SandboxRestClient::PortfolioPositions(std::string id) const {
    return RestProvider::PortfolioPositions(URL::Sandbox::Portfolio, id);
}

PortfolioPositionList SandboxRestClient::PortfolioPositions(Error& error, std::string id) const {
    auto result = RestProvider::PortfolioPositions(URL::Sandbox::Portfolio, id);
    error = result.second;

    return result.first;
}

void SandboxRestClient::PortfolioPositions(PortfolioPositionList& portfolio, Error& error, std::string id) const {
    auto result = RestProvider::PortfolioPositions(URL::Sandbox::Portfolio, id);
    error = result.second;
    portfolio = result.first;

    return;
}


std::pair<CurrencyPositionList, Error> SandboxRestClient::PortfolioCurrencies(std::string id) const {
    return RestProvider::PortfolioCurrencies(URL::Sandbox::PortfolioCurrencies, id);
}

CurrencyPositionList SandboxRestClient::PortfolioCurrencies(Error& error, std::string id) const {
    auto result = RestProvider::PortfolioCurrencies(URL::Sandbox::PortfolioCurrencies, id);
    error = result.second;

    return result.first;
}

void SandboxRestClient::PortfolioCurrencies(CurrencyPositionList& positions, Error& error, std::string id) const {
    auto result = RestProvider::PortfolioCurrencies(URL::Sandbox::PortfolioCurrencies, id);
    error = result.second;
    positions = result.first;

    return;
}


// Market
std::pair<MarketInstrumentList, Error> SandboxRestClient::Stocks() const {
    return RestProvider::GetInstruments(URL::Sandbox::MarketStocks);
}

MarketInstrumentList SandboxRestClient::Stocks(Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Sandbox::MarketStocks);
    error = result.second;

    return result.first;
}   

void SandboxRestClient::Stocks(MarketInstrumentList& instruments, Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Sandbox::MarketStocks);
    error = result.second;
    instruments = result.first;

    return;
}


std::pair<MarketInstrumentList, Error> SandboxRestClient::Bonds() const {
    return RestProvider::GetInstruments(URL::Sandbox::MarketBonds);
}

MarketInstrumentList SandboxRestClient::Bonds(Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Sandbox::MarketBonds);
    error = result.second;

    return result.first;
}   

void SandboxRestClient::Bonds(MarketInstrumentList& instruments, Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Sandbox::MarketBonds);
    error = result.second;
    instruments = result.first;
    
    return;
}


std::pair<MarketInstrumentList, Error> SandboxRestClient::ETFs() const {
    return RestProvider::GetInstruments(URL::Sandbox::MarketETFs);
}

MarketInstrumentList SandboxRestClient::ETFs(Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Sandbox::MarketETFs);
    error = result.second;

    return result.first;
}   

void SandboxRestClient::ETFs(MarketInstrumentList& instruments, Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Sandbox::MarketETFs);
    error = result.second;
    instruments = result.first;
    
    return;
}


std::pair<MarketInstrumentList, Error> SandboxRestClient::Currencies() const {
    return RestProvider::GetInstruments(URL::Sandbox::MarketCurrencies);
}

MarketInstrumentList SandboxRestClient::Currencies(Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Sandbox::MarketCurrencies);
    error = result.second;

    return result.first;
}   

void SandboxRestClient::Currencies(MarketInstrumentList& instruments, Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Sandbox::MarketCurrencies);
    error = result.second;
    instruments = result.first;
    
    return;
}


std::pair<OrderBook, Error> SandboxRestClient::Orderbook(std::string figi, int depth) const {
    return RestProvider::Orderbook(URL::Sandbox::MarketOrderbook, figi, depth);
}

OrderBook SandboxRestClient::Orderbook(Error& error, std::string figi, int depth) const {
    auto result = RestProvider::Orderbook(URL::Sandbox::MarketOrderbook, figi, depth);
    error = result.second;

    return result.first;
}

void SandboxRestClient::Orderbook(OrderBook& orderBook, Error& error, std::string figi, int depth) const {
    auto result = RestProvider::Orderbook(URL::Sandbox::MarketOrderbook, figi, depth);
    error = result.second;
    orderBook = result.first;

    return;
}


std::pair<CandleList, Error> SandboxRestClient::Candles(std::string figi, time_t& from, time_t& to, CandleInterval interval) const {
    std::string from_str = toString(from);
    std::string to_str = toString(to);
    return RestProvider::Candles(URL::Sandbox::MarketCandles, figi, from_str, to_str, interval);
}

CandleList SandboxRestClient::Candles(Error& error, std::string figi, time_t& from, time_t& to, CandleInterval interval) const {
    std::string from_str = toString(from);
    std::string to_str = toString(to);

    auto result = RestProvider::Candles(URL::Sandbox::MarketCandles, figi, from_str, to_str, interval);
    error = result.second;

    return result.first;
}

void SandboxRestClient::Candles(CandleList& candles, Error& error, std::string figi, time_t& from, time_t& to, CandleInterval interval) const {
    std::string from_str = toString(from);
    std::string to_str = toString(to);

    auto result = RestProvider::Candles(URL::Sandbox::MarketCandles, figi, from_str, to_str, interval);
    error = result.second;
    candles = result.first;

    return;
}



std::pair<CandleList, Error> SandboxRestClient::Candles(std::string figi, std::string from, std::string to, CandleInterval interval) const {
    return RestProvider::Candles(URL::Sandbox::MarketCandles, figi, from, to, interval);
}

CandleList SandboxRestClient::Candles(Error& error, std::string figi, std::string from, std::string to, CandleInterval interval) const {
    auto result = RestProvider::Candles(URL::Sandbox::MarketCandles, figi, from, to, interval);
    error = result.second;

    return result.first;
}

void SandboxRestClient::Candles(CandleList& candles, Error& error, std::string figi, std::string from, std::string to, CandleInterval interval) const {
    auto result = RestProvider::Candles(URL::Sandbox::MarketCandles, figi, from, to, interval);
    error = result.second;
    candles = result.first;

    return;
}


std::pair<SearchMarketInstrument, Error> SandboxRestClient::GetIntsrumentByFIGI(std::string figi) const {
    return RestProvider::GetIntsrumentByFIGI(URL::Sandbox::MarketSearchByFigi, figi);
}

SearchMarketInstrument SandboxRestClient::GetIntsrumentByFIGI(Error& error, std::string figi) const {
    auto result = RestProvider::GetIntsrumentByFIGI(URL::Sandbox::MarketSearchByFigi, figi);
    error = result.second;

    return result.first;
}

void SandboxRestClient::GetIntsrumentByFIGI(SearchMarketInstrument& instruments, Error& error, std::string figi) const {
    auto result = RestProvider::GetIntsrumentByFIGI(URL::Sandbox::MarketSearchByFigi, figi);
    error = result.second;
    instruments = result.first;
    
    return;
}


std::pair<MarketInstrumentList, Error> SandboxRestClient::GetInstrumentByTicker(std::string ticker) const {
    return RestProvider::GetInstrumentByTicker(URL::Sandbox::MarketSearchByTicker, ticker);
}

MarketInstrumentList SandboxRestClient::GetInstrumentByTicker(Error& error, std::string ticker) const {
    auto result = RestProvider::GetInstrumentByTicker(URL::Sandbox::MarketSearchByTicker, ticker);
    error = result.second;

    return result.first;
}

void SandboxRestClient::GetInstrumentByTicker(MarketInstrumentList& instruments, Error& error, std::string ticker) const {
    auto result = RestProvider::GetInstrumentByTicker(URL::Sandbox::MarketSearchByTicker, ticker);
    error = result.second;
    instruments = result.first;
    
    return;
}


// Operations
std::pair<OperationList, Error> SandboxRestClient::Operations(std::string id, std::string figi, time_t from, time_t to) const {
    std::string from_str = toString(from);
    std::string to_str = toString(to);
    return RestProvider::Operations(URL::Sandbox::Operations, id, figi, from_str, to_str);
}

OperationList SandboxRestClient::Operations(Error& error, std::string id, std::string figi, time_t from, time_t to) const {
    std::string from_str = toString(from);
    std::string to_str = toString(to);
    
    auto result = RestProvider::Operations(URL::Sandbox::Operations, id, figi, from_str, to_str);
    error = result.second;

    return result.first;
}

void SandboxRestClient::Operations(OperationList& operations, Error& error, std::string id, std::string figi, time_t from, time_t to) const {
    std::string from_str = toString(from);
    std::string to_str = toString(to);
    
    auto result = RestProvider::Operations(URL::Sandbox::Operations, id, figi, from_str, to_str);
    error = result.second;
    operations = result.first;

    return;
}



std::pair<OperationList, Error> SandboxRestClient::Operations(std::string id, std::string figi, std::string from, std::string to) const {
    return RestProvider::Operations(URL::Sandbox::Operations, id, figi, from, to);
}

OperationList SandboxRestClient::Operations(Error& error, std::string id, std::string figi, std::string from, std::string to) const {
    auto result = RestProvider::Operations(URL::Sandbox::Operations, id, figi, from, to);
    error = result.second;

    return result.first;
}

void SandboxRestClient::Operations(OperationList& operations, Error& error, std::string id, std::string figi, std::string from, std::string to) const {
    auto result = RestProvider::Operations(URL::Sandbox::Operations, id, figi, from, to);
    error = result.second;
    operations = result.first;

    return;
}


// User
std::pair<UserAccountList, Error> SandboxRestClient::Accounts() const {
    return RestProvider::Accounts(URL::Sandbox::UserAccounts);
}

UserAccountList SandboxRestClient::Accounts(Error& error) const {
    auto result = RestProvider::Accounts(URL::Sandbox::UserAccounts);
    error = result.second;

    return result.first;
}

void SandboxRestClient::Accounts(UserAccountList& accounts, Error& error) const {
    auto result = RestProvider::Accounts(URL::Sandbox::UserAccounts);
    error = result.second;
    accounts = result.first;
    
    return;
}

}