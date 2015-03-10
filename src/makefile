CC=g++
CFLAGS=-c -std=c++11

all: AlgorithmicTrading

AlgorithmicTrading: main.o MomentumStrategy.o Strategy.o TradeDay.o StrategyResult.o Logger.o
	$(CC) main.o MomentumStrategy.o Strategy.o TradeDay.o StrategyResult.o Logger.o -o AlgorithmicTrading

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

MomentumStrategy.o: MomentumStrategy.cpp
	$(CC) $(CFLAGS) MomentumStrategy.cpp

Strategy.o: Strategy.cpp
	$(CC) $(CFLAGS) Strategy.cpp

TradeDay.o: TradeDay.cpp
	$(CC) $(CFLAGS) TradeDay.cpp

StrategyResult.o: StrategyResult.cpp
	$(CC) $(CFLAGS) StrategyResult.cpp

Logger.o: Logger.cpp
	$(CC) $(CFLAGS) Logger.cpp

clean:
	rm *.o AlgorithmicTrading
