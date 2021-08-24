#pragma once

#include <Error.h>
#include <BrokerAccountType.h>

#include <string>
#include <utility>

#include <nlohmann/json.hpp>



struct SandboxAccount {
    BrokerAccountType brokerAccountType;
    std::string brokerAccountId;

    
    SandboxAccount();
    SandboxAccount(BrokerAccountType, std::string);
};


void to_json(nlohmann::json&, const SandboxAccount&);
void from_json(const nlohmann::json&, SandboxAccount&);

bool operator==(const SandboxAccount&, const SandboxAccount&);