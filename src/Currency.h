#pragma once

#include <string>

/*
enum class Currency {
    RUB, USD, EUR, GBP, HKD, CHF, JPY, CNY, TRY
};
*/

// https://stackoverflow.com/a/53284026/16689699

class Currency {
public:
    enum CurrencyType {
        RUB, USD, EUR, GBP, HKD, CHF, JPY, CNY, TRY
    };
    
    Currency() = default;

    constexpr Currency(CurrencyType type)
        : value(type)
    {}

    operator CurrencyType() const {
        return value; 
    } 

    explicit operator bool() = delete;

    constexpr bool operator==(Currency currency) const {
        return value == currency.value; 
    }

    constexpr bool operator==(CurrencyType currency) const {
        return value == currency; 
    }

    constexpr bool operator!=(Currency currency) const { 
        return value != currency.value; 
    }

    constexpr bool operator!=(CurrencyType currency) const { 
        return value != currency; 
    }


    std::string to_string() const {
        switch (value) {
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
        
        return "";
    }
private:
    CurrencyType value;
};