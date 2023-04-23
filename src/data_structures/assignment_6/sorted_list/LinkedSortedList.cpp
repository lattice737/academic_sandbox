/** Link-based implementation
 @file LinkedSortedList.cpp */

#include "LinkedSortedList.h"

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : headPtr(nullptr), itemCount(0) {}

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& anotherList) {
    headPtr = copyChain(anotherList.headPtr);
    itemCount = anotherlist.itemCount;
}

