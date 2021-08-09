#pragma once

#include <SandboxAccount.h>
#include <Currency.h>
#include <Order.h>
#include <OperationType.h>
#include <PlacedLimitOrder.h>
#include <PlacedMarketOrder.h>
#include <PortfolioPosition.h>
#include <CurrencyPosition.h>
#include <Portfolio.h>
#include <MarketInstrument.h>
#include <OrderBook.h>
#include <CandleInterval.h>
#include <Candle.h>
#include <SearchMarketInstrument.h>

#include <string>
#include <utility>
#include <vector>
#include <ctime>

class SandboxRestClient {
    std::string token;
public:
    SandboxRestClient() = delete;
    SandboxRestClient(std::string&);
    SandboxRestClient(char*);
    ~SandboxRestClient();

    // Sandbox
    std::pair<SandboxAccount, Error> Register(BrokerAccountType);
    Error SetCurrencyBalance(std::string&, Currency, double);
    Error SetPositionsBalance(std::string&, std::string, double);
    Error Remove(std::string&);
    Error Clear(std::string&);

    // Orders
    std::pair<std::vector<Order>, Error> Orders(std::string&);
    std::pair<PlacedLimitOrder, Error> LimitOrder(std::string&, std::string&, int, OperationType, double);
    std::pair<PlacedMarketOrder, Error> MarketOrder(std::string&, std::string&, int, OperationType);
    Error OrderCancel(std::string&, std::string&);

    // Portfolio
    std::pair<PortfolioInfo, Error> Portfolio(std::string&);
    std::pair<std::vector<PortfolioPosition>, Error> PortfolioPositions(std::string&);
    std::pair<std::vector<CurrencyPosition>, Error> PortfolioCurrencies(std::string&);

    // Market
    std::pair<std::vector<MarketInstrument>, Error> Stocks();
    std::pair<std::vector<MarketInstrument>, Error> Bonds();
    std::pair<std::vector<MarketInstrument>, Error> ETFs();
    std::pair<std::vector<MarketInstrument>, Error> Currencies();
    std::pair<OrderBook, Error> Orderbook(std::string&, int);
    std::pair<std::vector<Candle>, Error> Candles(std::string&, time_t&, time_t&, CandleInterval&);
    std::pair<SearchMarketInstrument, Error> GetIntsrumentByFIGI(std::string&);
    std::pair<std::vector<MarketInstrument>, Error> GetInstrumentByTicker(std::string&);
};