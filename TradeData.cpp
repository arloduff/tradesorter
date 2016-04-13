/*****************************************************************************
 * TradeData.cpp
 * 
 * Implementation file for TradeData.h
 * See that file for a description of this class.
 * 
 ******************************************************************************/

#include <iostream>
#include <string>
#include "TradeData.h"

//Constructor

Trade::TradeData::TradeData (const std::string& sym, const std::string& exc) 
        : symbol(sym), exchange(exc), totalPrice(), minimumPrice(MAXIMUM_DOUBLE_VALUE), quantitiesTraded(0) {}
        //Here, minimumPrice is initialized to the maximum value a double can hold so that our algorithm for keeping track of the minimum price will work later

//Getters

const std::string& Trade::TradeData::getSymbol () const {
    return symbol;
}

const std::string& Trade::TradeData::getExchange () const {
    return exchange;
}

const double Trade::TradeData::getMinimumPrice () const {
    return minimumPrice;
}

const double Trade::TradeData::getAveragePrice () const {
    //This seemingly pointless multiplication and division by 100 is necessary to correct floating point precision errors
    return totalPrice / quantitiesTraded * 100 / 100;
}

const double Trade::TradeData::getMaximumPrice () const {
    return maximumPrice;
}

const int Trade::TradeData::getQuantitiesTraded () const {
    return quantitiesTraded;
}

//Inserts another trade into the TradeData object

Trade::TradeData& Trade::TradeData::addTrade (double price, int quantity) {
    //Update our tally of the total price paid, and the quantities traded
    totalPrice += price * quantity;
    quantitiesTraded += quantity;
    
    //Update minimum and maximum prices, if needed
    if(price < minimumPrice) {
        minimumPrice = price;
    }
    
    if(price > maximumPrice) {
        maximumPrice = price;
    }
    
    return *this;
}

// Ostream function for outputting the TradeData object to a stream, such as cout

std::ostream& Trade::operator<< (std::ostream& os, const Trade::TradeData& rhs) {
    //We have to change the precision and format flags, so we should be sure to set them back later
    int precision = os.precision(PENNY_PRECISION);
    std::ios_base::fmtflags flags = os.flags(os.flags() | std::ios_base::fixed);
    //Change the floatfield so it always displays two decimal places
    os.setf(std::ios::fixed, std::ios::floatfield);

    os << rhs.getSymbol() << ',' << rhs.getExchange() << ',' << rhs.getMinimumPrice() << ',' << rhs.getAveragePrice() << ',' << rhs.getMaximumPrice() << ',' << rhs.getQuantitiesTraded();

    //Set the precision and floafields back to what they were
    os.precision(precision);
    os.flags(flags);
    return os;
}

//Less than operator, implemented so that TradeData objects can be inserted into a set. The TradeData objects should be ordered first by symbol, and then by exchange

bool Trade::operator< (const Trade::TradeData& lhs, const Trade::TradeData& rhs) {
    //First, compare the symbols
    if(lhs.getSymbol().compare(rhs.getSymbol()) != 0) {  //If the symbols are not the same
        return lhs.getSymbol().compare(rhs.getSymbol()) < 0;
    } //else (If the symbols are the same, then we should order the two trades based on their exchanges)
    
    return lhs.getExchange().compare(rhs.getExchange()) < 0;
}