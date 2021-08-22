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

    // Регистрация клиента в sandbox
    auto [account, err] = sandboxRest.Register(BrokerAccountType::Tinkoff);
    if (err) {
        std::cout << "Error 1: " << err.message << std::endl;
    } else {
        std::cout << "Account id: " << account.brokerAccountId << std::endl;
    }

    err = sandboxRest.SetCurrencyBalance(account.brokerAccountId, Currency::RUB, 250000);
    if (err) {
        std::cout << "Error 2: " << err.message << std::endl;
    }

    PlacedOrder limitOrder;
    std::tie(limitOrder, err) = sandboxRest.LimitOrder(account.brokerAccountId, "BBG004730N88", 10, OperationType::Buy, 1.0);
    if (err) {
        std::cout << "Error 3: " << err.message << std::endl;
    }

    PlacedOrder marketOrder;
    std::tie(marketOrder, err) = sandboxRest.MarketOrder(account.brokerAccountId, "BBG004730N88", 10, OperationType::Buy);
    if (err) {
        std::cout << "Error 4: " << err.message << " " << err.code << std::endl;
    }

    OrderList orders;
    std::tie(orders, err) = sandboxRest.Orders(account.brokerAccountId);
    if (err) {
        std::cout << "Error 5: " << err.message << std::endl;
    } else {
        std::cout << "Orders total: " << orders.size() << std::endl;
        for (const auto& o : orders) {
            std::cout << o.figi << ": " << o.requestedLots << "\n";
        }
        std::cout << std::endl;
    }
    
    PortfolioPositionList positions;
    std::tie(positions, err) = sandboxRest.PortfolioPositions(account.brokerAccountId);
    if (err) {
        std::cout << "Error 6: " << err.message << std::endl;
    } else {
        std::cout << "Positions total: " << positions.size() << std::endl;
        for (const auto& p : positions) {
            std::cout << p.name << ": " << p.lots << "\n";
        }
        std::cout << std::endl;
    }

    CurrencyPositionList currencies;
    std::tie(currencies, err) = sandboxRest.PortfolioCurrencies(account.brokerAccountId);
    if (err) {
        std::cout << "Error 7: " << err.message << std::endl;
    } else {
        std::cout << "Currencies total: " << positions.size() << std::endl;
        for (const auto& c : currencies) {
            std::cout << c.currency.to_string() << ": " << c.balance << "\n";
        }
        std::cout << std::endl;
    }

    PortfolioInfo portfolio;
    std::tie(portfolio, err) = sandboxRest.Portfolio(account.brokerAccountId);
    if (err) {
        std::cout << "Error 8: " << err.message << std::endl;
    } else {
        std::cout << "Positions total: " << portfolio.positions.size() << std::endl;
        std::cout << "Currencies total: " << portfolio.currencies.size() << std::endl << std::endl;
    }

    err = sandboxRest.Remove(account.brokerAccountId);
    if (err) {
        std::cout << "Error 9: " << err.message << std::endl;
    } else {
        std::cout << "Account " << account.brokerAccountId << " removed\n";
    }

    /*
    // Выполнение регистрации без инициализации объекта ошибки (не стоит так делать)
    SandboxAccount account2 = sandboxRest.Register(BrokerAccountType::TinkoffIis);
    std::cout << "Account id: " << account2.brokerAccountId << std::endl;

    
    // Выставление баланса по валютным позициям
   

    // Выставление баланса по инструментальным позициям
    err = sandboxRest.SetPositionsBalance(account.brokerAccountId, "BBG004730N88", 10000);
    if (err) {
        std::cout << "Error: " << err.message << std::endl;
    }


    // Удаление всех позиций
    err = sandboxRest.Clear(account.brokerAccountId);
    if (err) {
        std::cout << "Error: " << err.message << std::endl;
    }


    // Удаление счета
    err = sandboxRest.Remove(account.brokerAccountId);
    if (err) {
        std::cout << "Error: " << err.message << std::endl;
    }

    */
    return 0;
}