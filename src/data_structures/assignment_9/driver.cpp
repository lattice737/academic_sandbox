// Programmer:      Nicholas Martinez
// Project number:  9
// Project Desc:    Array-based implementation of heap
// Course:          COSC 2436 PF III Data Structures
// Date:            5/10/23

#include "PrecondViolatedExcep.h"
#include "ArrayMaxHeap.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// *** INCOMPLETE ***
// [x] Implement test suite with two data types (test-driven development)
// [x] Complete ArrayMaxHeap implementation
// [ ] Implement heap sorting (p556 in Notability)


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

template<class ItemType>
void displayArray(ItemType array[], int size) {
   for (int i=0; i<size; i++)
      cout << array[i] << (i < size-1 ? ", " : "");
}

// From textbook
template<class ItemType>
void heapRebuild(ItemType array[], int start, int n) {
   int leftChildIndex,
       rightChildIndex,
       largerChildIndex;

   if (start+1 > n-1) return; // test for leaf condition

   // Find the larger child
   leftChildIndex = 2 * start + 1;
   rightChildIndex = leftChildIndex + 1;
   largerChildIndex = rightChildIndex;

   // Validate larger child
   if (largerChildIndex >= n || array[leftChildIndex] > array[rightChildIndex]) {
      largerChildIndex = leftChildIndex;

      // Transform semiheap rooted at largerChildIndex into a heap
      if (array[start] < array[largerChildIndex]) {
         swap(array[start], array[largerChildIndex]);
         heapRebuild(array, largerChildIndex, n-1);
      }
   }
}

// From textbook
template<class ItemType>
void heapSort(ItemType array[], int n) {
   int heapSize;

   // Build proper heap
   for (int i=n/2-1; i>=0; i--)
      heapRebuild(array, i, n);
   
   swap(array[0], array[n-1]);
   heapSize = n-1;

   while (heapSize > 1) {
      // Make the heap region a heap again
      heapRebuild(array, 0, heapSize);

      // Swap the root and adjust region sizes
      swap(array[0], array[heapSize-1]);
      heapSize--;
   }

   displayArray(array, n);
}

// From assignment
template<class ItemType>
void sortHeap(ItemType array[], int n) {
   ArrayMaxHeap<ItemType>* stringHeapPointer = new ArrayMaxHeap<ItemType>(array, n);
   
   cout << "Sorting array: ";
   displayArray(array, n);

   for (int i=n-1; i>=0; i--) {
      array[i] = stringHeapPointer->peekTop();
      stringHeapPointer->remove();
   }

   cout << "\nSorted array: ";
   displayArray(array, n);
}

template<class ItemType>
bool testIsEmpty(ArrayMaxHeap<ItemType>* heap, bool expected) {
   bool passed = heap->isEmpty() == expected;
   cout << "isEmpty() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

template<class ItemType>
bool testGetNumberOfNodes(ArrayMaxHeap<ItemType>* heap, int expected) {
   bool passed = heap->getNumberOfNodes() == expected;
   cout << "getNumberOfNodes() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

template<class ItemType>
bool testGetHeight(ArrayMaxHeap<ItemType>* heap, int expected) {
   bool passed = heap->getHeight() == expected;
   cout << "getHeight() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

template<class ItemType>
bool testPeekTop(ArrayMaxHeap<ItemType>* heap, ItemType topItem, bool expected) {
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

template<class ItemType>
bool testAdd(ArrayMaxHeap<ItemType>* heap, ItemType itemToAdd, bool expected) {
   bool passed = heap->add(itemToAdd) == expected;
   cout << "add(" << itemToAdd << ") test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

template<class ItemType>
bool testRemove(ArrayMaxHeap<ItemType>* heap, bool expected) {
   bool passed = heap->remove() == expected;
   cout << "remove() test " << (passed ? "passed" : "failed") << endl;
   return passed;
}

template<class ItemType>
bool testClear(ArrayMaxHeap<ItemType>* heap) {
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

   const int N = 10;
   int integers[N] = {10, 2, 4, 7, 8, 3, 9, 1, 6, 5};
   string strings[N] = {"foxtrot", "zulu", "charlie", "tango", "echo", "india", "kilo", "whiskey", "november", "juliett"};
   
   // FIXME Yikes
   cout << "\nSorting array: ";
   displayArray(integers, N);
   cout << endl;
   heapSort(integers, N);

   // FIXME So close! Implementation either:
   // a) plays more nicely with strings than ints
   // b) is more closely mapped to the string array (pre-sorting)
   cout << "\nSorting array: ";
   displayArray(strings, N);
   cout << endl;
   heapSort(strings, N);

   return 0;
}

// EOF