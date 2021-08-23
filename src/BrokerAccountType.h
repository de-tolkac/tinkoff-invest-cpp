#pragma once

#include <string>

/*
enum class BrokerAccountType {
    Tinkoff, TinkoffIis
};
*/

class BrokerAccountType {
public:
    enum BrokerAccountTypeEnum {
        Tinkoff, TinkoffIis
    };
    
    BrokerAccountType() = default;

    constexpr BrokerAccountType(BrokerAccountTypeEnum type)
        : value(type)
    {}

    operator BrokerAccountTypeEnum() const {
        return value; 
    } 

    explicit operator bool() = delete;

    constexpr bool operator==(BrokerAccountType status) const {
        return value == status.value; 
    }

    constexpr bool operator==(BrokerAccountTypeEnum status) const {
        return value == status; 
    }

    constexpr bool operator!=(BrokerAccountType status) const { 
        return value != status.value; 
    }

    constexpr bool operator!=(BrokerAccountTypeEnum status) const { 
        return value != status; 
    }


    std::string to_string() const {
        if (value == Tinkoff) {
            return "Tinkoff";
        }

        return "TinkoffIis";
    }
private:
    BrokerAccountTypeEnum value;
};