#include "Set.h"

Set::Set(int numBlocks, int blockSize, Memory* memory, AddressDecoder* decoder, PerformanceCounter* counter) {
    this->numBlocks = numBlocks;
    this->blockSize = blockSize;
    this->memory = memory;
    this->decoder = decoder;
    this->counter = counter;
    blocks = new Block*[numBlocks];
    for (int i = 0; i < numBlocks; i++) {
        blocks[i] = new Block(blockSize, memory);
    }
}

Set::~Set() {
    for (int i = 0; i < numBlocks; i++) {
        delete blocks[i];
    }
    delete[] blocks;
}

unsigned char Set::read(unsigned long address) {
    unsigned long tag = decoder->getTag(address);
    int blockIndex = findBlockWithTag(tag);
    if (blockIndex == -1) {
        blockIndex = findBlockToReplace();
        blocks[blockIndex]->saveToMemory(decoder->getBlockAddress(address));
        blocks[blockIndex]->loadFromMemory(decoder->getBlockAddress(address));
        blocks[blockIndex]->setTag(tag);
        counter->incrementMisses();
    } else {
        counter->incrementHits();
    }
    return blocks[blockIndex]->read(decoder->getBlockOffset(address));
}

void Set::write(unsigned long address, unsigned char value) {
    unsigned long tag = decoder->getTag(address);
    int blockIndex = findBlockWithTag(tag);
    if (blockIndex == -1) {
        blockIndex = findBlockToReplace();
        blocks[blockIndex]->saveToMemory(decoder->getBlockAddress(address));
        blocks[blockIndex]->loadFromMemory(decoder->getBlockAddress(address));
        blocks[blockIndex]->setTag(tag);
        counter->incrementMisses();
    } else {
        counter->incrementHits();
    }
    blocks[blockIndex]->write(decoder->getBlockOffset(address), value);
}

void Set::display() {
    for (int i = 0; i < numBlocks; i++) {
        std::cout << "  " << i << ": " << std::endl;
        blocks[i]->display();
    }
}

int Set::findBlockToReplace() {
    int lruIndex = 0;
    long lruTime = blocks[0]->getTimestamp();
    for (int i = 1; i < numBlocks; i++) {
        if (blocks[i]->getTimestamp() < lruTime) {
            lruIndex = i;
            lruTime = blocks[i]->getTimestamp();
        }
    }
    return lruIndex;
}

int Set::findBlockWithTag(unsigned long tag) {
    for (int i = 0; i < numBlocks; i++) {
        if (blocks[i]->isValid() && blocks[i]->getTag() == tag) {
            return i;
        }
    }
    return -1;
}

int Set::findEmptyBlock() {
    for (int i = 0; i < numBlocks; i++) {
        if (!blocks[i]->isValid()) {
            return i;
        }
    }
    return -1;
}
