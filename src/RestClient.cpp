#include <RestClient.h>
#include <UrlLib.h>
#include <utils.h>

namespace ti {

// Orders
std::pair<OrderList, Error> RestClient::Orders(std::string id) const {
    return RestProvider::Orders(URL::Production::Orders, id);
}

OrderList RestClient::Orders(Error& error, std::string id) const {
    auto result = RestProvider::Orders(URL::Production::Orders, id);
    error = result.second;

    return result.first;
}

void RestClient::Orders(OrderList& orders, Error& error, std::string id) const {
    auto result = RestProvider::Orders(URL::Production::Orders, id);
    error = result.second;
    orders = result.first;

    return;
}


std::pair<PlacedOrder, Error> RestClient::LimitOrder(std::string id, std::string figi, int lots, OperationType operation, double price) const {
    return RestProvider::LimitOrder(URL::Production::OrdersLimitOrder, id, figi, lots, operation, price);
}

PlacedOrder RestClient::LimitOrder(Error& error, std::string id, std::string figi, int lots, OperationType operation, double price) const {
    auto result = RestProvider::LimitOrder(URL::Production::OrdersLimitOrder, id, figi, lots, operation, price);
    error = result.second;

    return result.first;
}

void RestClient::LimitOrder(PlacedOrder& order, Error& error, std::string id, std::string figi, int lots, OperationType operation, double price) const {
    auto result = RestProvider::LimitOrder(URL::Production::OrdersLimitOrder, id, figi, lots, operation, price);
    error = result.second;
    order = result.first;

    return;
}


std::pair<PlacedOrder, Error> RestClient::MarketOrder(std::string id, std::string figi, int lots, OperationType operation) const {
    return RestProvider::MarketOrder(URL::Production::OrdersMarketOrder, id, figi, lots, operation);
}

PlacedOrder RestClient::MarketOrder(Error& error, std::string id, std::string figi, int lots, OperationType operation) const {
    auto result = RestProvider::MarketOrder(URL::Production::OrdersMarketOrder, id, figi, lots, operation);
    error = result.second;

    return result.first;
}

void RestClient::MarketOrder(PlacedOrder& order, Error& error, std::string id, std::string figi, int lots, OperationType operation) const {
    auto result = RestProvider::MarketOrder(URL::Production::OrdersMarketOrder, id, figi, lots, operation);
    error = result.second;
    order = result.first;

    return;
}


Error RestClient::OrderCancel(std::string id, std::string orderId) const {
    return RestProvider::OrderCancel(URL::Production::OrdersCancel, id, orderId);
}

void RestClient::OrderCancel(Error& error, std::string id, std::string orderId) const {
    error = RestProvider::OrderCancel(URL::Production::OrdersCancel, id, orderId);
}


// Portfolio
std::pair<PortfolioInfo, Error> RestClient::Portfolio(std::string id) const {
    return RestProvider::Portfolio(URL::Production::Portfolio, URL::Production::PortfolioCurrencies, id);
}

PortfolioInfo RestClient::Portfolio(Error& error, std::string id) const {
    auto result = RestProvider::Portfolio(URL::Production::Portfolio, URL::Production::PortfolioCurrencies, id);
    error = result.second;

    return result.first;
}

void RestClient::Portfolio(PortfolioInfo& portfolio, Error& error, std::string id) const {
    auto result = RestProvider::Portfolio(URL::Production::Portfolio, URL::Production::PortfolioCurrencies, id);
    error = result.second;
    portfolio = result.first;

    return;
}


std::pair<PortfolioPositionList, Error> RestClient::PortfolioPositions(std::string id) const {
    return RestProvider::PortfolioPositions(URL::Production::Portfolio, id);
}

PortfolioPositionList RestClient::PortfolioPositions(Error& error, std::string id) const {
    auto result = RestProvider::PortfolioPositions(URL::Production::Portfolio, id);
    error = result.second;

    return result.first;
}

void RestClient::PortfolioPositions(PortfolioPositionList& portfolio, Error& error, std::string id) const {
    auto result = RestProvider::PortfolioPositions(URL::Production::Portfolio, id);
    error = result.second;
    portfolio = result.first;

    return;
}


std::pair<CurrencyPositionList, Error> RestClient::PortfolioCurrencies(std::string id) const {
    return RestProvider::PortfolioCurrencies(URL::Production::PortfolioCurrencies, id);
}

CurrencyPositionList RestClient::PortfolioCurrencies(Error& error, std::string id) const {
    auto result = RestProvider::PortfolioCurrencies(URL::Production::PortfolioCurrencies, id);
    error = result.second;

    return result.first;
}

void RestClient::PortfolioCurrencies(CurrencyPositionList& positions, Error& error, std::string id) const {
    auto result = RestProvider::PortfolioCurrencies(URL::Production::PortfolioCurrencies, id);
    error = result.second;
    positions = result.first;

    return;
}


// Market
std::pair<MarketInstrumentList, Error> RestClient::Stocks() const {
    return RestProvider::GetInstruments(URL::Production::MarketStocks);
}

MarketInstrumentList RestClient::Stocks(Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Production::MarketStocks);
    error = result.second;

    return result.first;
}   

void RestClient::Stocks(MarketInstrumentList& instruments, Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Production::MarketStocks);
    error = result.second;
    instruments = result.first;

    return;
}


std::pair<MarketInstrumentList, Error> RestClient::Bonds() const {
    return RestProvider::GetInstruments(URL::Production::MarketBonds);
}

MarketInstrumentList RestClient::Bonds(Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Production::MarketBonds);
    error = result.second;

    return result.first;
}   

void RestClient::Bonds(MarketInstrumentList& instruments, Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Production::MarketBonds);
    error = result.second;
    instruments = result.first;
    
    return;
}


std::pair<MarketInstrumentList, Error> RestClient::ETFs() const {
    return RestProvider::GetInstruments(URL::Production::MarketETFs);
}

MarketInstrumentList RestClient::ETFs(Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Production::MarketETFs);
    error = result.second;

    return result.first;
}   

void RestClient::ETFs(MarketInstrumentList& instruments, Error& error) const {
    auto result = RestProvider::GetInstruments(URL::Production::MarketETFs);
    error = result.second;
    instruments = result.first;
    
    return;
}

}