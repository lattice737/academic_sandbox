/** ADT sorted list using ADT list.
 @file SortedListIsA.h */

#ifndef SORTED_LIST_IS_A
#define SORTED_LIST_IS_A

#include "LinkedList.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class SortedListIsA : public LinkedList<ItemType> {
    public:
        SortedListIsA();
        SortedListIsA(const SortedListIsA<ItemType>& sortedList);
        virtual ~SortedListIsA();
        bool insertSorted(const ItemType& newEntry);
        bool removeSorted(const ItemType& anEntry);
        int getPosition(const ItemType& anEntry) const;
        bool insert(int newPosition, const ItemType& newEntry) override;
        void replace(int position, const ItemType& newEntry) noexcept(false) override;
};

#include "SortedListHasA.h"
#endif