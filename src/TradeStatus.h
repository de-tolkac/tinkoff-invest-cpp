#pragma once

/*
enum class TradeStatus {
    NormalTrading, NotAvailableForTrading
};
*/

// https://stackoverflow.com/a/53284026/16689699


class TradeStatus {
public:
    enum TradeStatusType {
        NormalTrading, NotAvailableForTrading
    };
    
    TradeStatus() = default;

    constexpr TradeStatus(TradeStatusType type)
        : value(type)
    {}

    operator TradeStatusType() const {
        return value; 
    } 

    explicit operator bool() = delete;

    constexpr bool operator==(TradeStatus status) const {
        return value == status.value; 
    }

    constexpr bool operator==(TradeStatusType status) const {
        return value == status; 
    }

    constexpr bool operator!=(TradeStatus status) const { 
        return value != status.value; 
    }

    constexpr bool operator!=(TradeStatusType status) const { 
        return value != status; 
    }


    std::string to_string() const {
        if (value == NormalTrading) {
            return "NormalTrading";
        }

        return "NotAvailableForTrading";
    }
private:
    TradeStatusType value;
};