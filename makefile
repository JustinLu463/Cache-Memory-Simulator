CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJS = Simulation.o Memory.o Cache.o Set.o Block.o AddressDecoder.o PerformanceCounter.o

all: cache_simulator

cache_simulator: $(OBJS)
	$(CXX) $(CXXFLAGS) -o cache_simulator $(OBJS)

Simulation.o: Simulation.cc Memory.h Cache.h
	$(CXX) $(CXXFLAGS) -c Simulation.cc

Memory.o: Memory.cc Memory.h
	$(CXX) $(CXXFLAGS) -c Memory.cc

Cache.o: Cache.cc Cache.h Set.h AddressDecoder.h PerformanceCounter.h
	$(CXX) $(CXXFLAGS) -c Cache.cc

Set.o: Set.cc Set.h Block.h AddressDecoder.h PerformanceCounter.h
	$(CXX) $(CXXFLAGS) -c Set.cc

Block.o: Block.cc Block.h Memory.h
	$(CXX) $(CXXFLAGS) -c Block.cc

AddressDecoder.o: AddressDecoder.cc AddressDecoder.h
	$(CXX) $(CXXFLAGS) -c AddressDecoder.cc

PerformanceCounter.o: PerformanceCounter.cc PerformanceCounter.h
	$(CXX) $(CXXFLAGS) -c PerformanceCounter.cc

clean:
	rm -f *.o cache_simulator
