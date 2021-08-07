#pragma once

#include <Currency.h>
#include <BrokerAccountType.h>

#include <string>

std::string toString(Currency&);
std::string toString(BrokerAccountType&);
BrokerAccountType toBrokerAccountType(std::string);