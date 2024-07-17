#include "PerformanceCounter.h"

PerformanceCounter::PerformanceCounter() {
    hits = 0;
    misses = 0;
    writebacks = 0;
}

void PerformanceCounter::incrementHits() {
    hits++;
}

void PerformanceCounter::incrementMisses() {
    misses++;
}

void PerformanceCounter::incrementWritebacks() {
    writebacks++;
}

void PerformanceCounter::display() {
    std::cout << "Accesses: " << (hits + misses) << std::endl;
    std::cout << "Hits: " << hits << std::endl;
    std::cout << "Misses: " << misses << std::endl;
    std::cout << "Writebacks: " << writebacks << std::endl;
    std::cout << "Miss Perc: " << (misses * 100.0) / (hits + misses) << std::endl;
    std::cout << "Writeback Perc: " << (writebacks * 100.0) / (hits + misses) << std::endl;
}
