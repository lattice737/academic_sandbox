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

// TODO
template<class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList() {}

template<class ItemType>
auto LinkedSortedList<ItemType>::copyChain(const shared_ptr<Node<ItemType>>& origChainPtr) {
    shared_ptr<Node<ItemType>> copiedChainPtr;

    if (origChainPtr != nullptr) {
        // Build new chain from given one; create new node with the current item
        copiedChainPtr = make_shared<Node<ItemType>>(origChainPtr->getItem());
        // Make the node point to the rest of the chain
        copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
    }
    
    return copiedChainPtr
}

// TODO
template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeAt(int position) const {}

template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const {
    auto currentPtr = headPtr;
    shared_ptr<Node<ItemType>> previousPtr;

    while (currentPtr != nullptr && anEntry > currentPtr->getItem()) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->getNext();
    }
    
    return previousPtr;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry) {
    auto newNodePtr(make_shared<Node<ItemType>>(newEntry));
    auto previousPtr = getNodeBefore(newEntry);

    if (isEmpty() || previousPtr == nullptr) {
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;
    } else {
        auto followingPtr = previousPtr->getNext();
        newNodePtr->setNext(followingPtr);
        previousPtr->setNext(newNodePtr);
    }

    itemCount++;
    return true;
}

// TODO
template<class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry) {}

// TODO
template<class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& newEntry) const {}

template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const {
    return itemCount;
}

// TODO
template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position) {}

template<class ItemType>
void LinkedSortedList<ItemType>::clear() {
    while (!isEmpty()) remove(1);
}