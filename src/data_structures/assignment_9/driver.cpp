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

void addIntegers(ArrayMaxHeap<int>* heap, int n, int maxInt) {
   for (int i=0; i<n-1; i++)
      heap->add(rand() % maxInt-1);
   heap->add(maxInt);
}

void addStrings(ArrayMaxHeap<string>* heap, string maxString) {
   string greeks[] = {"gamma", "sigma", "alpha", "epsilon", "pi", "rho", "beta", "phi", "zeta"};
   for (string greek : greeks)
      heap->add(greek);
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
   bool excepted = false,
        passed;
   try {
      passed = heap->peekTop() == expected;
   } catch (PrecondViolatedExcep exception) {
      excepted = true;
      passed = false;
   }
   cout << "peekTop() test " << (passed ? "passed" : "failed") << (excepted ? " with precondition exception" : "") << endl;
   return passed;
}

bool testPeekTop(ArrayMaxHeap<string>* heap, string expected) {
   bool excepted = false,
        passed;
   try {
      passed = heap->peekTop() == expected;
   } catch (PrecondViolatedExcep exception) {
      excepted = true;
      passed = false;
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
   const string MAX_STR = "zzzzzzz";
   const int NUM_TESTS = 26,
             MAX_INT = 10001;
   int passed = 0;

   // Max heap test suite
   // 1) testIsEmpty()
   // 2) testGetNumberOfNodes()
   // 3) testGetHeight()
   // 4) testPeekTop()
   // 5) testAdd()
   // 6) testRemove()
   // 7) testClear()
   // 8) testIsEmpty()
   // 9) testGetNumberOfNodes()
   // 10) testGetHeight()
   // 11) testRemove()
   // 12) testPeekTop() -> exception
   // 13) testAdd()

   cout << "Testing integer heap:" << endl;

   ArrayMaxHeap<int>* intHeapPointer = new ArrayMaxHeap<int>();
   addIntegers(intHeapPointer, 10, MAX_INT);

   passed += testIsEmpty(intHeapPointer, false);
   passed += testGetNumberOfNodes(intHeapPointer, 6);
   passed += testGetHeight(intHeapPointer, 3);  // FIXME add expected height
   passed += testPeekTop(intHeapPointer, MAX_INT);   // FIXME add expected top int
   passed += testAdd(intHeapPointer, 42, false);
   passed += testRemove(intHeapPointer, true);
   passed += testClear(intHeapPointer);
   passed += testIsEmpty(intHeapPointer, true);
   passed += testGetNumberOfNodes(intHeapPointer, 0);
   passed += testGetHeight(intHeapPointer, 0);
   passed += testPeekTop(intHeapPointer, MAX_INT);
   passed += testRemove(intHeapPointer, false);
   passed += testAdd(intHeapPointer, 42, true);

   // String max heap test suite

   cout << "\nTesting string heap:" << endl;

   ArrayMaxHeap<string>* stringHeapPointer = new ArrayMaxHeap<string>(); 
   addStrings(stringHeapPointer, MAX_STR);

   passed += testIsEmpty(stringHeapPointer, false);
   passed += testGetNumberOfNodes(stringHeapPointer, 6);
   passed += testGetHeight(stringHeapPointer, 3);
   passed += testPeekTop(stringHeapPointer, MAX_STR);
   passed += testAdd(stringHeapPointer, "delta", false);
   passed += testRemove(stringHeapPointer, true);
   passed += testClear(stringHeapPointer);
   passed += testIsEmpty(stringHeapPointer, true);
   passed += testGetNumberOfNodes(stringHeapPointer, 0);
   passed += testGetHeight(stringHeapPointer, 0);
   passed += testPeekTop(stringHeapPointer, NULL);
   passed += testRemove(stringHeapPointer, false);
   passed += testAdd(stringHeapPointer, "delta", true);

   // Results

   cout << endl << (passed == NUM_TESTS ? "All" : passed+"/"+NUM_TESTS) << " tests passed";

   return 0;
}  // end main
