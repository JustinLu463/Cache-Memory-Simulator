#include "Cache.h"

Cache::Cache(Memory* memory, int cacheSize, int blockSize, int associativity) {
    this->memory = memory;
    this->numSets = cacheSize / (blockSize * associativity);
    this->setSize = associativity;
    this->decoder = new AddressDecoder(numSets, blockSize);
    this->counter = new PerformanceCounter();
    sets = new Set*[numSets];
    for (int i = 0; i < numSets; i++) {
        sets[i] = new Set(associativity, blockSize, memory, decoder, counter);
    }
}

Cache::~Cache() {
    for (int i = 0; i < numSets; i++) {
        delete sets[i];
    }
    delete[] sets;
    delete decoder;
    delete counter;
}

unsigned char Cache::read(unsigned long address) {
    int setIndex = decoder->getSetIndex(address);
    return sets[setIndex]->read(address);
}

void Cache::write(unsigned long address, unsigned char value) {
    int setIndex = decoder->getSetIndex(address);
    sets[setIndex]->write(address, value);
}

void Cache::display() {
    for (int i = 0; i < numSets; i++) {
        std::cout << "  Set " << i << std::endl;
        sets[i]->display();
    }
    counter->display();
}
