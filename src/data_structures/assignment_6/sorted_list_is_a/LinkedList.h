/** ADT list: Link-based implementation.
 @file LinkedList.h */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType> {
    private:
        Node<ItemType>* headPtr;    // Pointer to first node in chain--first list entry
        int itemCount;
        Node<ItemType>* insertNode(int position, Node<ItemType>* newNodePtr, Node<ItemType>* subChainPtr);

        // Locates a specified node in a linked list.
        // @pre  position is the number of the desired node;
        //       position >= 1 and position <= itemCount
        // @post  The node is found and a pointer to it is returned.
        // @param position  The number of the node to locate.
        // @param return  A pointer to the node at the given position.
        Node<ItemType>* getNodeAt(int position) const;  // not an ADT operation
    public:
        LinkedList();
        LinkedList(const LinkedList<ItemType>& anotherList);
        virtual ~LinkedList();
        bool isEmpty() const;
        int getLength() const;
        bool insert(int newPosition, const ItemType& newEntry);
        bool recursiveInsert(int newPosition, const ItemType& newEntry);
        bool remove(int position);
        void clear();

        /** @throw  PrecondViolatedExcept if position < 1 or position > getLength() */
        ItemType getEntry(int position) const noexcept(false);

        /** @throw  PrecondViolatedExcept if position < 1 or position > getLength() */
        ItemType replace(int position, const ItemType& newEntry) noexcept(false);
};

#include "LinkedList.cpp"
#endif