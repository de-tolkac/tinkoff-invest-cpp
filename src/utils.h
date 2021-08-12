#pragma once

#include <Currency.h>
#include <BrokerAccountType.h>
#include <OrderStatus.h>
#include <OperationType.h>
#include <OrderType.h>
#include <CandleInterval.h>

#include <string>

std::string toString(const Currency&);
std::string toString(const BrokerAccountType&);
std::string toString(const OrderStatus&);
std::string toString(const OperationType&);
std::string toString(const OrderType&);
std::string toString(const CandleInterval&);

Currency toCurrency(std::string&&);
OrderStatus toOrderStatus(std::string&&);
BrokerAccountType toBrokerAccountType(std::string&&);
CandleInterval toCandleInterval(std::string&&);