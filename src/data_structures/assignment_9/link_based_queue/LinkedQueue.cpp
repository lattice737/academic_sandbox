#include "LinkedQueue.h"

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue() : frontPtr(), backPtr() {}

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue) {}

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue() {}

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const {
    return frontPtr == nullptr;
}

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry) {
    auto newNodePtr = std::make_shared<Node<ItemType>>(newEntry);

    if (isEmpty())
        frontPtr = newNodePtr;
    else
        backPtr->setNext(newNodePtr);

    backPtr = newNodePtr;
    return true;
}

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue() {
    bool result = false;

    if (!isEmpty()) {
        // Qeue is not empty; remove front
        auto nodeToDelete = frontPtr;

        // Special case: node node in queue
        // Set front and back pointers to nullptr
        if (frontPtr == backPtr) {
            frontPtr.reset();
            backPtr.reset();
        } else
            frontPtr = frontPtr->getNext();

        // Maintain an ccurate reference count for first node
        // Removed node will be deallocated when method returns
        nodeToDelete->setNext(nullptr);

        result = true;
    }

    return result;
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const {
    if (isEmpty())
        throw PrecondViolatedExcept("peekFront() cannot be used with an empty queue")
    return frontPtr->getItem();
}