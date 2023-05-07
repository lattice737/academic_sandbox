/** ADT sorted list: Link-based implementation.
 @file LinkedSortedList.h */

#ifndef LINKED_SORTED_LIST_
#define LINKED_SORTED_LIST_

#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class LinkedSortedList : public SortedListInterface {
    private:
        shared_ptr<Node<ItemType>> headPtr;  // Pointer to first node in chain
        int itemCount;

        // Locates the node that is before the node that should or does
        // contain the given entry
        // @param anEntry  The entry to find.
        // @return  Either a pointer to the node before the node that contains
        //  or should contain the given entry, or nullptr if no prior node exists.j
        auto getNodeBefore(const ItemType& anEntry) const;

        // Locates the node at a given position within the chain
        auto getNodeAt(int position) const;

        // Returns a pointer to a copy of the chain to which origChainPtr points.
        auto copyChain(const shared_ptr<Node<ItemType>>& origChainPtr);
    public:
        LinkedSortedList();
        LinkedSortedList(const LinkedSortedList<ItemType>& anotherList);
        virtual ~LinkedSortedList();
        bool insertSorted(const ItemType& newEntry);
        bool removeSorted(const ItemType& anEntry);
        int getPosition(const ItemType& newEntry) const;
        bool isEmpty() const;
        int getLength() const;
        bool remove(int position);
        void clear();
        ItemType getEntry(int position) const noexcept(false);
};

#include "LinkedSortedList.h"
#endif