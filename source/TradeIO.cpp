/******************************************************************************
 * TradeIO.cpp
 * 
 * Implementation file for TradeIO.h.
 * See that file for details of what this code implements.
 * 
 *******************************************************************************/

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "Trade.h"
#include "TradeIO.h"

//Reads a CSV file and converts it to a vector of unique pointers to Trade objects

std::vector<std::unique_ptr<Trade::Trade>> Trade::readFileToTrades (const std::string& filename) {
    std::vector<TradePointer> trades;                         //Our vector of TradePointers which we will return

    std::ifstream file(filename.c_str(), std::ifstream::in); //This is our input file
    std::string line;                                        //Each line we read will be kept here

    std::getline(file, line);    //Get past first line, which just describes the data

    while(file) {
        std::string symbol;
        std::string exchange;
        std::string price;
        std::string quantity;
        std::istringstream values;      //An istreamstring object we use to convert the line to a stream for processing with getline after we read each line

        //If we can't read anymore from the file, it's time to break the loop
        if(!std::getline(file, line)) {
            break;
        } //else

        values.str(line);   //Set our istringstream to our line of text so we can parse its value

        //Now, for each line, get the values
        std::getline(values, symbol, ',');
        std::getline(values, exchange, ',');
        std::getline(values, price, ',');
        std::getline(values, quantity);

        //Create a new Trade object, point a TradePointer to it, and insert that into our vector
        trades.push_back(std::move(TradePointer(new Trade(symbol, exchange, std::atof(price.c_str()), std::atoi(quantity.c_str())))));
    }

    file.close();
    return trades;
}

//Writes a set of TradeData objects to a file. Since the TradeData objects are stored in a set, this guarantees that they will be output in the correct sorted order for us.

void Trade::writeTradesDataToFile (const std::set<TradeData>& tradeDataSet, const std::string& filename) {
    std::ofstream file(filename.c_str(), std::ofstream::out);   //This is our output file that we will write to
    
    file << "Symbol,Exchange,Min Price,Avg Price,Max Price,Total Qty" << std::endl;
    
    //Go over the entire set and output everything to the file
    //TradeData's operator<< function has already been overloaded to handle converting this data to CSV
    for(std::set<TradeData>::const_iterator x = tradeDataSet.begin(); x != tradeDataSet.end(); x++) {
        file << *x << std::endl;
    }
    
    file.close();
}