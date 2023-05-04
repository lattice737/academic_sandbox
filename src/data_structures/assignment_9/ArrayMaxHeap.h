//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.

/** Array-based implementation of the ADT heap.
 Listing 17-2.
 @file ArrayMaxHeap.h */ 
 
#ifndef ARRAY_MAX_HEAP_
#define ARRAY_MAX_HEAP_

#include "HeapInterface.h"
#include "PrecondViolatedExcep.h"

using namespace std;

template<class ItemType>
class ArrayMaxHeap : public HeapInterface<ItemType>
{
private:
   static const int ROOT_INDEX = 0;        // Helps with readability
   static const int DEFAULT_CAPACITY = 10; // Small capacity to test for a full heap
   ItemType *items;                        // Array of heap items
   int itemCount;                          // Current count of heap items
   int maxItems;                           // Maximum capacity of the heap
   
   // ---------------------------------------------------------------------
   // Most of the private utility methods use an array index as a parameter
   // and in calculations. This should be safe, even though the array is an
   // implementation detail, since the methods are private.
   // ---------------------------------------------------------------------
   
   // Returns the array index of the left child (if it exists).
   int getLeftChildIndex(const int nodeIndex) const;
   
   // Returns the array index of the right child (if it exists).
   int getRightChildIndex(int nodeIndex) const;
   
   // Returns the array index of the parent node.
   int getParentIndex(int nodeIndex) const;
   
   // Tests whether this node is a leaf.
   bool isLeaf(int nodeIndex) const;
   
   // Converts a semiheap to a heap.
   void heapRebuild(int subTreeRootIndex);
   
   // Creates a heap from an unordered array.
   void heapCreate();
     
public:
   ArrayMaxHeap();
   ArrayMaxHeap(const ItemType someArray[], const int arraySize);
   virtual ~ArrayMaxHeap();
   bool isEmpty() const;
   int getNumberOfNodes() const;
   int getHeight() const;
   ItemType peekTop() const;
   bool add(const ItemType& newData);
   bool remove();
   void clear();
}; // end ArrayMaxHeap

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Array-based implementation of the ADT heap.
 @file ArrayMaxHeap.cpp */ 
 
#include <cmath> // for log2
#include <algorithm>  // for swap
#include "PrecondViolatedExcep.h"

//******************************************************************
// Private methods
//******************************************************************

template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
   return (2 * nodeIndex) + 1;
}  // end getLeftChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(int nodeIndex) const {
   return (2 * nodeIndex) + 2;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(int nodeIndex) const {
   return (nodeIndex - 1) / 2;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const {
   return getLeftChildIndex(nodeIndex) > itemCount-1;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex) {
   int leftChildIndex,
       rightChildIndex,
       largerChildIndex;

   if (isLeaf(ROOT_INDEX)) return;

   // Find the larger child
   leftChildIndex = 2 * subTreeRootIndex + 1;
   rightChildIndex = leftChildIndex + 1;
   largerChildIndex = rightChildIndex;

   // Validate larger child
   if (largerChildIndex >= itemCount || items[leftChildIndex] > items[rightChildIndex]) {
      largerChildIndex = leftChildIndex;

      // Transform semiheap rooted at largerChildIndex into a heap
      if (items[subTreeRootIndex] < items[largerChildIndex]) {
         swap(items[subTreeRootIndex], items[largerChildIndex]);
         heapRebuild(largerChildIndex);
      }
   }
}

// TODO ready for testing
// Add implementation for heapCreate
// See page 527 in the Carrano textbook
template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate() {
   for (int i=(itemCount/2-1); i>=0; i--) {
      // TODO Assert that tree rooted at i is a semiheap
      heapRebuild(i);
   }
}

//******************************************************************
// Public methods
//******************************************************************

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap() : itemCount(0), maxItems(DEFAULT_CAPACITY) {
   items = new ItemType[DEFAULT_CAPACITY];
}

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize) : itemCount(arraySize), maxItems(2 * arraySize)
{
   // Allocate the array
   items = new ItemType[2 * arraySize];

   // Copy given values into the array
   for (int i = 0; i < itemCount; i++)
      items[i] = someArray[i];
   
   // Reorganize the array into a heap
   heapCreate();
} // end constructor

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{  
   delete [] items;
}  // end destructor

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const {
   return itemCount == 0;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
   return ceil(log2(itemCount + 1));
}  // end getHeight

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const {
   return itemCount;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear() {
   itemCount = 0;
}

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const
{
   if (isEmpty())
      throw PrecondViolatedExcep("Attempted peek into an empty heap.");
   
   return items[0];
} // end peekTop

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData) {
   int newDataIndex = itemCount,
       parentIndex;
   bool inPlace = false;

   if (itemCount == maxItems) return false;

   items[itemCount] = newData;

   while (newDataIndex >= 0 and !inPlace) {
      parentIndex = (newDataIndex - 1) / 2;
      
      if (items[newDataIndex] <= items[parentIndex])
         inPlace = true;
      else {
         swap(items[newDataIndex], items[parentIndex]);
         newDataIndex = parentIndex;
      }
   }

   itemCount++;
   
   return inPlace;
} 

template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove() {
   
   if (isEmpty()) return false;
   
   items[ROOT_INDEX] = items[itemCount - 1];
   itemCount--;
   
   // TODO Assert that tree rooted at ROOT_INDEX is a semiheap
   heapRebuild(ROOT_INDEX);
   
   return true;
}

#endif