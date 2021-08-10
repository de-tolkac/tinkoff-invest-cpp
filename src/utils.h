#pragma once

#include <Currency.h>
#include <BrokerAccountType.h>
#include <OrderStatus.h>
#include <OperationType.h>

#include <string>

std::string toString(Currency&);
std::string toString(BrokerAccountType&);
std::string toString(OrderStatus&);
std::string toString(OperationType&);

OrderStatus toOrderStatus(std::string&&);

BrokerAccountType toBrokerAccountType(std::string&&);