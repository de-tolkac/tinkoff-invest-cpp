#include <tinvest/OpenAPI.h>

#include <iostream>
#include <fstream>

using namespace ti;

int main() {
    std::string token;
    
    std::ifstream file("token.txt");
    file >> token;
    file.close();
    
    SandboxRestClient sandboxRest(token);

    Error err;

    // Регистрация клиента в sandbox [SANDBOX]
    SandboxAccount account;
    sandboxRest.Register(account, err, BrokerAccountType::Tinkoff);
    if (err) {
        std::cout << "Error 1: " << err.message << std::endl;
    } else {
        std::cout << "Account id: " << account.brokerAccountId << std::endl << std::endl;
    }


    // Получение брокерских счетов клиента 
    UserAccountList userAccounts;
    sandboxRest.Accounts(userAccounts, err);
    if (err) {
        std::cout << "Error 2: " << err.message << std::endl;
    }


    // Выставление баланса по валютным позициям [SANDBOX]
    sandboxRest.SetCurrencyBalance(err, account.brokerAccountId, Currency::USD, 250000);
    if (err) {
        std::cout << "Error 3: " << err.message << std::endl;
    }


    // Выставление баланса по инструментным позициям [SANDBOX]
    sandboxRest.SetPositionsBalance(err, account.brokerAccountId, "BBG005DXJS36", 10000);
    if (err) {
        std::cout << "Error 4: " << err.message << std::endl;
    }
    

    // Создание лимитной заявки
    PlacedOrder limitOrder;
    sandboxRest.LimitOrder(limitOrder, err, account.brokerAccountId, "BBG005DXJS36", 10, OperationType::Buy, 1.0);
    if (err) {
        std::cout << "Error 5: " << err.message << std::endl;
    } else {
        std::cout << "Placed limit order: " << limitOrder.orderId << std::endl << std::endl;
    }


    // Создание рыночной заявки
    PlacedOrder marketOrder;
    sandboxRest.MarketOrder(marketOrder, err, account.brokerAccountId, "BBG005DXJS36", 10, OperationType::Buy);
    if (err) {
        std::cout << "Error 6: " << err.message << " " << std::endl;
    } else {
        std::cout << "Placed market order: " << marketOrder.orderId << std::endl << std::endl;
    }


    // Отмена заявки
    sandboxRest.OrderCancel(err, account.brokerAccountId, "order-id-string");
    if (err) {
        std::cout << "Order cancelation error!" << std::endl;
    }


    // Получение списка активных заявок
    OrderList orders;
    sandboxRest.Orders(orders, err, account.brokerAccountId);
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
    sandboxRest.PortfolioPositions(positions, err, account.brokerAccountId);
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
    sandboxRest.PortfolioCurrencies(currencies, err, account.brokerAccountId);
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
    sandboxRest.Portfolio(portfolio, err, account.brokerAccountId);
    if (err) {
        std::cout << "Error 10: " << err.message << std::endl;
    } else {
        std::cout << "Positions total: " << portfolio.positions.size() << std::endl;
        std::cout << "Currencies total: " << portfolio.currencies.size() << std::endl << std::endl;
    }


    // Получение списка акций
    MarketInstrumentList stocks;
    sandboxRest.Stocks(stocks, err);
    if (err) {
        std::cout << "Error 11: " << err.message << std::endl;
    } else {
        std::cout << "Total stocks: " << stocks.size() << std::endl;
    }


    // Получение списка облигаций
    MarketInstrumentList bonds;
    sandboxRest.Bonds(bonds, err);
    if (err) {
        std::cout << "Error 12: " << err.message << std::endl;
    } else {
        std::cout << "Total bonds: " << bonds.size() << std::endl;
    }


    // Получение списка ETF
    MarketInstrumentList etfs;
    sandboxRest.ETFs(etfs, err);
    if (err) {
        std::cout << "Error 13: " << err.message << std::endl;
    } else {
        std::cout << "Total etfs: " << etfs.size() << std::endl;
    }


    // Получение списка валютных пар
    MarketInstrumentList currenciesList;
    sandboxRest.Currencies(currenciesList, err);
    if (err) {
        std::cout << "Error 14: " << err.message << std::endl;
    } else {
        std::cout << "Total currencies: " << currenciesList.size() << std::endl << std::endl;
    }


    // Получение стакана по FIGI
    OrderBook orderBook;
    sandboxRest.Orderbook(orderBook, err, "BBG005DXJS36", 10);
    if (err) {
        std::cout << "Error 15: " << err.message << std::endl;
    } else {
        std::cout << orderBook.figi << ": " << to_string(orderBook.tradeStatus) << std::endl << std::endl;
    }


    // Получение исторических свечей по FIGI
    CandleList candles;
    sandboxRest.Candles(candles, err, "BBG005DXJS36", "2019-08-19T18:38:33+03:00", 
                            "2019-08-19T18:40:33+03:00", CandleInterval::_1min);
    if (err) {
        std::cout << "Error 16: " << err.message << std::endl;
    } else {
        std::cout << "Total candles: " << candles.size() << std::endl << std::endl;;
    }


    // Получение инструмента по FIGI
    SearchMarketInstrument instrument;
    sandboxRest.GetIntsrumentByFIGI(instrument, err, "BBG005DXJS36");
    if (err) {
        std::cout << "Error 17: " << err.message << std::endl;
    } else {
        std::cout << instrument.figi << " " << instrument.ticker << " " << instrument.name << std::endl << std::endl;
    }


    // Получение инструмента по тикеру
    MarketInstrumentList instrumentList;
    sandboxRest.GetInstrumentByTicker(instrumentList, err, "TCS");
    if (err) {
        std::cout << "Error 18: " << err.message << std::endl;
    } else {
        std::cout << "Instruments found: " << instrumentList.size() << std::endl << std::endl;
    }


    // Получение списка операций
    OperationList operations;
    sandboxRest.Operations(operations, err, account.brokerAccountId, "BBG005DXJS36", 
                            "2019-08-19T18:38:33+03:00", "2019-08-19T18:40:33+03:00");
    if (err) {
        std::cout << "Error 19: " << err.message << std::endl;
    } else {
        std::cout << "Operations found: " << operations.size() << std::endl << std::endl;
    }


    // Удаление всех позиций [SANDBOX]
    sandboxRest.Clear(err, account.brokerAccountId);
    if (err) {
        std::cout << "Error 20: " << err.message << std::endl;
    }


    // Удаление счета [SANDBOX]
    sandboxRest.Remove(err, account.brokerAccountId);
    if (err) {
        std::cout << "Error 21: " << err.message << std::endl;
    } else {
        std::cout << "Account " << account.brokerAccountId << " removed\n";
    }
    
    return 0;
}