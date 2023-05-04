// Programmer:      Nicholas Martinez
// Project number:  9
// Project Desc:    Array-based implementation of heap
// Course:          COSC 2436 PF III Data Structures
// Date:            5//23

#include "PrecondViolatedExcep.h"
#include "ArrayMaxHeap.h"
#include <iostream>
#include <string>

using namespace std;

// [x] Implement test suite with two data types (test-driven development)
// [ ] Complete ArrayMaxHeap implementation
// [ ] Implement heap sorting:
//     1) Use the explicit-value constructor to copy the contents of the array into a max heap
//     2) Remove the largest value from the max heap and insert in the array at the last position
//     3) Keep removing the next largest value from the array and place it in the array at progressively lower positions until the max heap is empty

void addIntegers(ArrayMaxHeap<int>* heap, int n) {
   for (int i=0; i<n; i++)
      heap->add(rand() % 10000);
}

void addStrings(ArrayMaxHeap<string>* heap) {
   string greeks[] = {"gamma", "sigma", "alpha", "epsilon", "pi", "phi"};
   for (string greek : greeks)
      heap->add(greek);
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
   cout << "getNumberOfNodes() test " << (passed ? "passed" : "failed");
   return passed;
}

bool testGetNumberOfNodes(ArrayMaxHeap<string>* heap, int expected) {
   bool passed = heap->getNumberOfNodes() == expected;
   cout << "getNumberOfNodes() test " << (passed ? "passed" : "failed");
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

bool testPeekTop(ArrayMaxHeap<int>* heap, int expected) {
   bool passed = heap->peekTop() == expected;
   cout << "peekTop() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

bool testPeekTop(ArrayMaxHeap<string>* heap, string expected) {
   bool passed = heap->peekTop() == expected;
   cout << "peekTop() test " << (passed ? "passed" : "failed") << endl;
}

bool testAdd(ArrayMaxHeap<int>* heap, int itemToAdd, bool expected) {
   bool excepted = false,
        passed;
   try {
      passed = heap->add(itemToAdd) == expected;
   } catch (PrecondViolatedExcep exception) {
      excepted = true;
      passed = false;
   }
   cout << "add(" << itemToAdd << ") test " << (passed ? "passed" : "failed") << (excepted ? " with exception" : "") << endl;
   return passed;
}

bool testAdd(ArrayMaxHeap<string>* heap, string itemToAdd, bool expected) {
   bool excepted = false,
        passed;
   try {
      passed = heap->add(itemToAdd) == expected;
   } catch (PrecondViolatedExcep exception) {
      excepted = true;
      passed = false;
   }
   cout << "add(\"" << itemToAdd << "\") test " << (passed ? "passed" : "failed") << (excepted ? " with exception" : "") << endl;
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
   const int NUM_TESTS = 14;
   int passed = 0;

   // TODO pseudocode test cases
   // Integer max heap test suite

   ArrayMaxHeap<int>* intHeapPointer = new ArrayMaxHeap<int>();
   addIntegers(intHeapPointer, 10);

   passed += testIsEmpty(intHeapPointer, false);
   passed += testGetNumberOfNodes(intHeapPointer, 6);
   passed += testGetHeight(intHeapPointer, -1);  // FIXME add expected height
   passed += testPeekTop(intHeapPointer, -1);    // FIXME add expected top int
   passed += testAdd(intHeapPointer, 42, true);
   passed += testRemove(intHeapPointer, false);
   passed += testClear(intHeapPointer);

   // String max heap test suite

   ArrayMaxHeap<string>* stringHeapPointer = new ArrayMaxHeap<string>(); 
   addStrings(stringHeapPointer);

   passed += testIsEmpty(stringHeapPointer, false);
   passed += testAdd(stringHeapPointer, "delta", true);
   passed += testRemove(stringHeapPointer, false);
   passed += testGetNumberOfNodes(stringHeapPointer, 6);
   passed += testGetHeight(stringHeapPointer, -1);  // FIXME add expected height
   passed += testPeekTop(stringHeapPointer, "");    // FIXME add expected top int
   passed += testClear(stringHeapPointer);

   // Results

   cout << endl << (passed == NUM_TESTS ? "All" : passed+"/"+NUM_TESTS) << " tests passed";

   return 0;
}  // end main
