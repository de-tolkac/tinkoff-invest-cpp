#pragma once

#include <Error.h>
#include <BrokerAccountType.h>

#include <string>
#include <utility>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

struct SandboxAccount {
    BrokerAccountType brokerAccountType;
    std::string brokerAccountId;

    
    SandboxAccount();
    SandboxAccount(BrokerAccountType, std::string);
    
    /*
    SandboxAccount(std::pair<SandboxAccount, Error>&&);
    SandboxAccount& operator=(std::pair<SandboxAccount, Error>&&);
    SandboxAccount& operator=(const SandboxAccount&) = default;
    */
};


void to_json(Json&, const SandboxAccount&);
void from_json(const Json&, SandboxAccount&);

bool operator==(const SandboxAccount&, const SandboxAccount&);