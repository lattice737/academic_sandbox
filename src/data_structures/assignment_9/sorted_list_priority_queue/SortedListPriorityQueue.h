/** ADT priority queue: ADT sorted list implementation.
 @file SortedListPriorityQueue.h */

#ifndef PRIORITY_QUEUE_
#define PRIORITY_QUEUE_

#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class SortedListPriorityQueue : public PriorityQueueInterface<ItemType> {
    private:
        std::unique_ptr<LinkedSortedList<ItemType>> sortedListPtr;
    public:
        SortedListPriorityQueue();
        SortedListPriorityQueue(const SortedListPriorityQueue& priorityQueue);
        ~SortedListPriorityQueue();
        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();

        /** @throw  PrecondViolatedExcept if priority queue is empty. */
        ItemType peekFront() const;
};

#include "SortedListPriorityQueue.cpp"
#endif