#pragma once

#include <Error.h>
#include <BrokerAccountType.h>

#include <string>
#include <utility>

struct UserAccount {
    BrokerAccountType brokerAccountType;
    std::string brokerAccountId;

    UserAccount() {}
    UserAccount(BrokerAccountType type, std::string id) {
        brokerAccountType = type;
        brokerAccountId = id;
    }

    UserAccount(std::pair<UserAccount, Error>&& t) {
        brokerAccountType = t.first.brokerAccountType;
        brokerAccountId   = t.first.brokerAccountId;
    }

    UserAccount& operator=(std::pair<UserAccount, Error>&& t) {
        brokerAccountType = t.first.brokerAccountType;
        brokerAccountId   = t.first.brokerAccountId;
        return *this;
    }
};