#include <gtest/gtest.h>

#include <SandboxAccount.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

TEST(json_test, SandboxAccount_get) {
    Json j = R"(
        {
            "brokerAccountType": "Tinkoff",
            "brokerAccountId": "testID"
        }
    )"_json;

    SandboxAccount account1;
    account1.brokerAccountType = BrokerAccountType::Tinkoff;
    account1.brokerAccountId = "testID";

    SandboxAccount account2 = j.get<SandboxAccount>();

    ASSERT_EQ(account1, account2);
}

TEST(json_test, SandboxAccount_Parse) {
    std::string text = R"(
        {
            "brokerAccountType": "Tinkoff",
            "brokerAccountId": "testID"
        }
    )";

    SandboxAccount account1;
    account1.brokerAccountType = BrokerAccountType::Tinkoff;
    account1.brokerAccountId = "testID";

    SandboxAccount account2 = Json::parse(text);

    ASSERT_EQ(account1, account2);
}