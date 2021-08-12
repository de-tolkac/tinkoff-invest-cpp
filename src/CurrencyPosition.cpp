#include <CurrencyPosition.h>

#include <utils.h>

#include <string>

void to_json(Json& j, const CurrencyPosition& c) {
    j = Json {
                {"currency", toString(c.currency)},
                {"balance", std::to_string(c.balance)},
                {"blocked", std::to_string(c.blocked)}
             };
}

void from_json(const Json& j, CurrencyPosition& c) {
    try {
        c.currency = toCurrency(j.at("currency"));
        j.at("balance").get_to(c.balance);
        j.at("blocked").get_to(c.blocked);
    }
    catch(std::string error) {
        throw error;   
    }
    catch(...) {
        std::string message = "Impossible to parse JSON to CurrencyPosition structure";
        throw message;
    }
}

bool operator==(const CurrencyPosition& lhs, const CurrencyPosition& rhs) {
    return lhs.currency == rhs.currency && lhs.balance == rhs.balance && lhs.blocked == rhs.blocked;
}