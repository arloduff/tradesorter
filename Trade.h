/******************************************************************************
 * Trade.h
 * 
 * Contains the representation for a Trade object.
 * A Trade is a single trade that was executed for a given symbol and exchange,
 * at a certain price, and with a certain number of quantities. It corresponds to
 * each line in the CSV file for this exercise.
 * 
 * The data that can be retrieved from this object is:
 * 
 * Symbol
 * Exchange
 * Price at which the shares were traded
 * Quantity of shares traded
 * 
 ******************************************************************************/

#ifndef __TRADE
#define __TRADE 1

#include <string>
#include <memory>

namespace Trade {
    class Trade;
    typedef std::unique_ptr<Trade> TradePointer;
    
    class Trade {
        public:
            Trade (const std::string&, const std::string&, const double, const int);

            //Getters
            const std::string& getSymbol () const;
            const std::string& getExchange () const;
            const double getPrice () const;
            const int getQuantity () const;

        private:
            std::string symbol;
            std::string exchange;
            double price;
            int quantity;
    };
}


#endif
