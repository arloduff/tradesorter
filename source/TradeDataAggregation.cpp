/******************************************************************************
 * TradeDataAggregation.cpp
 * 
 * Contains implementation for TradeDataAggregation.h
 * See that file for details of the functions contained here
 * 
 ******************************************************************************/

#include <string>
#include <vector>
#include <set>
#include "Trade.h"
#include "TradeData.h"
#include "TradeDataAggregation.h"

//This function loops over a vector of TradePointers to Trade objects, and creates a new TradeData object for the given symbol/exchange combination, if one is not already
//present in the set which it will return. If it is present, it adds the current trade's price and quantity of shares traded to that TradeData object, as well as the TradeData
//object corresponding to all trades for the given symbol, regardless of exchange.

std::set<Trade::TradeData> Trade::aggregateTradeData (const std::vector<TradePointer>& trades) {
    std::set<TradeData> data;           //The TradeData set we will return
    
    //Loop over every Trade object in our vector
    for(std::vector<TradePointer>::const_iterator x = trades.begin(); x < trades.end(); x++) {
        //Update or insert new TradeData object corresponding to this Trade's symbol and exchange combination
        insertTradeDataIfNotPresent(data, (*x)->getPrice(), (*x)->getQuantity(), (*x)->getSymbol(), (*x)->getExchange());
        //Update or insert new TradeData object corresponding to all Trade objects with the given symbol
        insertTradeDataIfNotPresent(data, (*x)->getPrice(), (*x)->getQuantity(), (*x)->getSymbol());
    }
    
    return data;
}

//Given a set of TradeData objects, a price, a quantity, a symbol, and an exchange corresponding to a given Trade, this function will search the set for the given TradeData
//object corresponding to the symbol/exchange combination, and update it if it exists, if not it will insert a new TradeData object corresponding to the given info.
//If the exchange is not specified, it will update the data corresponding to a TradeData object with no exchange, that is, the TradeData object which corresponds to all Trades
//of the given symbol

void Trade::insertTradeDataIfNotPresent (std::set<TradeData>& tradeSummaries, double price, int quantity, const std::string& symbol, const std::string& exchange) {
    TradeData entry(symbol, exchange);
    std::set<TradeData>::const_iterator i = tradeSummaries.find(entry);

    if(i == tradeSummaries.end()) { //If the entry is not yet in the set, add it
        entry.addTrade(price, quantity);
        tradeSummaries.insert(entry);
    } else {
        entry = *i;
        entry.addTrade(price, quantity);

        tradeSummaries.erase(i);
        tradeSummaries.insert(entry);
    }

}