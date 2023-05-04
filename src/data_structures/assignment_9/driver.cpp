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

void displayArray(int array[], int size) {
   for (int i=0; i<size; i++)
      cout << array[i] << (i < size-1 ? ", " : "");
}

void displayArray(string array[], int size) {
   for (int i=0; i<size; i++)
      cout << array[i] << (i < size-1 ? ", " : "");
}

template<class ItemType>
void heapRebuild(int start, ItemType array[], int size) {
   // TODO ???
}

void sortIntegerHeap() {
   const int N = 10;
   int integers[N] = {10, 2, 4, 7, 8, 3, 9, 1, 6, 5};
   ArrayMaxHeap<int>* intHeapPointer = new ArrayMaxHeap<int>(integers, N);

   cout << "\nSorting array: ";
   displayArray(integers, N);
   
   // TODO implement sort

   cout << "\nSorted array: ";
   displayArray(integers, N);
}

void sortStringHeap() {
   const int N = 10;
   string strings[N] = {"foxtrot", "zulu", "charlie", "tango", "echo", "india", "kilo", "whiskey", "november", "juliett"};
   ArrayMaxHeap<string>* stringHeapPointer = new ArrayMaxHeap<string>(strings, N);
   
   cout << "Sorting array: ";
   displayArray(strings, N);

   // TODO implement sort

   cout << "\nSorted array: ";
   displayArray(strings, N);
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

   // ========== Test suite results ==========

   cout << endl << passed << " passed / " << NUM_TESTS - passed << " failed" << endl;

   // ========== Sorting ==========

   sortIntegerHeap();
   cout << endl << endl;
   sortStringHeap();

   return 0;
}

// EOF