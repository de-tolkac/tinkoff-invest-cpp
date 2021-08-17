#include <MoneyAmount.h>

#include <utils.h>

#include <string>
#include <iostream>

void to_json(Json& j, const MoneyAmount& m) {
    j = Json {
                {"currency", toString(m.currency)},
                {"value", std::to_string(m.value)}
             };
}

void from_json(const Json& j, MoneyAmount& m) {
    try {
        m.currency = toCurrency(j.at("currency"));
        j.at("value").get_to(m.value);
    }
    catch(std::string& error) {
        throw error;
    }
    catch(...) {
        std::string message = "Impossible to parse JSON to MoneyAmount structure";
        throw message;
    }
}

bool operator==(const MoneyAmount& lhs, const MoneyAmount& rhs) {
    return lhs.currency == rhs.currency && lhs.value == rhs.value;
}