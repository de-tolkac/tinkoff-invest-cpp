#pragma once

#include <string>

/*
enum class OperationStatus {
    Done, Decline, Progress
};
*/

class OperationStatus {
public:
    enum OperationStatusEnum {
        Done, Decline, Progress
    };
    
    OperationStatus() = default;

    constexpr OperationStatus(OperationStatusEnum type)
        : value(type)
    {}

    operator OperationStatusEnum() const {
        return value; 
    } 

    explicit operator bool() = delete;

    constexpr bool operator==(OperationStatus currency) const {
        return value == currency.value; 
    }

    constexpr bool operator==(OperationStatusEnum currency) const {
        return value == currency; 
    }

    constexpr bool operator!=(OperationStatus currency) const { 
        return value != currency.value; 
    }

    constexpr bool operator!=(OperationStatusEnum currency) const { 
        return value != currency; 
    }


    std::string to_string() const {
        switch (value) {
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
        
        return "";
    }
private:
    OperationStatusEnum value;
};