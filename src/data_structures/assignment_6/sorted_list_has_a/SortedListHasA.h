/** ADT sorted list using the ADT list.
 @file SortedListHasA.h */

#ifndef SORTED_LIST_HAS_A_
#define SORTED_LIST_HAS_A_

#include "SortedListInterface.h"
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class SortedListHasA : public SortedListInterface<ItemType>, private LinkedList<ItemType> {
    private:
        unique_ptr<ListInterface<ItemType>> listPtr;
    public:
        SortedListHasA();
        SortedListHasA(const SortedListHasA<ItemType>& sortedList);
        virtual ~SortedListHasA();
        bool insertSorted(const ItemType& newEntry);
        bool removeSorted(const ItemType& newEntry);
        int getPosition(const ItemType& newEntry) const;
        bool isEmpty() const;
        int getLength() const;
        bool remove(int position);
        void clear();
        ItemType getEntry(int position) const noexcept(false);
};

#include "SortedListHasA.cpp"
#endif