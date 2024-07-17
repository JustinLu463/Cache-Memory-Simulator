#ifndef CACHE_H
#define CACHE_H

#include "Set.h"
#include "AddressDecoder.h"
#include "PerformanceCounter.h"

class Cache {
private:
    Set** sets;
    int numSets;
    int setSize;
    Memory* memory;
    AddressDecoder* decoder;
    PerformanceCounter* counter;

public:
    Cache(Memory* memory, int cacheSize, int blockSize, int associativity);
    ~Cache();
    unsigned char read(unsigned long address);
    void write(unsigned long address, unsigned char value);
    void display();
};

#endif
