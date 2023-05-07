/** ADT queue: Circular array-based implementation.
 @file ArrayQueue.h */

#ifndef ARRAY_QUEUE_
#define ARRAY_QUEUE_
#include "QueueInterface.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType> {
    private:
        static const int DEFAULT_CAPACITY = 50;
        ItemType items[DEFAULT_CAPACITY];
        int front;
        int back;
        int count;
    public:
        ArrayQueue();
        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();

        /** @throw  PrecondViolatedExcept if queue is empty. */
        ItemType peekFront() const;
};

#include "ArrayQueue.cpp"
#endif