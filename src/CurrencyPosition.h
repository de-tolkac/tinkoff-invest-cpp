#pragma once

#include <Currency.h>

struct  CurrencyPosition {
    Currency currency;

    double balance;
    double blocked;
};
