#pragma once

#include <Currency.h>
#include <BrokerAccountType.h>
#include <OrderStatus.h>
#include <OperationType.h>
#include <OrderType.h>
#include <CandleInterval.h>
#include <InstrumentType.h>
#include <OperationStatus.h>
#include <OperationType.h>
#include <TradeStatus.h>

#include <string>

std::string toString(const Currency&);
std::string toString(const BrokerAccountType&);
std::string toString(const OrderStatus&);
std::string toString(const OrderType&);
std::string toString(const CandleInterval&);
std::string toString(const InstrumentType&);
std::string toString(const OperationStatus&);
std::string toString(const OperationType&);
std::string toString(const TradeStatus&);

Currency toCurrency(std::string&&);
OrderStatus toOrderStatus(std::string&&);
BrokerAccountType toBrokerAccountType(std::string&&);
CandleInterval toCandleInterval(std::string&&);
InstrumentType toInstrumentType(std::string&&);
OperationStatus toOperationStatus(std::string&&);
OperationType toOperationType(std::string&&);
TradeStatus toTradeStatus(std::string&&);