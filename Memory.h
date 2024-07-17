#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <iomanip>

class Memory {
private:
    int size;
    unsigned char* bytes;

public:
    Memory(int size);
    ~Memory();
    unsigned char getByte(unsigned long address);
    void setByte(unsigned long address, unsigned char value);
    int getSize();
    void display();
};

#endif
