#pragma once

#include <string>

/*
enum class OperationType {
    Buy, Sell
};
*/

class OperationType {
public:
    enum OperationTypeEnum {
        Buy, Sell
    };
    
    OperationType() = default;

    constexpr OperationType(OperationTypeEnum type)
        : value(type)
    {}

    operator OperationTypeEnum() const {
        return value; 
    } 

    explicit operator bool() = delete;

    constexpr bool operator==(OperationType currency) const {
        return value == currency.value; 
    }

    constexpr bool operator==(OperationTypeEnum currency) const {
        return value == currency; 
    }

    constexpr bool operator!=(OperationType currency) const { 
        return value != currency.value; 
    }

    constexpr bool operator!=(OperationTypeEnum currency) const { 
        return value != currency; 
    }


    std::string to_string() const {
        if (value == OperationType::Buy) {
            return "Buy";
        }
        
        return "Sell";
    }
private:
    OperationTypeEnum value;
};