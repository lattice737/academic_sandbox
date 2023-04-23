/* ADT list: link-based implementation.
 @file LinkedList.cpp */

#include "LinkedList.h"
#include <stdexcept>
#include <cassert>
#include <string>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0) {}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& anotherList) {
    Node<ItemType>* origChainPtr = anotherList.headPtr;

    // TODO implement exception throwing

    if (origChainPtr == nullptr)
        headPtr = nullptr;
    else {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        // Point to first node in new chain
        Node<ItemType>* newChainPtr = headPtr;

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
LinkedList<ItemType>::~LinkedList() {
    clear();
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const noexcept(false) {
    bool ableToGet = position >= 1 && position <= itemCount;
    
    // Enforce precondition
    if (ableToGet) {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    } else {
        string message = "getEntry() called with an empty list or invalid position.";
        throw(PrecondViolatedExcept(message));
    }
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    return headPtr == nullptr;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const {
    return itemCount;
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const {
    // Debugging precondition check
    assert(position >=1 && position <= itemCount);

    // Count from the start of the chain
    Node<ItemType>* currentPtr = headPtr;
    for (int skip=1; skip<position; skip++)
        currentPtr = currentPtr->getNext();

    return currentPtr;
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::insertNode(int position, Node<ItemType>* newNodePtr, Node<ItemType>* subChainPtr) {
    if (position == 1) {
        // Insert new node at subchain start
        newNodePtr->setNext(subChainPtr)
        subChainPtr = newNodePtr;
        itemCount++;
    } else {
        Node<ItemType>* afterPtr = insertNode(position-1, newNodePtr, subChainPtr->getNext());
        subChainPtr->setNext(afterPtr);
    }
    return subChainPtr;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
    bool ableToInsert = newPosition >= 1 && newPosition <= itemCount+1;

    if (ableToInsert) {
        // Create a new node containing the new entry
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

        // Attach new node to chain
        if (newPosition == 1) {
            // Insert new node at the start of the chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        } else {
            // Find node that will be before new node
            Node<ItemType>* previousPtr = getNodeAt(newPosition-1);

            // Insert new node after node to which previousPtr points
            newNodePtr->setNext(previousPtr->getNext());
            previousPtr->setNext(newNodePtr);
        }

        itemCount++;
    }

    return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::recursiveInsert(int newPosition, const ItemType& newEntry) {
    bool ableToInsert = newPosition >= 1 && newPosition <= itemCount+1;

    if (ableToInsert) {
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        headPtr = insertNode(newPosition, newNodePtr, headPtr);
    }

    return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position) {
    bool ableToRemove = position >= 1 && position <= itemCount;

    if (ableToRemove) {
        Node<ItemType>* currentPtr = nullptr;
        
        if (position == 1) {
            //Remove the first node in the chain
            currentPtr = headPtr;  // Save pointer to node
            headPtr = headPtr->getNext();
        } else {
            //Find node before the one to remove
            Node<ItemType>* previousPtr = getNodeAt(position-1);
            
            // Point to node to remove
            currentPtr = previousPtr->getNext();

            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            previousPtr->setNext(currentPtr->getNext());
        }

        // Return node to system
        currentPtr->setNext(nullptr);
        delete currentPtr;
        currentPtr = nullptr;

        itemCount--;
    }

    return ableToRemove;
}

template<class ItemType>
void LinkedList<ItemType>::clear() {
    while (!isEmpty()) remove(1);
}

// TODO
template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry) noexcept(false) {
    // TODO: see ch 4
}