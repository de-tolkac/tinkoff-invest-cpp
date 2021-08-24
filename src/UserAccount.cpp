#include <UserAccount.h>

#include <utils.h>

using Json = nlohmann::json;


UserAccount::UserAccount() {}
UserAccount::UserAccount(BrokerAccountType type, std::string id) {
    brokerAccountType = type;
    brokerAccountId = id;
}

UserAccount::UserAccount(std::pair<UserAccount, Error>&& t) {
    brokerAccountType = t.first.brokerAccountType;
    brokerAccountId   = t.first.brokerAccountId;
}

void to_json(Json& j, const UserAccount& account) {
    j = Json {
                {"brokerAccountType", to_string(account.brokerAccountType)},
                {"brokerAccountId", account.brokerAccountId}
             };
}

void from_json(const Json& j, UserAccount& account) {
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

bool operator==(const UserAccount& lhs, const UserAccount& rhs) {
    return lhs.brokerAccountId == rhs.brokerAccountId && lhs.brokerAccountType == rhs.brokerAccountType;
}