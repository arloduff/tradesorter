# Tradesorter #

This is a sample C++11 program to parse a CSV file listing a number of stock trades and produce an output file listing the minimum, maximum, and average prices at which the stock was traded. If a stock was traded on more than one exchange, then the output will list separate averages for each exchange on which it was traded.

Each line of the input files specifies one trade listing the symbol name, exchange name, stock price, and number of shares traded, separated by commas.

Sample input from a file might look something like this:

    GOOG,NYSE,0.45,35
    HUBS,NSDQ,0.09,20
    YHOO,DOW,0.16,20
    GOOG,SNP,0.22,45
    HUBS,NYSE,0.22,40
    YHOO,NSDQ,0.47,10
    GOOG,DOW,0.10,50
    HUBS,SNP,0.08,15
    YHOO,NYSE,0.18,25
    GOOG,NSDQ,0.07,25
    HUBS,DOW,0.10,35
    YHOO,SNP,0.33,10
    GOOG,NYSE,0.20,10
    HUBS,NSDQ,0.15,45
    YHOO,DOW,0.36,15
    GOOG,SNP,0.11,25
    HUBS,NYSE,0.38,10
    YHOO,NSDQ,0.16,25
    GOOG,DOW,0.26,45
    HUBS,SNP,0.11,10
    YHOO,NYSE,0.40,10
    GOOG,NSDQ,0.26,35
    HUBS,DOW,0.33,10
    YHOO,SNP,0.19,15
    GOOG,NYSE,0.15,20
    HUBS,NSDQ,0.50,20
    YHOO,DOW,0.49,10
    GOOG,SNP,0.35,30
    HUBS,NYSE,0.35,45
    YHOO,NSDQ,0.04,15
    GOOG,DOW,0.45,25
    HUBS,SNP,0.42,15
    YHOO,NYSE,0.20,25
    GOOG,NSDQ,0.48,5
    HUBS,DOW,0.40,40

The output generated specifies the stock symbol, the exchange, the minimum price, average price, maximum price, and total number of trades.

A sample output file might look like:

    GOOG,,0.07,0.24,0.48,350
    GOOG,NYSE,0.15,0.32,0.45,65
    GOOG,NSDQ,0.07,0.20,0.48,65
    GOOG,DOW,0.10,0.23,0.45,120
    GOOG,SNP,0.11,0.23,0.35,100
    HUBS,,0.08,0.26,0.50,305
    HUBS,NYSE,0.22,0.30,0.38,95
    HUBS,NSDQ,0.09,0.22,0.50,85
    HUBS,DOW,0.10,0.27,0.40,85
    HUBS,SNP,0.08,0.21,0.42,40
    YHOO,,0.04,0.27,0.49,220
    YHOO,NYSE,0.18,0.23,0.40,60
    YHOO,NSDQ,0.04,0.19,0.47,50
    YHOO,DOW,0.16,0.30,0.49,45

The lines that contain no index (`,,`) indicate averages across all the indices.

## Installation ##

Running your C++ compiler with the C++11 option enabled should do the trick on most systems. On a Linux system with g++ installed, the following command should work:

    g++ sorttrades.cpp Trade.cpp TradeData.cpp TradeIO.cpp TradeDataAggregation.cpp -o sorttrades.o -std=c++0x

Additionally, if `g++` is in your path, then simply running `make` should build the project.

## Running the Program ##

The program operates from the command line and takes two arguments: the first is the name of the input file to process, and the second is the name of the output file to which to write data. For example, if you created a file named `input1.csv` containing the input file form the example above, then running

    ./sorttrades.o input1.csv output1.csv

would produce the output from the example above in a new file named `output1.csv`

