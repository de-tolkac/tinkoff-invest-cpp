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

std::string toString(const InstrumentType& i) {
    switch (i) {
    case InstrumentType::Stock:
        return "Stock";
        break;
    case InstrumentType::Currency:
        return "Currency";
        break;
    case InstrumentType::Bond:
        return "Bond";
        break;
    case InstrumentType::Etf:
        return "Etf";
        break;
    }
}

std::string toString(const OperationStatus& o) {
    switch (o) {
    case OperationStatus::Done:
        return "Done";
        break;
    case OperationStatus::Decline:
        return "Decline";
        break;
    case OperationStatus::Progress:
        return "Progress";
        break;
    }
}

std::string toString(const OperationType& o) {
    if (o == OperationType::Buy) {
        return "Buy";
    } 

    return "Sell";
}

std::string toString(const TradeStatus& s) {
    if (s == TradeStatus::NormalTrading) {
        return "NormalTrading";
    }

    return "NotAvailableForTrading";
}

std::string toString(const time_t& time) {
    char timeBuffer[26];
    strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%dT%H:%M:%S%z", gmtime(&time));
    timeBuffer[25] = '\0';
    timeBuffer[24] = timeBuffer[23];
    timeBuffer[23] = timeBuffer[22];
    timeBuffer[22] = ':';

    return timeBuffer;
}

std::string toString(const OperationTypeWithCommission& o) {
    switch (o) {
    case OperationTypeWithCommission::Buy:
        return "Buy";
        break;
    case OperationTypeWithCommission::BuyCard:
        return "BuyCard";
        break;
    case OperationTypeWithCommission::Sell:
        return "Sell";
        break;
    case OperationTypeWithCommission::BrokerCommission:
        return "BrokerCommission";
        break;
    case OperationTypeWithCommission::ExchangeCommission:
        return "ExchangeCommission";
        break;
    case OperationTypeWithCommission::ServiceCommission:
        return "ServiceCommission";
        break;
    case OperationTypeWithCommission::MarginCommission:
        return "MarginCommission";
        break;
    case OperationTypeWithCommission::OtherCommission:
        return "OtherCommission";
        break;
    case OperationTypeWithCommission::PayIn:
        return "PayIn";
        break;
    case OperationTypeWithCommission::PayOut:
        return "PayOut";
        break;
    case OperationTypeWithCommission::Tax:
        return "Tax";
        break;
    case OperationTypeWithCommission::TaxLucre:
        return "TaxLucre";
        break;
    case OperationTypeWithCommission::TaxDividend:
        return "TaxDividend";
        break;
    case OperationTypeWithCommission::TaxCoupon:
        return "TaxCoupon";
        break;
    case OperationTypeWithCommission::TaxBack:
        return "TaxBack";
        break;
    case OperationTypeWithCommission::Repayment:
        return "Repayment";
        break;
    case OperationTypeWithCommission::PartRepayment:
        return "PartRepayment";
        break;
    case OperationTypeWithCommission::Coupon:
        return "Coupon";
        break;
    case OperationTypeWithCommission::Dividend:
        return "Dividend";
        break;
    case OperationTypeWithCommission::SecurityIn:
        return "SecurityIn";
        break;
    case OperationTypeWithCommission::SecurityOut:
        return "SecurityOut";
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

OrderType toOrderType(std::string&& s) {
    if (s == "Limit") {
        return OrderType::Limit;
    } else if (s == "Market") {
        return OrderType::Market;
    }

    std::string message = "Invalid order type: ";
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

InstrumentType toInstrumentType(std::string&& i) {
    if (i == "Stock") {
        return InstrumentType::Stock;
    } else if (i == "Currency") {
        return InstrumentType::Currency;
    } else if (i == "Bond") {
        return InstrumentType::Bond;
    } else if (i == "Etf") {
        return InstrumentType::Etf;
    }

    std::string message = "Invalid Instrument Type: ";
    message += i;
    throw message; 
}

OperationStatus toOperationStatus(std::string&& o) {
    if (o == "Done") {
        return OperationStatus::Done;
    } else if (o == "Decline") {
        return OperationStatus::Decline;
    } else if (o == "Progress") {
        return OperationStatus::Progress;
    }

    std::string message = "Invalid Operation Status: ";
    message += o;
    throw message; 
}

OperationType toOperationType(std::string&& o) {
    if (o == "Buy") {
        return OperationType::Buy;
    } else if (o == "Sell") {
        return OperationType::Sell;
    }

    std::string message = "Invalid Operation Type: ";
    message += o;
    throw message; 
}

TradeStatus toTradeStatus(std::string&& s) {
    if (s == "NormalTrading") {
        return TradeStatus::NormalTrading;
    } else if (s == "NotAvailableForTrading") {
        return TradeStatus::NotAvailableForTrading;
    }

    std::string message = "Invalid Trade Status: ";
    message += s;
    throw message;     
}

OperationTypeWithCommission toOperationTypeWithCommission(std::string&& op) {
    if (op == "Buy") {
        return OperationTypeWithCommission::Buy;
    } else if (op == "BuyCard") {
        return OperationTypeWithCommission::BuyCard;
    } else if (op == "Sell") {
        return OperationTypeWithCommission::Sell;
    } else if (op == "BrokerCommission") {
        return OperationTypeWithCommission::BrokerCommission;
    } else if (op == "ExchangeCommission") {
        return OperationTypeWithCommission::ExchangeCommission;
    } else if (op == "ServiceCommission") {
        return OperationTypeWithCommission::ServiceCommission;
    } else if (op == "MarginCommission") {
        return OperationTypeWithCommission::MarginCommission;
    } else if (op == "OtherCommission") {
        return OperationTypeWithCommission::OtherCommission;
    } else if (op == "PayIn") {
        return OperationTypeWithCommission::PayIn;
    } else if (op == "PayOut") {
        return OperationTypeWithCommission::PayOut;
    } else if (op == "Tax") {
        return OperationTypeWithCommission::Tax;
    } else if (op == "TaxLucre") {
        return OperationTypeWithCommission::TaxLucre;
    } else if (op == "TaxDividend") {
        return OperationTypeWithCommission::TaxDividend;
    } else if (op == "TaxCoupon") {
        return OperationTypeWithCommission::TaxCoupon;
    } else if (op == "TaxBack") {
        return OperationTypeWithCommission::TaxBack;
    } else if (op == "Repayment") {
        return OperationTypeWithCommission::Repayment;
    } else if (op == "PartRepayment") {
        return OperationTypeWithCommission::PartRepayment;
    } else if (op == "Coupon") {
        return OperationTypeWithCommission::Coupon;
    } else if (op == "Dividend") {
        return OperationTypeWithCommission::Dividend;
    } else if (op == "SecurityIn") {
        return OperationTypeWithCommission::SecurityIn;
    } else if (op == "SecurityOut") {
        return OperationTypeWithCommission::SecurityOut;
    }

    std::string message = "Invalid Operation Type With Commission: ";
    message += op;
    throw message; 
}

time_t toDate(std::string&& t) {
    struct tm time;
    strptime(t.c_str(), "%Y-%m-%dT%H:%M:%S%c%c%c:%c%c", &time);
    return timegm(&time);
}