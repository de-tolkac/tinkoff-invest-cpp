#pragma once

#include <string>

/*
enum class InstrumentType {
    Stock, Currency, Bond, Etf
};
*/

#include <string>

class InstrumentType {
public:
    enum InstrumentTypeEnum {
        Stock, Currency, Bond, Etf
    };
    
    InstrumentType() = default;

    constexpr InstrumentType(InstrumentTypeEnum type)
        : value(type)
    {}

    operator InstrumentTypeEnum() const {
        return value; 
    } 

    explicit operator bool() = delete;

    constexpr bool operator==(InstrumentType status) const {
        return value == status.value; 
    }

    constexpr bool operator==(InstrumentTypeEnum status) const {
        return value == status; 
    }

    constexpr bool operator!=(InstrumentType status) const { 
        return value != status.value; 
    }

    constexpr bool operator!=(InstrumentTypeEnum status) const { 
        return value != status; 
    }


    std::string to_string() const {
        switch (value) {
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

        return "";
    }
private:
    InstrumentTypeEnum value;
};