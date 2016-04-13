/*******************************************************************************
 * TradeData.h
 * 
 * Contains the implementation for TradeData objects, which are used  to store
 * the data for all trades of a given symbol/exchange combination. The data they
 * can be used to retrieve is:
 * 
 * Symbol
 * Exchange
 * Minimum price paid for the given symbol/exchange combination
 * Average price paid for the given symbol/exchange combination
 * Maximum price paid for the given symbol/exchange combination
 * Number of quantities traded
 *  
 ******************************************************************************/

#ifndef __TRADEDATA
#define __TRADEDATA 1

#include <iostream>
#include <string>
#include <limits>

namespace Trade {
    const int PENNY_PRECISION(2);                                               //The precision with which to display the aggregated values
    const double MAXIMUM_DOUBLE_VALUE(std::numeric_limits<double>::max());      //The maximum value a double can hold
    
    class TradeData;
    
    /**
     * Ostream operator for outputting a TradeData object to a stream (e.g. cout or a file)
     * 
     * @param ostream object (e.g. cout)
     * @param TradeData object to be output
     * @return Reference to the ostream object passed in
     */
    std::ostream& operator<< (std::ostream&, const TradeData&);

    /**
     * Less-than comparison function, implemented so that TradeData objects can be stored in a set
     * 
     * @param Left-hand side
     * @param Right-hand side
     * @return 
     */
    bool operator< (const TradeData&, const TradeData&);
    
    class TradeData {
    public:
        /**
         * Constructor. Must take a symbol and an exchange. If the exchange is an empty string, then the object will correspond to all trades with the given symbol.
         * 
         * @param Symbol
         * @param Exchange
         */
        TradeData (const std::string&, const std::string&);
        
        //Getters
        const std::string& getSymbol () const;
        const std::string& getExchange () const;
        const double getMinimumPrice () const;
        const double getAveragePrice () const;
        const double getMaximumPrice () const;
        const int getQuantitiesTraded () const;
        
        /**
         * Adds a trade to the trades stored so far.
         * 
         * @param The price of the trade
         * @param The quantities associated with the trade
         * @return A reference to this
         */
        TradeData& addTrade (double, int);
        
    private:
        std::string symbol;
        std::string exchange;
        double minimumPrice;
        double maximumPrice;
        double totalPrice;      //A tally of the total price which has been paid for all shares of this option which have been traded
        int quantitiesTraded;   //A tally of all quantities corresponding to this type of trade
    };
}

#endif