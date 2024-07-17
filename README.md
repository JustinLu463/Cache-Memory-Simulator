Cache Memory Simulator:
- This project is a C++ implementation of a cache memory simulator.

Contents:
- AddressDecoder.cc: Implementation of the address decoder.
- AddressDecoder.h: Header file for the address decoder.
- Block.cc: Implementation of a cache block.
- Block.h: Header file for a cache block.
- Cache.cc: Implementation of the cache.
- Cache.h: Header file for the cache.
- Memory.cc: Implementation of the main memory.
- Memory.h: Header file for the main memory.
- PerformanceCounter.cc: Implementation of the performance counter.
- PerformanceCounter.h: Header file for the performance counter.
- Set.cc: Implementation of a cache set.
- Set.h: Header file for a cache set.
- Simulation.cc: Main file to run the cache memory simulation.
- makefile: Makefile for building the project.

Prerequisites:
To run this project, you'll need the following:
- A C++ compiler (e.g., g++).
- Make utility.

How It Works:
The cache memory simulator models the behavior of a cache memory system. It includes the following components:
- Address Decoder: Decodes memory addresses to identify cache set and block offsets.
- Cache: Represents the cache with multiple sets, each containing multiple blocks.
- Memory: Simulates the main memory.
- Performance Counter: Tracks the performance metrics such as hit rate and miss rate.

Simulation:
- The main simulation logic is implemented in Simulation.cc. The simulator reads memory access patterns, processes them through the cache, and records performance metrics.
