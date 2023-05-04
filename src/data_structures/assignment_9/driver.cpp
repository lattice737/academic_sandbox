// Programmer:      Nicholas Martinez
// Project number:  9
// Project Desc:    Array-based implementation of heap
// Course:          COSC 2436 PF III Data Structures
// Date:            5//23

#include "PrecondViolatedExcep.h"
#include "ArrayMaxHeap.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// [x] Implement test suite with two data types (test-driven development)
// [x] Complete ArrayMaxHeap implementation
// [ ] Implement heap sorting (p556 in Notability)

void sortHeap(ArrayMaxHeap<int>* heap) {
   // 1) Use the explicit-value constructor to copy the contents of the array into a max heap
   // 2) Remove the largest value from the max heap and insert in the array at the last position
   // 3) Keep removing the next largest value from the array and place it in the array at progressively lower positions until the max heap is empty
   return;
}

void sortHeap(ArrayMaxHeap<string>* heap) {
   return;
}

void addIntegers(ArrayMaxHeap<int>* heap, int maxInt) {
   for (int i=0; i<9; i++)
      heap->add(rand() % 10000);
   heap->add(maxInt);
}

void addStrings(ArrayMaxHeap<string>* heap, string maxString) {
   string greeks[] = {"gamma", "sigma", "alpha", "epsilon", "pi", "rho", "beta", "phi", "zeta"};
   for (int i=0; i<9; i++)
      heap->add(greeks[i]);
   heap->add(maxString);
}

bool testIsEmpty(ArrayMaxHeap<int>* heap, bool expected) {
   bool passed = heap->isEmpty() == expected;
   cout << "isEmpty() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

bool testIsEmpty(ArrayMaxHeap<string>* heap, bool expected) {
   bool passed = heap->isEmpty() == expected;
   cout << "isEmpty() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

bool testGetNumberOfNodes(ArrayMaxHeap<int>* heap, int expected) {
   bool passed = heap->getNumberOfNodes() == expected;
   cout << "getNumberOfNodes() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

bool testGetNumberOfNodes(ArrayMaxHeap<string>* heap, int expected) {
   bool passed = heap->getNumberOfNodes() == expected;
   cout << "getNumberOfNodes() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

bool testGetHeight(ArrayMaxHeap<int>* heap, int expected) {
   bool passed = heap->getHeight() == expected;
   cout << "getHeight() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

bool testGetHeight(ArrayMaxHeap<string>* heap, int expected) {
   bool passed = heap->getHeight() == expected;
   cout << "getHeight() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

bool testPeekTop(ArrayMaxHeap<int>* heap, int topItem, bool expected) {
   bool excepted = false,
        passed;
   try {
      passed = (heap->peekTop() == topItem) == expected;
   } catch (PrecondViolatedExcep exception) {
      excepted = true;
      passed = expected == false;
   }
   cout << "peekTop() test " << (passed ? "passed" : "failed") << (excepted ? " with precondition exception" : "") << endl;
   return passed;
}

bool testPeekTop(ArrayMaxHeap<string>* heap, string topItem, bool expected) {
   bool excepted = false,
        passed;
   try {
      passed = (heap->peekTop() == topItem) == expected;
   } catch (PrecondViolatedExcep exception) {
      excepted = true;
      passed = expected == false;
   }
   cout << "peekTop() test " << (passed ? "passed" : "failed") << (excepted ? " with precondition exception" : "") << endl;
   return passed;
}

bool testAdd(ArrayMaxHeap<int>* heap, int itemToAdd, bool expected) {
   bool passed = heap->add(itemToAdd) == expected;
   cout << "add(" << itemToAdd << ") test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

bool testAdd(ArrayMaxHeap<string>* heap, string itemToAdd, bool expected) {
   bool passed = heap->add(itemToAdd) == expected;
   cout << "add(\"" << itemToAdd << "\") test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

bool testRemove(ArrayMaxHeap<int>* heap, bool expected) {
   bool passed = heap->remove() == expected;
   cout << "remove() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

bool testRemove(ArrayMaxHeap<string>* heap, bool expected) {
   bool passed = heap->remove() == expected;
   cout << "remove() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

bool testClear(ArrayMaxHeap<int>* heap) {
   heap->clear();
   bool passed = !heap->getNumberOfNodes() && heap->isEmpty();
   cout << "clear() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

bool testClear(ArrayMaxHeap<string>* heap) {
   heap->clear();
   bool passed = !heap->getNumberOfNodes() && heap->isEmpty();
   cout << "clear() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}


int main()
{
   const int NUM_TESTS = 26,
             MAX_INT = 10001,
             HEAP_CAPACITY = 10,
             MIN_HEIGHT = ceil(log2(HEAP_CAPACITY+1)),
             ANSWER_INT = 42;
   const string MAX_STR = "zzzzzzz",
                ANSWER_STR = to_string(ANSWER_INT);
   int passed = 0;
   
   // ========== Integer max heap test suite ==========

   cout << "Testing integer heap:" << endl;

   ArrayMaxHeap<int>* intHeapPointer = new ArrayMaxHeap<int>();
   addIntegers(intHeapPointer, MAX_INT);

   cout << "\nTesting full integer heap:" << endl;
   passed += testIsEmpty(intHeapPointer, false);
   passed += testGetNumberOfNodes(intHeapPointer, HEAP_CAPACITY);
   passed += testGetHeight(intHeapPointer, MIN_HEIGHT);
   passed += testPeekTop(intHeapPointer, MAX_INT, true);
   passed += testAdd(intHeapPointer, ANSWER_INT, false);
   passed += testRemove(intHeapPointer, true);
   passed += testClear(intHeapPointer);

   cout << "\nTesting empty integer heap:" << endl;
   passed += testIsEmpty(intHeapPointer, true);
   passed += testGetNumberOfNodes(intHeapPointer, 0);
   passed += testGetHeight(intHeapPointer, 0);
   passed += testPeekTop(intHeapPointer, MAX_INT, false);
   passed += testRemove(intHeapPointer, false);
   passed += testAdd(intHeapPointer, ANSWER_INT, true);

   // ========== String max heap test suite ==========

   ArrayMaxHeap<string>* stringHeapPointer = new ArrayMaxHeap<string>(); 
   addStrings(stringHeapPointer, MAX_STR);

   cout << "\nTesting full string heap:" << endl;
   passed += testIsEmpty(stringHeapPointer, false);
   passed += testGetNumberOfNodes(stringHeapPointer, HEAP_CAPACITY);
   passed += testGetHeight(stringHeapPointer, MIN_HEIGHT);
   passed += testPeekTop(stringHeapPointer, MAX_STR, true);
   passed += testAdd(stringHeapPointer, ANSWER_STR, false);
   passed += testRemove(stringHeapPointer, true);
   passed += testClear(stringHeapPointer);

   cout << "\nTesting empty string heap:" << endl;
   passed += testIsEmpty(stringHeapPointer, true);
   passed += testGetNumberOfNodes(stringHeapPointer, 0);
   passed += testGetHeight(stringHeapPointer, 0);
   passed += testPeekTop(stringHeapPointer, MAX_STR, false);
   passed += testRemove(stringHeapPointer, false);
   passed += testAdd(stringHeapPointer, ANSWER_STR, true);

   // ========== Results ==========

   cout << endl << passed << " passed / " << NUM_TESTS - passed << " failed" << endl;

   return 0;
}

// EOF