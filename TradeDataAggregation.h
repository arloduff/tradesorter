/******************************************************************************
 * TradeDataAggregation.h
 * 
 * Contains functions to aggregate the data for all Trades objects
 * 
 *******************************************************************************/

#ifndef __TRADE_DATA_AGGREGATION
#define __TRADE_DATA_AGGREGATION 1

#include <string>
#include <vector>
#include <set>
#include "Trade.h"
#include "TradeData.h"

namespace Trade {
    
    /**
     * Given a vector of TradePointers to Trade objects, this will return a set of TradeData objects which contain the aggregated data corresponding to each symbol/exchange
     * combination
     * 
     * @param A vector of unique pointers to Trade objects
     */
    std::set<TradeData> aggregateTradeData (const std::vector<TradePointer>&);

    /**
     * Given a vector of unique pointers to Trade objects, and a set of TradeData objects, this function will create the appropriate TradeData object and insert it into the set
     * if it is not already present
     * 
     * @param A set of TradeData objects, which the computed data will be inserted into
     * @param The price to add to the TradeData object
     * @param The quantity of trades executed at this price
     * @param The symbol of the trades for which to aggregate the data
     * @param The exchange of the trades for which to aggregate the data. If this parameter is omitted, the function will add data to the TradeData object corresponding to
     *        all trades of a given symbol, regardless of their exchange
     */
    void insertTradeDataIfNotPresent (std::set<TradeData>&, double, int, const std::string&, const std::string& = std::string());

}

#endif
