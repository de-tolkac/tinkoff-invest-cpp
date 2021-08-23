#pragma once

#include <string>

/*
enum class OrderStatus {
    New, PartiallyFill, Fill, Cancelled, Replaced, PendingCancel, Rejected, PendingReplace, PendingNew
};
*/

class OrderStatus {
public:
    enum OrderStatusEnum {
        New, PartiallyFill, Fill, Cancelled, Replaced, PendingCancel, Rejected, PendingReplace, PendingNew
    };
    
    OrderStatus() = default;

    constexpr OrderStatus(OrderStatusEnum type)
        : value(type)
    {}

    operator OrderStatusEnum() const {
        return value; 
    } 

    explicit operator bool() = delete;

    constexpr bool operator==(OrderStatus currency) const {
        return value == currency.value; 
    }

    constexpr bool operator==(OrderStatusEnum currency) const {
        return value == currency; 
    }

    constexpr bool operator!=(OrderStatus currency) const { 
        return value != currency.value; 
    }

    constexpr bool operator!=(OrderStatusEnum currency) const { 
        return value != currency; 
    }


    std::string to_string() const {
        switch (value) {
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

        return "";
    }
private:
    OrderStatusEnum value;
};