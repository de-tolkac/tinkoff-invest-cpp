#pragma once

#include <Error.h>
#include <BrokerAccountType.h>

#include <string>
#include <tuple>


struct SandboxAccount {
    BrokerAccountType brokerAccountType;
    std::string brokerAccountId;

    SandboxAccount() {}
    SandboxAccount(BrokerAccountType type, std::string id) {
        brokerAccountType = type;
        brokerAccountId = id;
    }

    SandboxAccount(std::tuple<SandboxAccount, Error>&& t) {
        brokerAccountType = std::get<SandboxAccount>(t).brokerAccountType;
        brokerAccountId   = std::get<SandboxAccount>(t).brokerAccountId;
    }

    SandboxAccount& operator=(std::tuple<SandboxAccount, Error>&& t) {
        brokerAccountType = std::get<SandboxAccount>(t).brokerAccountType;
        brokerAccountId   = std::get<SandboxAccount>(t).brokerAccountId;
        return *this;
    }
};