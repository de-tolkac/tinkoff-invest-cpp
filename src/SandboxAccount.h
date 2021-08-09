#pragma once

#include <Error.h>
#include <BrokerAccountType.h>

#include <string>
#include <utility>

struct SandboxAccount {
    BrokerAccountType brokerAccountType;
    std::string brokerAccountId;

    SandboxAccount() {}
    SandboxAccount(BrokerAccountType type, std::string id) {
        brokerAccountType = type;
        brokerAccountId = id;
    }

    SandboxAccount(std::pair<SandboxAccount, Error>&& t) {
        brokerAccountType = t.first.brokerAccountType;
        brokerAccountId   = t.first.brokerAccountId;
    }

    SandboxAccount& operator=(std::pair<SandboxAccount, Error>&& t) {
        brokerAccountType = t.first.brokerAccountType;
        brokerAccountId   = t.first.brokerAccountId;
        return *this;
    }
};