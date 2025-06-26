# Makefile for JSON generator (EE1520 Style)
# Project: ModuleConfig JSON Writer

CXX = g++ -std=c++14

# jsoncpp include path
CFLAGS = -g -I/usr/include/jsoncpp

# jsoncpp lib path and linking
LDFLAGS = -L/opt/homebrew/lib -ljsoncpp

CORE_INCS = \
	Signal.h Time.h ClockConfig.h ResetConfig.h IOPort.h IOPattern.h ModuleConfig.h

CORE_OBJS = \
	Signal.o Time.o ClockConfig.o ResetConfig.o IOPort.o IOPattern.o ModuleConfig.o

all: main

# object file rules
Signal.o: Signal.cpp $(CORE_INCS)
	$(CXX) -c $(CFLAGS) Signal.cpp

Time.o: Time.cpp $(CORE_INCS)
	$(CXX) -c $(CFLAGS) Time.cpp

ClockConfig.o: ClockConfig.cpp $(CORE_INCS)
	$(CXX) -c $(CFLAGS) ClockConfig.cpp

ResetConfig.o: ResetConfig.cpp $(CORE_INCS)
	$(CXX) -c $(CFLAGS) ResetConfig.cpp

IOPort.o: IOPort.cpp $(CORE_INCS)
	$(CXX) -c $(CFLAGS) IOPort.cpp

IOPattern.o: IOPattern.cpp $(CORE_INCS)
	$(CXX) -c $(CFLAGS) IOPattern.cpp

ModuleConfig.o: ModuleConfig.cpp $(CORE_INCS)
	$(CXX) -c $(CFLAGS) ModuleConfig.cpp

main.o: main.cpp $(CORE_INCS)
	$(CXX) -c $(CFLAGS) main.cpp

main: $(CORE_OBJS) main.o
	$(CXX) -o main $(CORE_OBJS) main.o $(LDFLAGS)

clean:
	rm -f *.o *~ core main
