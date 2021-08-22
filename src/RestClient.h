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

#include <RestProvider.h>

#include <string>
#include <utility>
#include <vector>
#include <ctime>

class RestClient : private RestProvider {
    std::string token;
public:
    RestClient() = delete;
    RestClient(std::string&);
    RestClient(char*);
    ~RestClient();

    // Orders
    std::pair<OrderList, Error> Orders(std::string&) const;
    std::pair<PlacedOrder, Error> LimitOrder(std::string&, std::string&, int, OperationType, double) const;
    std::pair<PlacedOrder, Error> MarketOrder(std::string&, std::string&, int, OperationType) const;
    Error OrderCancel(std::string&, std::string&) const;

    // Portfolio
    std::pair<PortfolioInfo, Error> Portfolio(std::string&) const;
    std::pair<PortfolioPositionList, Error> PortfolioPositions(std::string&) const;
    std::pair<CurrencyPositionList, Error> PortfolioCurrencies(std::string&) const;

    // Market
    std::pair<MarketInstrumentList, Error> Stocks() const;
    std::pair<MarketInstrumentList, Error> Bonds() const;
    std::pair<MarketInstrumentList, Error> ETFs() const;
    std::pair<MarketInstrumentList, Error> Currencies() const;
    std::pair<OrderBook, Error> Orderbook(std::string&, int) const;
    std::pair<CandleList, Error> Candles(std::string&, time_t&, time_t&, CandleInterval&) const;
    std::pair<CandleList, Error> Candles(std::string&, std::string, std::string, CandleInterval&) const;
    std::pair<SearchMarketInstrument, Error> GetIntsrumentByFIGI(std::string&) const;
    std::pair<MarketInstrumentList, Error> GetInstrumentByTicker(std::string&) const;

    // Operations
    std::pair<OperationList, Error> Operations(std::string&, std::string&, time_t&, time_t&) const;

    // User
    std::pair<UserAccountList, Error> Accounts() const;
};