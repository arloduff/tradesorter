sorttrades.o: sorttrades.cpp Trade.h Trade.cpp TradeData.h TradeData.cpp TradeIO.h TradeIO.cpp TradeDataAggregation.h TradeDataAggregation.cpp
	g++ sorttrades.cpp Trade.cpp TradeData.cpp TradeIO.cpp TradeDataAggregation.cpp -o sorttrades.o -std=c++0x

