#pragma once

#include <SandboxAccount.h>
#include <Currency.h>

#include <string>
#include <tuple>

class StreamingClient {
    std::string token;
public:

};

class RestClient {
    std::string token;
public:

};

class SandboxRestClient {
    std::string token;
public:
    SandboxRestClient() = delete;
    SandboxRestClient(std::string&);
    SandboxRestClient(char*);
    ~SandboxRestClient();

    std::tuple<SandboxAccount, Error> Register(BrokerAccountType);
    Error SetCurrencyBalance(std::string&, Currency, double);
    Error SetPositionsBalance(std::string&, std::string, double);
    Error Remove(std::string&);
    Error Clear(std::string&);
};