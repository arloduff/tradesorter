/******************************************************************************
 * TradeIO.h
 * 
 * Contains utility functions for parsing a CSV file to a vector of TradePointer
 * objects, or writing a set of TradeData objects to a file.
 * 
 ******************************************************************************/

#ifndef __TRADEIO
#define __TRADEIO 1

#include <string>
#include <vector>
#include <set>
#include "Trade.h"
#include "TradeData.h"

namespace Trade {
   /**
    * Parses a CSV file, converting each line to a Trade object, and returning a
    * vector of TradePointers to each object parsed from the file.
    * 
    * @param The filename of the CSV file to parse
    * @return A vector of TradePointers to the Trade objects parsed
    */
    std::vector<TradePointer> readFileToTrades (const std::string&);
    
    /**
     * Writes each TradeData object from the given set to a file.
     * 
     * @param The set of TradeData objects to write.
     * @param The filename to write to. Will be overridden if it already exists.
     */
    void writeTradesDataToFile (const std::set<TradeData>&, const std::string&);
}

#endif
