#pragma once

enum class OperationTypeWithCommission {
    Buy, BuyCard, Sell, BrokerCommission, ExchangeCommission, ServiceCommission,
    MarginCommission, OtherCommission, PayIn, PayOut, Tax, TaxLucre, TaxDividend,
    TaxCoupon, TaxBack, Repayment, PartRepayment, Coupon, Dividend, SecurityIn, SecurityOut
};