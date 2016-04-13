sorttrades.o: source/sorttrades.cpp source/Trade.h source/Trade.cpp source/TradeData.h source/TradeData.cpp source/TradeIO.h source/TradeIO.cpp source/TradeDataAggregation.h source/TradeDataAggregation.cpp
	g++ source/sorttrades.cpp source/Trade.cpp source/TradeData.cpp source/TradeIO.cpp source/TradeDataAggregation.cpp -o sorttrades.o -std=c++0x

