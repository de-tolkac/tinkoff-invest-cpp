#pragma once

#include <Order.h>
#include <OperationType.h>
#include <PlacedOrder.h>
#include <PortfolioPosition.h>
#include <CurrencyPosition.h>
#include <Portfolio.h>
#include <MarketInstrument.h>
#include <OrderBook.h>
#include <CandleInterval.h>
#include <Candle.h>
#include <SearchMarketInstrument.h>
#include <Operation.h>
#include <UserAccount.h>

#include <string>
#include <utility>
#include <vector>
#include <ctime>

class RestProvider {
    std::string token;
private:
    template<typename T>
    void handleStatusCode500(std::pair<T, Error>&, std::string&) const;

    void handleStatusCode500(Error&, std::string&) const;
protected:
    RestProvider() = delete;
    RestProvider(std::string&);
    RestProvider(char*);

    // Orders
    std::pair<std::vector<Order>, Error> Orders(const char*, std::string&) const;
    std::pair<PlacedOrder, Error> LimitOrder(const char*, std::string&, std::string&, int, OperationType, double) const;
    std::pair<PlacedOrder, Error> MarketOrder(const char*, std::string&, std::string&, int, OperationType) const;
    Error OrderCancel(const char*, std::string&, std::string&) const;

    // Portfolio
    std::pair<PortfolioInfo, Error> Portfolio(const char*, const char*, std::string&) const;
    std::pair<std::vector<PortfolioPosition>, Error> PortfolioPositions(const char*, std::string&) const;
    std::pair<std::vector<CurrencyPosition>, Error> PortfolioCurrencies(const char*, std::string&) const;

    // Market
    std::pair<MarketInstrumentList, Error> GetInstruments(const char*) const; 
    std::pair<std::vector<MarketInstrument>, Error> Stocks(const char*) const;
    std::pair<std::vector<MarketInstrument>, Error> Bonds(const char*) const;
    std::pair<std::vector<MarketInstrument>, Error> ETFs(const char*) const;
    std::pair<std::vector<MarketInstrument>, Error> Currencies(const char*) const;
    std::pair<OrderBook, Error> Orderbook(const char*, std::string&, int) const;
    std::pair<std::vector<Candle>, Error> Candles(const char*, std::string&, std::string&, std::string&, CandleInterval&) const;
    std::pair<SearchMarketInstrument, Error> GetIntsrumentByFIGI(const char*, std::string&) const;
    std::pair<std::vector<MarketInstrument>, Error> GetInstrumentByTicker(const char*, std::string&) const;

    // Operations
    std::pair<std::vector<Operation>, Error> Operations(const char*, std::string&, std::string&, time_t&, time_t&) const;

    // User
    std::pair<std::vector<UserAccount>, Error> Accounts(const char*) const;
};