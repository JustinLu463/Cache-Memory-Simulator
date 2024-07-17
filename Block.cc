#include "Block.h"

Block::Block(int blockSize, Memory* memory) {
    this->blockSize = blockSize;
    this->memory = memory;
    data = new unsigned char[blockSize];
    valid = false;
    dirty = false;
    tag = 0;
    timestamp = 0;
}

Block::~Block() {
    delete[] data;
}

unsigned char Block::read(int offset) {
    updateTimestamp();
    return data[offset];
}

void Block::write(int offset, unsigned char value) {
    updateTimestamp();
    data[offset] = value;
    dirty = true;
}

void Block::loadFromMemory(unsigned long address) {
    for (int i = 0; i < blockSize; i++) {
        data[i] = memory->getByte(address + i);
    }
    valid = true;
    dirty = false;
}

void Block::saveToMemory(unsigned long address) {
    if (dirty) {
        for (int i = 0; i < blockSize; i++) {
            memory->setByte(address + i, data[i]);
        }
    }
}

unsigned long Block::getTag() {
    return tag;
}

bool Block::isValid() {
    return valid;
}

bool Block::isDirty() {
    return dirty;
}

long Block::getTimestamp() {
    return timestamp;
}

void Block::setTag(unsigned long tag) {
    this->tag = tag;
}

void Block::setValid(bool valid) {
    this->valid = valid;
}

void Block::setDirty(bool dirty) {
    this->dirty = dirty;
}

void Block::updateTimestamp() {
    auto now = std::chrono::high_resolution_clock::now();
    timestamp = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
}

void Block::display() {
    std::cout << "    valid: " << valid << "    tag: " << tag << "    dirty: " << dirty << "    timestamp: " << timestamp << std::endl;
    for (int i = 0; i < blockSize; i++) {
        std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)data[i] << " ";
    }
    std::cout << std::dec << std::endl;
}
