#include "Memory.h"

Memory::Memory(int size) {
    this->size = size;
    bytes = new unsigned char[size];
    for (int i = 0; i < size; i++) {
        bytes[i] = i % 255;
    }
}

Memory::~Memory() {
    delete[] bytes;
}

unsigned char Memory::getByte(unsigned long address) {
    return bytes[address];
}

void Memory::setByte(unsigned long address, unsigned char value) {
    bytes[address] = value;
}

int Memory::getSize() {
    return size;
}

void Memory::display() {
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)bytes[i] << " ";
        if ((i + 1) % 16 == 0) std::cout << std::endl;
    }
    std::cout << std::dec;
}
