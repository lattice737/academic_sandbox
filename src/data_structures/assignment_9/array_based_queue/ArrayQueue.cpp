/** ADT queue: Circular array-based implementation.
 @file ArrayQueue.cpp */

#include "ArrayQueue.h"

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(0), back(DEFAULT_CAPACITY-1), count(0) {}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const {
    return count == 0;
}

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry) {

    if (count >= DEFAULT_CAPACITY) return false;

    back = (back+1) % DEFAULT_CAPACITY;
    items[back] = newEntry;
    count++;
    
    return true;
}

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue() {
    
    if (isEmpty()) return false;

    front = (front+1) % DEFAULT_CAPACITY;
    count--;

    return true;
}

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const {
    if (isEmpty())
        throw PrecondViolatedExcept("peekFront() called with an empty queue");
    return items[front];
}