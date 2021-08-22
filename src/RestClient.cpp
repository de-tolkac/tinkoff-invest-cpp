#include <RestClient.h>
#include <UrlLib.h>
#include <utils.h>

// Orders
std::pair<std::vector<Order>, Error> RestClient::Orders(std::string& id) const {
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

std::pair<std::vector<PortfolioPosition>, Error> RestClient::PortfolioPositions(std::string& id) const {
    return RestProvider::PortfolioPositions(URL::Production::Portfolio, id);
}

std::pair<std::vector<CurrencyPosition>, Error> RestClient::PortfolioCurrencies(std::string& id) const {
    return RestProvider::PortfolioCurrencies(URL::Production::PortfolioCurrencies, id);
}


// Market
std::pair<std::vector<MarketInstrument>, Error> RestClient::Stocks() const {
    return RestProvider::Stocks(URL::Production::MarketStocks);
}

std::pair<std::vector<MarketInstrument>, Error> RestClient::Bonds() const {
    return RestProvider::Bonds(URL::Production::MarketBonds);
}

std::pair<std::vector<MarketInstrument>, Error> RestClient::ETFs() const {
    return RestProvider::ETFs(URL::Production::MarketETFs);
}

std::pair<std::vector<MarketInstrument>, Error> RestClient::Currencies() const {
    return RestProvider::Currencies(URL::Production::MarketCurrencies);
}

std::pair<OrderBook, Error> RestClient::Orderbook(std::string& figi, int depth) const {
    return RestProvider::Orderbook(URL::Production::MarketOrderbook, figi, depth);
}

std::pair<std::vector<Candle>, Error> RestClient::Candles(std::string& figi, time_t& from, time_t& to, CandleInterval& interval) const {
    std::string from_str = toString(from);
    std::string to_str = toString(to);
    return RestProvider::Candles(URL::Production::MarketCandles, figi, from_str, to_str, interval);
}

std::pair<SearchMarketInstrument, Error> RestClient::GetIntsrumentByFIGI(std::string& figi) const {
    return RestProvider::GetIntsrumentByFIGI(URL::Production::MarketSearchByFigi, figi);
}

std::pair<std::vector<MarketInstrument>, Error> RestClient::GetInstrumentByTicker(std::string& ticker) const {
    return RestProvider::GetInstrumentByTicker(URL::Production::MarketSearchByTicker, ticker);
}


// Operations
std::pair<std::vector<Operation>, Error> RestClient::Operations(std::string& id, std::string& figi, time_t& from, time_t& to) const {
    return RestProvider::Operations(URL::Production::Operations, id, figi, from, to);
}


// User
std::pair<std::vector<UserAccount>, Error> RestClient::Accounts() const {
    return RestProvider::Accounts(URL::Production::UserAccounts);
}