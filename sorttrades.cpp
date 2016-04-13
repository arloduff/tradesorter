/*****************************************************************************
 * Sort Trades
 * Arlo DUff
 * 
 * This program parses a CSV file of trades to Trade objects, aggregates them into
 * TradeData objects, which rougly correspond to the format of the output file
 * which is generated, and outputs that aggregated data to a CSV file. The
 * generated file contains the minimum price, average price, maximum price, and
 * number of quantities sold for each symbol/exchange combination, as well as
 * for all trades of a given symbol.
 * 
 * To aggregate the data, a vector of unique pointers to Trade objects is used
 * to store the information input from the CSV file. For the output, a binary
 * tree of TradeData objects is used. The operator< function has been overloaded
 * so that TreeData objects can be inserted into C++'s implementation of a binary
 * tree. Additionally, the use of the binary tree ensures greater runtime efficiency,
 * as well as having the added advantage of sorting the output data for us.
 * 
 *****************************************************************************/

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <set>
#include "Trade.h"
#include "TradeIO.h"
#include "TradeDataAggregation.h"
using namespace std;

/**
 * Displays the instructions for running this program.
 * 
 * @param The command used to run this program.
 */
void displayHelp (const string&);

int main (int argc, char* argv[]) {
    string inputFile;                                   //Filename of our input file
    string outputFile;                                  //Filename of our output file
    vector<unique_ptr<Trade::Trade>> trades;
    set<Trade::TradeData> data;
                
    //Make sure enough arguments were provided
    if(argc < 3) {
        displayHelp(argv[0]);
        return 0;
    } //else

    //Get filenames for input and output
    inputFile = argv[1];
    outputFile = argv[2];

    //Aggregate the data
    trades = Trade::readFileToTrades(inputFile);
    data = Trade::aggregateTradeData(trades);
    
    //Output the aggregated data
    Trade::writeTradesDataToFile(data, outputFile);
    
    return 0;
}

void displayHelp (const string& me) {
    cout << "Usage: ";
    cout << me << " [input] [output]" << endl;
    cout << "\t Where [input] is the name of the input file to process and [output] is the file to generate." << endl;
}
