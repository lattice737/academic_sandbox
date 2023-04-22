/** @file MemoryAllocationExcept */

#include "MemoryAllocationExcept.h"

MemoryAllocationExcept::MemoryAllocationExcept(const string& message) : runtime_error("Memory Allocation Exception: " + message) {}