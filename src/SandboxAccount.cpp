#include <SandboxAccount.h>

#include <utils.h>

using Json = nlohmann::json;


SandboxAccount::SandboxAccount() {}

SandboxAccount::SandboxAccount(BrokerAccountType type, std::string id) {
    brokerAccountType = type;
    brokerAccountId = id;
}

void to_json(Json& j, const SandboxAccount& account) {
    j = Json {
                {"brokerAccountType", to_string(account.brokerAccountType)},
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