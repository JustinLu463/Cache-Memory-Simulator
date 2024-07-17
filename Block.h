#ifndef BLOCK_H
#define BLOCK_H

#include <chrono>
#include "Memory.h"

class Block {
private:
    unsigned char* data;
    unsigned long tag;
    bool valid;
    bool dirty;
    int blockSize;
    long timestamp;
    Memory* memory;

public:
    Block(int blockSize, Memory* memory);
    ~Block();
    unsigned char read(int offset);
    void write(int offset, unsigned char value);
    void loadFromMemory(unsigned long address);
    void saveToMemory(unsigned long address);
    unsigned long getTag();
    bool isValid();
    bool isDirty();
    long getTimestamp();
    void setTag(unsigned long tag);
    void setValid(bool valid);
    void setDirty(bool dirty);
    void updateTimestamp();
    void display();
};

#endif
