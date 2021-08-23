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
protected:
    RestProvider() = delete;
    RestProvider(std::string&);
    RestProvider(char*);

    // Orders
    std::pair<OrderList, Error> Orders(const char*, std::string&) const;
    std::pair<PlacedOrder, Error> LimitOrder(const char*, std::string&, std::string&, int, OperationType, double) const;
    std::pair<PlacedOrder, Error> MarketOrder(const char*, std::string&, std::string&, int, OperationType) const;
    Error OrderCancel(const char*, std::string&, std::string&) const;

    // Portfolio
    std::pair<PortfolioInfo, Error> Portfolio(const char*, const char*, std::string&) const;
    std::pair<PortfolioPositionList, Error> PortfolioPositions(const char*, std::string&) const;
    std::pair<CurrencyPositionList, Error> PortfolioCurrencies(const char*, std::string&) const;

    // Market
    std::pair<MarketInstrumentList, Error> GetInstruments(const char*) const; 
    std::pair<OrderBook, Error> Orderbook(const char*, std::string&, int) const;
    std::pair<CandleList, Error> Candles(const char*, std::string&, std::string&, std::string&, CandleInterval&) const;
    std::pair<SearchMarketInstrument, Error> GetIntsrumentByFIGI(const char*, std::string&) const;
    std::pair<MarketInstrumentList, Error> GetInstrumentByTicker(const char*, std::string&) const;

    // Operations
    std::pair<OperationList, Error> Operations(const char*, std::string&, std::string&, std::string&, std::string&) const;

    // User
    std::pair<UserAccountList, Error> Accounts(const char*) const;
};