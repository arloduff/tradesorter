/*****************************************************************************
 * Trade.cpp
 * 
 * Implementation file for Trade.h
 * See that file for details of what this file implements
 *****************************************************************************/

#include <string>
#include "Trade.h"

Trade::Trade::Trade (const std::string& s, const std::string& e, const double p, const int q) : symbol(s), exchange(e), price(p), quantity(q) {}

const std::string& Trade::Trade::getSymbol () const {
    return symbol;
}

const std::string& Trade::Trade::Trade::getExchange () const {
    return exchange;
}

const double Trade::Trade::getPrice () const {
    return price;
}

const int Trade::Trade::getQuantity () const {
    return quantity;
}
