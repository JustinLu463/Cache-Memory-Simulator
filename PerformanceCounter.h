#ifndef PERFORMANCECOUNTER_H
#define PERFORMANCECOUNTER_H

#include <iostream>

class PerformanceCounter {
private:
    int hits;
    int misses;
    int writebacks;

public:
    PerformanceCounter();
    void incrementHits();
    void incrementMisses();
    void incrementWritebacks();
    void display();
};

#endif
