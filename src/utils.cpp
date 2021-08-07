#include <utils.h>

std::string toString(Currency& c) {
    switch (c) {
    case Currency::RUB:
        return "RUB";
        break;
    case Currency::USD:
        return "USD";
        break;
    case Currency::EUR:
        return "EUR";
        break;
    case Currency::GBP:
        return "GBP";
        break;
    case Currency::HKD:
        return "HKD";
        break;
    case Currency::CHF:
        return "CHF";
        break;
    case Currency::JPY:
        return "JPY";
        break;
    case Currency::CNY:
        return "CNY";
        break;
    case Currency::TRY:
        return "TRY";
        break;
    default:
        return "Error";
    }
}

std::string toString(BrokerAccountType& t) {
    if (t == BrokerAccountType::Tinkoff) {
        return "Tinkoff";
    }
    return "TinkoffIis";
}

BrokerAccountType toBrokerAccountType(std::string s) {
    if (s == "Tinkoff") {
        return BrokerAccountType::Tinkoff;
    }
    return BrokerAccountType::TinkoffIis;
}