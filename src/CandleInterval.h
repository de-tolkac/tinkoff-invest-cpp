#pragma once

#include <string>

/*
enum class CandleInterval {
    _1min, _2min, _3min, _5min, _10min, _15min, _30min,
    _hour, _day, _week, _month
};
*/

class CandleInterval {
public:
    enum CandleIntervalEnum {
        _1min, _2min, _3min, _5min, _10min, _15min, _30min,
        _hour, _day, _week, _month
    };
    
    CandleInterval() = default;

    constexpr CandleInterval(CandleIntervalEnum type)
        : value(type)
    {}

    operator CandleIntervalEnum() const {
        return value; 
    } 

    explicit operator bool() = delete;

    constexpr bool operator==(CandleInterval status) const {
        return value == status.value; 
    }

    constexpr bool operator==(CandleIntervalEnum status) const {
        return value == status; 
    }

    constexpr bool operator!=(CandleInterval status) const { 
        return value != status.value; 
    }

    constexpr bool operator!=(CandleIntervalEnum status) const { 
        return value != status; 
    }


    std::string to_string() const {
        switch (value) {
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

        return "";
    }
private:
    CandleIntervalEnum value;
};