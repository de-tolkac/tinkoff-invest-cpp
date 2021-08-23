#include <tinvest/OpenAPI.h>

#include <iostream>
#include <fstream>
#include <climits>

int main() {
    std::string token;
    
    std::ifstream file("token.txt");
    file >> token;
    file.close();
    
    SandboxRestClient sandboxRest(token);

    // Регистрация клиента в sandbox [SANDBOX]
    auto [account, err] = sandboxRest.Register(BrokerAccountType::Tinkoff);
    if (err) {
        std::cout << "Error 1: " << err.message << std::endl;
    } else {
        std::cout << "Account id: " << account.brokerAccountId << std::endl << std::endl;
    }


    // Получение брокерских счетов клиента 
    UserAccountList userAccounts;
    std::tie(userAccounts, err) = sandboxRest.Accounts();
    if (err) {
        std::cout << "Error 2: " << err.message << std::endl;
    }


    // Выставление баланса по валютным позициям [SANDBOX]
    err = sandboxRest.SetCurrencyBalance(account.brokerAccountId, Currency::USD, 250000);
    if (err) {
        std::cout << "Error 3: " << err.message << std::endl;
    }


    // Выставление баланса по инструментным позициям [SANDBOX]
    err = sandboxRest.SetPositionsBalance(account.brokerAccountId, "BBG005DXJS36", 10000);
    if (err) {
        std::cout << "Error 4: " << err.message << std::endl;
    }
    

    // Создание лимитной заявки
    PlacedOrder limitOrder;
    std::tie(limitOrder, err) = sandboxRest.LimitOrder(account.brokerAccountId, "BBG005DXJS36", 10, OperationType::Buy, 1.0);
    if (err) {
        std::cout << "Error 5: " << err.message << std::endl;
    } else {
        std::cout << "Placed limit order: " << limitOrder.orderId << std::endl << std::endl;
    }


    // Создание рыночной заявки
    PlacedOrder marketOrder;
    std::tie(marketOrder, err) = sandboxRest.MarketOrder(account.brokerAccountId, "BBG005DXJS36", 10, OperationType::Buy);
    if (err) {
        std::cout << "Error 6: " << err.message << " " << err.code << std::endl;
    } else {
        std::cout << "Placed market order: " << marketOrder.orderId << std::endl << std::endl;
    }


    // Отмена заявки
    err = sandboxRest.OrderCancel(account.brokerAccountId, "order-id-string");
    if (err) {
        std::cout << "Order cancelation error!" << std::endl;
    }


    // Получение списка активных заявок
    OrderList orders;
    std::tie(orders, err) = sandboxRest.Orders(account.brokerAccountId);
    if (err) {
        std::cout << "Error 7: " << err.message << std::endl;
    } else {
        std::cout << "Orders total: " << orders.size() << std::endl;
        for (const auto& o : orders) {
            std::cout << o.figi << ": " << o.requestedLots << "\n";
        }
        std::cout << std::endl;
    }
    

    // Получение инструментальных активов клиента
    PortfolioPositionList positions;
    std::tie(positions, err) = sandboxRest.PortfolioPositions(account.brokerAccountId);
    if (err) {
        std::cout << "Error 8: " << err.message << std::endl;
    } else {
        std::cout << "Positions total: " << positions.size() << std::endl;
        for (const auto& p : positions) {
            std::cout << p.name << ": " << p.lots << "\n";
        }
        std::cout << std::endl;
    }


    // Получение валютных активов клиента
    CurrencyPositionList currencies;
    std::tie(currencies, err) = sandboxRest.PortfolioCurrencies(account.brokerAccountId);
    if (err) {
        std::cout << "Error 9: " << err.message << std::endl;
    } else {
        std::cout << "Currencies total: " << currencies.size() << std::endl;
        for (const auto& c : currencies) {
            std::cout << to_string(c.currency) << ": " << c.balance << "\n";
        }
        std::cout << std::endl;
    }


    // Получение всех активов клиента (PortfolioPosition + PortfolioCurrencies)
    PortfolioInfo portfolio;
    std::tie(portfolio, err) = sandboxRest.Portfolio(account.brokerAccountId);
    if (err) {
        std::cout << "Error 10: " << err.message << std::endl;
    } else {
        std::cout << "Positions total: " << portfolio.positions.size() << std::endl;
        std::cout << "Currencies total: " << portfolio.currencies.size() << std::endl << std::endl;
    }


    // Получение списка акций
    MarketInstrumentList stocks;
    std::tie(stocks, err) = sandboxRest.Stocks();
    if (err) {
        std::cout << "Error 11: " << err.message << std::endl;
    } else {
        std::cout << "Total stocks: " << stocks.size() << std::endl;
    }


    // Получение списка облигаций
    MarketInstrumentList bonds;
    std::tie(bonds, err) = sandboxRest.Bonds();
    if (err) {
        std::cout << "Error 12: " << err.message << std::endl;
    } else {
        std::cout << "Total bonds: " << bonds.size() << std::endl;
    }


    // Получение списка ETF
    MarketInstrumentList etfs;
    std::tie(etfs, err) = sandboxRest.ETFs();
    if (err) {
        std::cout << "Error 13: " << err.message << std::endl;
    } else {
        std::cout << "Total etfs: " << etfs.size() << std::endl;
    }


    // Получение списка валютных пар
    MarketInstrumentList currenciesList;
    std::tie(currenciesList, err) = sandboxRest.Currencies();
    if (err) {
        std::cout << "Error 14: " << err.message << std::endl;
    } else {
        std::cout << "Total currencies: " << currenciesList.size() << std::endl << std::endl;
    }


    // Получение стакана по FIGI
    OrderBook orderBook;
    std::tie(orderBook, err) = sandboxRest.Orderbook("BBG005DXJS36", 10);
    if (err) {
        std::cout << "Error 15: " << err.message << std::endl;
    } else {
        std::cout << orderBook.figi << ": " << to_string(orderBook.tradeStatus) << std::endl << std::endl;
    }


    // Получение исторических свечей по FIGI
    CandleList candles;
    std::tie(candles, err) = sandboxRest.Candles("BBG005DXJS36", "2019-08-19T18:38:33+03:00", 
                                                    "2019-08-19T18:40:33+03:00", CandleInterval::_1min);
    if (err) {
        std::cout << "Error 16: " << err.message << std::endl;
    } else {
        std::cout << "Total candles: " << candles.size() << std::endl << std::endl;;
    }


    // Получение инструмента по FIGI
    SearchMarketInstrument instrument;
    std::tie(instrument, err) = sandboxRest.GetIntsrumentByFIGI("BBG005DXJS36");
    if (err) {
        std::cout << "Error 17: " << err.message << std::endl;
    } else {
        std::cout << instrument.figi << " " << instrument.ticker << " " << instrument.name << std::endl << std::endl;
    }


    // Получение инструмента по тикеру
    MarketInstrumentList instrumentList;
    std::tie(instrumentList, err) = sandboxRest.GetInstrumentByTicker("TCS");
    if (err) {
        std::cout << "Error 18: " << err.message << std::endl;
    } else {
        std::cout << "Instruments found: " << instrumentList.size() << std::endl << std::endl;
    }


    // Получение списка операций
    OperationList operations;
    std::tie(operations, err) = sandboxRest.Operations(account.brokerAccountId, "BBG005DXJS36", 
                                                        "2019-08-19T18:38:33+03:00", "2019-08-19T18:40:33+03:00");
    if (err) {
        std::cout << "Error 19: " << err.message << std::endl;
    } else {
        std::cout << "Operations found: " << operations.size() << std::endl << std::endl;
    }


    // Удаление всех позиций [SANDBOX]
    err = sandboxRest.Clear(account.brokerAccountId);
    if (err) {
        std::cout << "Error 20: " << err.message << std::endl;
    }


    // Удаление счета [SANDBOX]
    err = sandboxRest.Remove(account.brokerAccountId);
    if (err) {
        std::cout << "Error 21: " << err.message << std::endl;
    } else {
        std::cout << "Account " << account.brokerAccountId << " removed\n";
    }
    return 0;
}