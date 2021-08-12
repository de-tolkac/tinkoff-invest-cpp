#include <utils.h>

std::string toString(const Currency& c) {
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
    }
}

std::string toString(const BrokerAccountType& t) {
    if (t == BrokerAccountType::Tinkoff) {
        return "Tinkoff";
    }
    return "TinkoffIis";
}

std::string toString(const OrderStatus& s) {
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
    }
}

std::string toString(const OperationType& t) {
    if (t == OperationType::Buy) {
        return "Buy";
    }

    return "Sell";
}

std::string toString(const OrderType& t) {
    if (t == OrderType::Limit) {
        return "Limit";
    }

    return "Market";
}

std::string toString(const CandleInterval& i) {
    switch (i) {
    case CandleInterval::_1min:
        return "1min";
        break;
    case CandleInterval::_2min:
        return "2min";
        break;
    case CandleInterval::_3min:
        return "3min";
        break;
    case CandleInterval::_5min:
        return "5min";
        break;
    case CandleInterval::_10min:
        return "10min";
        break;
    case CandleInterval::_15min:
        return "15min";
        break;
    case CandleInterval::_30min:
        return "30min";
        break;
    case CandleInterval::_hour:
        return "hour";
        break;
    case CandleInterval::_day:
        return "day";
        break;
    case CandleInterval::_week:
        return "week";
        break;
    case CandleInterval::_month:
        return "month";
        break;
    }
}

Currency toCurrency(std::string&& c) {
    if (c == "RUB") {
        return Currency::RUB;
    } else if (c == "USD") {
        return Currency::USD;
    } else if (c == "EUR") {
        return Currency::EUR;
    } else if (c == "GBP") {
        return Currency::GBP;
    } else if (c == "HKD") {
        return Currency::HKD;
    } else if (c == "CHF") {
        return Currency::CHF;
    } else if (c == "JPY") {
        return Currency::JPY;
    } else if (c == "CNY") {
        return Currency::CNY;
    } else if (c == "TRY") {
        return Currency::TRY;
    }

    std::string message = "Invalid currency: ";
    message += c;
    throw message;
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
     
    std::string message = "Invalid order status: ";
    message += s;
    throw message; 
}

BrokerAccountType toBrokerAccountType(std::string&& s) {
    if (s == "Tinkoff") {
        return BrokerAccountType::Tinkoff;
    }
    return BrokerAccountType::TinkoffIis;
}

CandleInterval toCandleInterval(std::string&& i) {
    if (i == "1min") {
        return CandleInterval::_1min;
    } else if (i == "2min") {
        return CandleInterval::_2min;
    } else if (i == "3min") {
        return CandleInterval::_3min;
    } else if (i == "5min") {
        return CandleInterval::_5min;
    } else if (i == "10min") {
        return CandleInterval::_10min;
    } else if (i == "15min") {
        return CandleInterval::_15min;
    } else if (i == "30min") {
        return CandleInterval::_30min;
    } else if (i == "hour") {
        return CandleInterval::_hour;
    } else if (i == "day") {
        return CandleInterval::_day;
    } else if (i == "week") {
        return CandleInterval::_week;
    } else if (i == "month") {
        return CandleInterval::_month;
    }

    std::string message = "Invalid Candle Resolution: ";
    message += i;
    throw message; 
}