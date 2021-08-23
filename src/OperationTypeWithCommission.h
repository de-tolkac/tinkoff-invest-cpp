#pragma once

#include <string>

/*
enum class OperationTypeWithCommission {
    Buy, BuyCard, Sell, BrokerCommission, ExchangeCommission, ServiceCommission,
    MarginCommission, OtherCommission, PayIn, PayOut, Tax, TaxLucre, TaxDividend,
    TaxCoupon, TaxBack, Repayment, PartRepayment, Coupon, Dividend, SecurityIn, SecurityOut
};
*/

class OperationTypeWithCommission {
public:
    enum OperationTypeWithCommissionEnum {
        Buy, BuyCard, Sell, BrokerCommission, ExchangeCommission, ServiceCommission,
        MarginCommission, OtherCommission, PayIn, PayOut, Tax, TaxLucre, TaxDividend,
        TaxCoupon, TaxBack, Repayment, PartRepayment, Coupon, Dividend, SecurityIn, SecurityOut
    };
    
    OperationTypeWithCommission() = default;

    constexpr OperationTypeWithCommission(OperationTypeWithCommissionEnum type)
        : value(type)
    {}

    operator OperationTypeWithCommissionEnum() const {
        return value; 
    } 

    explicit operator bool() = delete;

    constexpr bool operator==(OperationTypeWithCommission currency) const {
        return value == currency.value; 
    }

    constexpr bool operator==(OperationTypeWithCommissionEnum currency) const {
        return value == currency; 
    }

    constexpr bool operator!=(OperationTypeWithCommission currency) const { 
        return value != currency.value; 
    }

    constexpr bool operator!=(OperationTypeWithCommissionEnum currency) const { 
        return value != currency; 
    }


    std::string to_string() const {
        switch (value) {
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

        return "";
    }
private:
    OperationTypeWithCommissionEnum value;
};