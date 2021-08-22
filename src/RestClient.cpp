#include <RestClient.h>
#include <UrlLib.h>
#include <utils.h>

// Orders
std::pair<OrderList, Error> RestClient::Orders(std::string& id) const {
    return RestProvider::Orders(URL::Production::Orders, id);
}

std::pair<PlacedOrder, Error> RestClient::LimitOrder(std::string& id, std::string& figi, int lots, OperationType operation, double price) const {
    return RestProvider::LimitOrder(URL::Production::OrdersLimitOrder, id, figi, lots, operation, price);
}

std::pair<PlacedOrder, Error> RestClient::MarketOrder(std::string& id, std::string& figi, int lots, OperationType operation) const {
    return RestProvider::MarketOrder(URL::Production::OrdersMarketOrder, id, figi, lots, operation);
}

Error RestClient::OrderCancel(std::string& id, std::string& orderId) const {
    return RestProvider::OrderCancel(URL::Production::OrdersCancel, id, orderId);
}


// Portfolio
std::pair<PortfolioInfo, Error> RestClient::Portfolio(std::string& id) const {
    return RestProvider::Portfolio(URL::Production::Portfolio, URL::Production::PortfolioCurrencies, id);
}

std::pair<PortfolioPositionList, Error> RestClient::PortfolioPositions(std::string& id) const {
    return RestProvider::PortfolioPositions(URL::Production::Portfolio, id);
}

std::pair<CurrencyPositionList, Error> RestClient::PortfolioCurrencies(std::string& id) const {
    return RestProvider::PortfolioCurrencies(URL::Production::PortfolioCurrencies, id);
}


// Market
std::pair<MarketInstrumentList, Error> RestClient::Stocks() const {
    return RestProvider::GetInstruments(URL::Production::MarketStocks);
}

std::pair<MarketInstrumentList, Error> RestClient::Bonds() const {
    return RestProvider::GetInstruments(URL::Production::MarketBonds);
}

std::pair<MarketInstrumentList, Error> RestClient::ETFs() const {
    return RestProvider::GetInstruments(URL::Production::MarketETFs);
}

std::pair<MarketInstrumentList, Error> RestClient::Currencies() const {
    return RestProvider::GetInstruments(URL::Production::MarketCurrencies);
}

std::pair<OrderBook, Error> RestClient::Orderbook(std::string& figi, int depth) const {
    return RestProvider::Orderbook(URL::Production::MarketOrderbook, figi, depth);
}

std::pair<CandleList, Error> RestClient::Candles(std::string& figi, time_t& from, time_t& to, CandleInterval& interval) const {
    std::string from_str = toString(from);
    std::string to_str = toString(to);
    return RestProvider::Candles(URL::Production::MarketCandles, figi, from_str, to_str, interval);
}

std::pair<CandleList, Error> RestClient::Candles(std::string& figi, std::string from, std::string to, CandleInterval& interval) const {
    return RestProvider::Candles(URL::Production::MarketCandles, figi, from, to, interval);
}

std::pair<SearchMarketInstrument, Error> RestClient::GetIntsrumentByFIGI(std::string& figi) const {
    return RestProvider::GetIntsrumentByFIGI(URL::Production::MarketSearchByFigi, figi);
}

std::pair<MarketInstrumentList, Error> RestClient::GetInstrumentByTicker(std::string& ticker) const {
    return RestProvider::GetInstrumentByTicker(URL::Production::MarketSearchByTicker, ticker);
}


// Operations
std::pair<OperationList, Error> RestClient::Operations(std::string& id, std::string& figi, time_t& from, time_t& to) const {
    std::string from_str = toString(from);
    std::string to_str = toString(to);
    return RestProvider::Operations(URL::Production::Operations, id, figi, from_str, to_str);
}


// User
std::pair<UserAccountList, Error> RestClient::Accounts() const {
    return RestProvider::Accounts(URL::Production::UserAccounts);
}