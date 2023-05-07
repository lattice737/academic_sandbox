/** ADT queue: ADT list implementation.
 @file ListQueue.cpp */

#include "ListQueue.h"
#include <memory>

template<class ItemType>
ListQueue<ItemType>::ListQueue() : listPtr(std::make_unique<LinkedList<ItemType>>()) {} // new list instance

template<class ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue& aQueue) : listPtr(aQueue.listPtr) {}

template<class ItemType>
ListQueue<ItemType>::~ListQueue() {}

template<class ItemType>
bool ListQueue<ItemType>::isEmpty() const {
    return listPtr->isEmpty();
}

template<class ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& newEntry) {
    return listPtr->insert(listPtr->getLength()+1, newEntry);
}

template<class ItemType>
bool ListQueue<ItemType>::dequeue() {
    return listPtr->remove(1);
}

template<class ItemType>
ItemType ListQueue<ItemType>::peekFront() const {
    if (isEmpty()) throw PrecondViolatedExcept("peekFront() called with empty queue.");
    return listPtr->getEntry(1);  // Queue is not empty; return first item
}