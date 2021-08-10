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

std::string toString(OrderStatus& s) {
    switch (s) {
    case OrderStatus::New:
        return "New";
        break;
    case OrderStatus::PartiallyFill:
        return "PartiallyFill";
        break;
    case OrderStatus::Fill:
        return "Fill";
        break;
    case OrderStatus::Cancelled:
        return "Cancelled";
        break;
    case OrderStatus::Replaced:
        return "Replaced";
        break;
    case OrderStatus::PendingCancel:
        return "PendingCancel";
        break;
    case OrderStatus::Rejected:
        return "Rejected";
        break;
    case OrderStatus::PendingReplace:
        return "PendingReplace";
        break;
    case OrderStatus::PendingNew:
        return "PendingNew";
        break;
    default:
        return "Error";
    }
}

std::string toString(OperationType& t) {
    if (t == OperationType::Buy) {
        return "Buy";
    }

    return "Sell";
}

OrderStatus toOrderStatus(std::string&& s) {
    if (s == "New") {
        return OrderStatus::New;
    } else if (s == "PartiallyFill") {
        return OrderStatus::PartiallyFill;
    } else if (s == "Fill") {
        return OrderStatus::Fill;
    } else  if (s == "Cancelled") {
        return OrderStatus::Cancelled;
    } else if (s == "Replaced") {
        return OrderStatus::Replaced;
    } else if (s == "PendingCancel") {
        return OrderStatus::PendingCancel;
    } else if (s == "Rejected") {
        return OrderStatus::Rejected;
    } else if (s == "PendingReplace") {
        return OrderStatus::PendingReplace;
    } else if (s == "PendingNew") {
        return OrderStatus::PendingNew;
    }
    
    throw "Invalid order status";    
}

BrokerAccountType toBrokerAccountType(std::string&& s) {
    if (s == "Tinkoff") {
        return BrokerAccountType::Tinkoff;
    }
    return BrokerAccountType::TinkoffIis;
}