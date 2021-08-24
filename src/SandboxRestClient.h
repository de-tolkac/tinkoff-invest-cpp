#pragma once

#include <SandboxAccount.h>
#include <Currency.h>
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

namespace ti {

class SandboxRestClient : private RestProvider {
    std::string token;
public:
    SandboxRestClient() = delete;
    SandboxRestClient(std::string&);
    SandboxRestClient(char*);
    ~SandboxRestClient();

    // Sandbox
    std::pair<SandboxAccount, Error> Register(BrokerAccountType) const;
    SandboxAccount Register(Error&, BrokerAccountType) const;
    void Register(SandboxAccount&, Error&, BrokerAccountType) const;

    Error SetCurrencyBalance(std::string, Currency, double) const;
    void SetCurrencyBalance(Error&, std::string, Currency, double) const;

    Error SetPositionsBalance(std::string, std::string, double) const;
    void SetPositionsBalance(Error&, std::string, std::string, double) const;
    
    Error Remove(std::string) const;
    void Remove(Error&, std::string) const;

    Error Clear(std::string) const;
    void Clear(Error&, std::string) const;


    // Orders
    std::pair<OrderList, Error> Orders(std::string) const;
    OrderList Orders(Error&, std::string) const;
    void Orders(OrderList&, Error&, std::string) const;

    std::pair<PlacedOrder, Error> LimitOrder(std::string, std::string, int, OperationType, double) const;
    PlacedOrder LimitOrder(Error&, std::string, std::string, int, OperationType, double) const;
    void LimitOrder(PlacedOrder&, Error&, std::string, std::string, int, OperationType, double) const;

    std::pair<PlacedOrder, Error> MarketOrder(std::string, std::string, int, OperationType) const;
    PlacedOrder MarketOrder(Error&, std::string, std::string, int, OperationType) const;
    void MarketOrder(PlacedOrder&, Error&, std::string, std::string, int, OperationType) const;

    Error OrderCancel(std::string, std::string) const;
    void OrderCancel(Error&, std::string, std::string) const;


    // Portfolio
    std::pair<PortfolioInfo, Error> Portfolio(std::string) const;
    PortfolioInfo Portfolio(Error&, std::string) const;
    void Portfolio(PortfolioInfo&, Error&, std::string) const;

    std::pair<PortfolioPositionList, Error> PortfolioPositions(std::string) const;
    PortfolioPositionList PortfolioPositions(Error&, std::string) const;
    void PortfolioPositions(PortfolioPositionList&, Error&, std::string) const;

    std::pair<CurrencyPositionList, Error> PortfolioCurrencies(std::string) const;
    CurrencyPositionList PortfolioCurrencies(Error&, std::string) const;
    void PortfolioCurrencies(CurrencyPositionList&, Error&, std::string) const;


    // Market
    std::pair<MarketInstrumentList, Error> Stocks() const;
    MarketInstrumentList Stocks(Error&) const;
    void Stocks(MarketInstrumentList&, Error&) const;

    std::pair<MarketInstrumentList, Error> Bonds() const;
    MarketInstrumentList Bonds(Error&) const;
    void Bonds(MarketInstrumentList&, Error&) const;

    std::pair<MarketInstrumentList, Error> ETFs() const;
    MarketInstrumentList ETFs(Error&) const;
    void ETFs(MarketInstrumentList&, Error&) const;

    std::pair<MarketInstrumentList, Error> Currencies() const;
    MarketInstrumentList Currencies(Error&) const;
    void Currencies(MarketInstrumentList&, Error&) const;

    std::pair<OrderBook, Error> Orderbook(std::string, int) const;
    OrderBook Orderbook(Error&, std::string, int) const;
    void Orderbook(OrderBook&, Error&, std::string, int) const;

    std::pair<CandleList, Error> Candles(std::string, time_t&, time_t&, CandleInterval) const;
    CandleList Candles(Error&, std::string, time_t&, time_t&, CandleInterval) const;
    void Candles(CandleList&, Error&, std::string, time_t&, time_t&, CandleInterval) const;

    std::pair<CandleList, Error> Candles(std::string, std::string, std::string, CandleInterval) const;
    CandleList Candles(Error&, std::string, std::string, std::string, CandleInterval) const;
    void Candles(CandleList&, Error&, std::string, std::string, std::string, CandleInterval) const;

    std::pair<SearchMarketInstrument, Error> GetIntsrumentByFIGI(std::string) const;
    SearchMarketInstrument GetIntsrumentByFIGI(Error&, std::string) const;
    void GetIntsrumentByFIGI(SearchMarketInstrument&, Error&, std::string) const;

    std::pair<MarketInstrumentList, Error> GetInstrumentByTicker(std::string) const;
    MarketInstrumentList GetInstrumentByTicker(Error&, std::string) const;
    void GetInstrumentByTicker(MarketInstrumentList&, Error&, std::string) const;


    // Operations
    std::pair<OperationList, Error> Operations(std::string, std::string, time_t, time_t) const;
    OperationList Operations(Error&, std::string, std::string, time_t, time_t) const;
    void Operations(OperationList&, Error&, std::string, std::string, time_t, time_t) const;

    std::pair<OperationList, Error> Operations(std::string, std::string, std::string, std::string) const;
    OperationList Operations(Error&, std::string, std::string, std::string, std::string) const;
    void Operations(OperationList&, Error&, std::string, std::string, std::string, std::string) const;


    // User
    std::pair<UserAccountList, Error> Accounts() const;
    UserAccountList Accounts(Error&) const;
    void Accounts(UserAccountList&, Error&) const;
};

}