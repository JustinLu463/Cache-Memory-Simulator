#include "AddressDecoder.h"
#include <cmath>

AddressDecoder::AddressDecoder(int numSets, int blockSize) {
    setBits = log2(numSets);
    blockBits = log2(blockSize);
}

unsigned long AddressDecoder::getTag(unsigned long address) {
    return address >> (setBits + blockBits);
}

unsigned long AddressDecoder::getSetIndex(unsigned long address) {
    return (address >> blockBits) & ((1 << setBits) - 1);
}

unsigned long AddressDecoder::getBlockOffset(unsigned long address) {
    return address & ((1 << blockBits) - 1);
}

unsigned long AddressDecoder::getBlockAddress(unsigned long address) {
    return address & ~((1 << blockBits) - 1);
}
