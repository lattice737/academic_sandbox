/* ADT list: link-based implementation.
 @file LinkedList.cpp */

#include <LinkedList.h>
#include <PrecondViolatedExcept.h>
#include <stdexcept>
#include <cassert>
#include <string>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0) {}

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

