#pragma once

#include <string>

/*
enum class OrderType {
    Limit, Market
};
*/

class OrderType {
public:
    enum OrderTypeEnum {
        Limit, Market
    };
    
    OrderType() = default;

    constexpr OrderType(OrderTypeEnum type)
        : value(type)
    {}

    operator OrderTypeEnum() const {
        return value; 
    } 

    explicit operator bool() = delete;

    constexpr bool operator==(OrderType currency) const {
        return value == currency.value; 
    }

    constexpr bool operator==(OrderTypeEnum currency) const {
        return value == currency; 
    }

    constexpr bool operator!=(OrderType currency) const { 
        return value != currency.value; 
    }

    constexpr bool operator!=(OrderTypeEnum currency) const { 
        return value != currency; 
    }


    std::string to_string() const {
        if (value == Limit) {
            return "Limit";
        }

        return "Market";
    }
private:
    OrderTypeEnum value;
};