#include "SortedListPriorityQueue.h"

// TODO
template<class ItemType>
SortedListPriorityQueue<ItemType>::SortedListPriorityQueue() : {}

// TODO
template<class ItemType>
SortedListPriorityQueue<ItemType>::SortedListPriorityQueue(const SortedListPriorityQueue& priorityQueue) {}

// TODO
template<class ItemType>
SortedListPriorityQueue<ItemType>::~SortedListPriorityQueue() {}

// Private Methods

// TODO

// Public Methods

// TODO
template<class ItemType>
bool SortedListPriorityQueue<ItemType>::isEmpty() const {}

template<class ItemType>
bool SortedListPriorityQueue<ItemType>::enqueue(const ItemType& newEntry) {
    return sortedListPtr->insertSorted(newEntry);
}

template<class ItemType>
bool SortedListPriorityQueue<ItemType>::dequeue() {
    return sortedListPtr->removeSorted(sortedListPtr->getLength());
}

// TODO
template<class ItemType>
ItemType SortedListPriorityQueue<ItemType>::peekFront() const {}