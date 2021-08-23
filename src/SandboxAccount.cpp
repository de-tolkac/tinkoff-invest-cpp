#include <SandboxAccount.h>

#include <utils.h>


SandboxAccount::SandboxAccount() {}

SandboxAccount::SandboxAccount(BrokerAccountType type, std::string id) {
    brokerAccountType = type;
    brokerAccountId = id;
}
/*
SandboxAccount::SandboxAccount(std::pair<SandboxAccount, Error>&& t) {
    brokerAccountType = t.first.brokerAccountType;
    brokerAccountId   = t.first.brokerAccountId;
}

SandboxAccount& SandboxAccount::operator=(std::pair<SandboxAccount, Error>&& t) {
    brokerAccountType = t.first.brokerAccountType;
    brokerAccountId   = t.first.brokerAccountId;
    return *this;
}
*/

void to_json(Json& j, const SandboxAccount& account) {
    j = Json {
                {"brokerAccountType", account.brokerAccountType.to_string()},
                {"brokerAccountId", account.brokerAccountId}
             };
}

void from_json(const Json& j, SandboxAccount& account) {
    try {
        j.at("brokerAccountId").get_to(account.brokerAccountId);

        account.brokerAccountType = toBrokerAccountType(j.at("brokerAccountType"));
    }
    catch(std::string& error) {
        throw error;
    }
    catch(...) {
        std::string message = "Impossible to parse JSON to SandboxAccount structure";
        throw message;
    }
}

bool operator==(const SandboxAccount& lhs, const SandboxAccount& rhs) {
    return lhs.brokerAccountId == rhs.brokerAccountId && lhs.brokerAccountType == rhs.brokerAccountType;
}