#ifndef SET_H
#define SET_H

#include "Block.h"
#include "AddressDecoder.h"
#include "PerformanceCounter.h"

class Set {
private:
    Block** blocks;
    int numBlocks;
    int blockSize;
    Memory* memory;
    AddressDecoder* decoder;
    PerformanceCounter* counter;

public:
    Set(int numBlocks, int blockSize, Memory* memory, AddressDecoder* decoder, PerformanceCounter* counter);
    ~Set();
    unsigned char read(unsigned long address);
    void write(unsigned long address, unsigned char value);
    void display();
private:
    int findBlockToReplace();
    int findBlockWithTag(unsigned long tag);
    int findEmptyBlock();
};

#endif
