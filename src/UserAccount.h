#pragma once

#include <Error.h>
#include <BrokerAccountType.h>

#include <string>
#include <utility>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

struct UserAccount {
    BrokerAccountType brokerAccountType;
    std::string brokerAccountId;

    UserAccount();
    UserAccount(BrokerAccountType, std::string);

    UserAccount(std::pair<UserAccount, Error>&&);

    /*
    UserAccount& operator=(std::pair<UserAccount, Error>&& t) {
        brokerAccountType = t.first.brokerAccountType;
        brokerAccountId   = t.first.brokerAccountId;
        return *this;
    }
    */
};

void to_json(Json&, const UserAccount&);
void from_json(const Json&, UserAccount&);

bool operator==(const UserAccount&, const UserAccount&);

using UserAccountList = std::vector<UserAccount>;