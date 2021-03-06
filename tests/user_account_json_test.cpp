#include <gtest/gtest.h>

#include <UserAccount.h>

#include <nlohmann/json.hpp>

using Json = nlohmann::json;

using namespace ti;

TEST(json_test, UserAccount_get) {
    Json j = R"(
        {
            "brokerAccountType": "Tinkoff",
            "brokerAccountId": "testID"
        }
    )"_json;

    UserAccount account1;
    account1.brokerAccountType = BrokerAccountType::Tinkoff;
    account1.brokerAccountId = "testID";

    UserAccount account2 = j.get<UserAccount>();

    ASSERT_EQ(account1, account2);
}

TEST(json_test, UserAccount_Parse) {
    std::string text = R"(
        {
            "brokerAccountType": "Tinkoff",
            "brokerAccountId": "testID"
        }
    )";

    UserAccount account1;
    account1.brokerAccountType = BrokerAccountType::Tinkoff;
    account1.brokerAccountId = "testID";

    UserAccount account2 = Json::parse(text);

    ASSERT_EQ(account1, account2);
}

TEST(json_test, UserAccount_Exception_brokerAccountType) {
    Json j = R"(
        {
            "brokerAccountId": "testID"
        }
    )"_json;

    ASSERT_THROW(j.get<UserAccount>(), std::string);
}

TEST(json_test, UserAccount_Exception_brokerAccountId) {
    Json j = R"(
        {
            "brokerAccountType": "Tinkoff"
        }
    )"_json;

    ASSERT_THROW(j.get<UserAccount>(), std::string);
}