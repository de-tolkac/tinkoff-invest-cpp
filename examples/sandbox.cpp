#include <tinvest/OpenAPI.h>

#include <iostream>
#include <fstream>

int main() {
    std::string token;
    
    std::ifstream file("token.txt");
    file >> token;
    file.close();
    
    SandboxRestClient sandboxRest(token);

    // Регистрация клиента в sandbox
    auto [account, err] = sandboxRest.Register(BrokerAccountType::Tinkoff);
    if (err) {
        std::cout << "Error: " << err.message << std::endl;
    } else {
        std::cout << "Account id: " << account.brokerAccountId << std::endl;
    }

    auto [orders, err2] = sandboxRest.Orders(account.brokerAccountId);
    if (err2) {
        std::cout << "Error: " << err2.message << std::endl;
    }

    err = sandboxRest.Remove(account.brokerAccountId);
    if (err) {
        std::cout << "Error: " << err.message << std::endl;
    } else {
        std::cout << "Account " << account.brokerAccountId << " removed\n";
    }
    /*
    // Выполнение регистрации без инициализации объекта ошибки (не стоит так делать)
    SandboxAccount account2 = sandboxRest.Register(BrokerAccountType::TinkoffIis);
    std::cout << "Account id: " << account2.brokerAccountId << std::endl;

    
    // Выставление баланса по валютным позициям
    err = sandboxRest.SetCurrencyBalance(account.brokerAccountId, Currency::RUB, 250000);
    if (err) {
        std::cout << "Error: " << err.message << std::endl;
    }


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