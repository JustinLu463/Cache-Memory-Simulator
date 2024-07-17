#ifndef ADDRESSDECODER_H
#define ADDRESSDECODER_H

class AddressDecoder {
private:
    int setBits;
    int blockBits;

public:
    AddressDecoder(int numSets, int blockSize);
    unsigned long getTag(unsigned long address);
    unsigned long getSetIndex(unsigned long address);
    unsigned long getBlockOffset(unsigned long address);
    unsigned long getBlockAddress(unsigned long address);
};

#endif
