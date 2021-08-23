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
#include <OperationTypeWithCommission.h>

#include <string>
#include <ctime>


std::string to_string(BrokerAccountType);
std::string to_string(CandleInterval);
std::string to_string(Currency);
std::string to_string(InstrumentType);
std::string to_string(OperationStatus);
std::string to_string(OperationType);
std::string to_string(OperationTypeWithCommission);
std::string to_string(OrderStatus);
std::string to_string(OrderType);
std::string to_string(TradeStatus);

std::string toString(const time_t&);


Currency toCurrency(std::string&&);
OrderStatus toOrderStatus(std::string&&);
OrderType toOrderType(std::string&&);
BrokerAccountType toBrokerAccountType(std::string&&);
CandleInterval toCandleInterval(std::string&&);
InstrumentType toInstrumentType(std::string&&);
OperationStatus toOperationStatus(std::string&&);
OperationType toOperationType(std::string&&);
TradeStatus toTradeStatus(std::string&&);
OperationTypeWithCommission toOperationTypeWithCommission(std::string&&);
time_t toDate(std::string&&);