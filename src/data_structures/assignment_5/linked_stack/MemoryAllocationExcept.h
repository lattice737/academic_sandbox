/** @file MemoryAllocationExcept.h */

#ifndef MEMORY_ALLOCATION_EXCEPT_
#define MEMORY_ALLOCATION_EXCEPT_

#include <stdexcept>
#include <string>

using namespace std;

class MemoryAllocationExcept: public runtime_error {
    public:
        MemoryAllocationExcept(const string& message = "");
};

#endif