#pragma once

#include <Error.h>
#include <BrokerAccountType.h>

#include <string>
#include <utility>

#include <nlohmann/json.hpp>

namespace ti {

struct UserAccount {
    BrokerAccountType brokerAccountType;
    std::string brokerAccountId;

    UserAccount();
    UserAccount(BrokerAccountType, std::string);

    UserAccount(std::pair<UserAccount, Error>&&);
};

void to_json(nlohmann::json&, const UserAccount&);
void from_json(const nlohmann::json&, UserAccount&);

bool operator==(const UserAccount&, const UserAccount&);

using UserAccountList = std::vector<UserAccount>;

}