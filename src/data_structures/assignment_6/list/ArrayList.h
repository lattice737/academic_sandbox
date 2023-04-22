/** ADT list: Array-based implementation.
 @file ArrayList.h */

#ifndef ARRAY_LIST_
#define ARRAY_LIST_

#include "ListInterface.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class ArrayList : public ListInterface<ItemType> {
    private:
        static const int DEFAULT_CAPACITY = 100;    // Default list capacity
        ItemType items[DEFAULT_CAPACITY+1];         // Array of list items (ignore items[0])
        int itemCount;                              // Current list count
        int maxItems;                               // Max list capacity
    public:
        ArrayList();
        bool isEmpty() const;
        int getLength() const;
        bool insert(int newPosition, const ItemType& newEntry);
        bool remove(int position);
        void clear();
        ItemType getEntry(int position) const noexcept(false);
        ItemType replace(int position, const ItemType& newEntry) noexcept(false);
};

#include "ArrayList.cpp"
#endif