#pragma once

#include <Currency.h>
#include <BrokerAccountType.h>
#include <OrderStatus.h>
#include <OperationType.h>
#include <OrderType.h>

#include <string>

std::string toString(Currency&);
std::string toString(BrokerAccountType&);
std::string toString(const OrderStatus&);
std::string toString(const OperationType&);
std::string toString(const OrderType&);

OrderStatus toOrderStatus(std::string&&);

BrokerAccountType toBrokerAccountType(std::string&&);