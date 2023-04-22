/** @file LinkedStack.cpp */

#include <cassert>
#include <stdexcept>
#include "LinkedStack.h"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr) {}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& anotherStack) {
    Node<ItemType>* origChainPtr = anotherStack.topPtr;

    if (origChainPtr == nullptr)
        topPtr = nullptr;
    else {
        // Copy first node
        topPtr = new Node<ItemType>();
        topPtr->setItem(origChainPtr->getItem());

        // Point to first node in new chain
        Node<ItemTyep>* newChainPtr = topPtr;

        // Advance original chain's pointer
        origChainPtr = origChainPtr->getNext();

        // Copy remaining nodes
        while (origChainPtr != nullptr) {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            Node<ItemType>* newNodePtr = newNode<ItemType>(nextItem);

            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);

            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();

            // Advance original chain's pointer
            origChainPtr = origChainPtr->getNext();
        }

        newChainPtr->setNext(nullptr);
    }
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack() {
    // Pop until stack is empty
    while (!isEmpty())
        pop();
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem) noexcept(false) {
    // TODO: implement memory allocation exception throwing
    Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;
    return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop() {
    bool result = false;
    
    if (!isEmpty()) {
        // Stack is not empty; delete top
        Node<ItemType>* nodeToDeletePtr = topPtr;
        topPtr = topPtr->getNext();

        // Return deleted node to system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        result = true;
    }

    return result;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const noexcept(false) {
    // Enforce precondition
    if (isEmpty())
        throw PrecondViolatedExcept("peek() called with empty stack");
    else  // Stack is not empty; return to top
        return topPtr->getItem();
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const {
    return topPtr == nullptr;
}