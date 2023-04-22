/** ADT list implementation
 @file ArrayList.cpp */

#include "ArrayList.h"

template<class ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY) {}

template<class ItemType>
bool ArrayList<ItemType>::isEmpty() const {
    return itemCount == 0;
}

template<class ItemType>
int ArrayList<ItemType>::getLength() const {
    return itemCount;
}

template<class ItemType>
bool ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
    bool ableToInsert = newPosition >= 1 && newPosition <= itemCount+1 && itemCount < maxItems;
    
    if (ableToInsert) {
        // Shift all entries from itemCount down to newPosition
        // (no shift if newPosition == itemCount+1)
        for (int i=itemCount; i >= newPosition; i--) {
            items[i+1] = items[i]
        }

        // Insert new entry
        items[newPosition] = newEntry;
        itemCount++;
    }

    return ableToInsert;
}

template<class ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const noexcept(false) {
    // Enforce precondition
    bool ableToGet = position >= 1 && position <= itemCount;
    if (ableToGet)
        return items[position];
    else {
        string message = "getEntry() called with an empty list or invalid position.";
        throw(PrecondViolatedExcept(message));
    }
}

template<class ItemType>
ItemType ArrayList<ItemType>::replace(int position, const ItemType& newEntry) noexcept(false) {
    // Enforce precondition
    bool ableToSet = position >= 1 && position <= itemCount;
    if (ableToSet) {
        ItemType oldEntry = items[position];
        items[position] = newEntry;
        return oldEntry;
    }
    string message = "replace() called with an empty list or invalid position";
    throw(PrecondViolatedExcept(message));
}

template<class ItemType>
bool ArrayList<ItemType>::remove(int position) {
    bool ableToRemove = position >= 1 && position <= itemCount;
    if (ableToRemove) {
        // Shift all entries after the one at position toward array start
        // to remove entry
        // (no shift if position == itemCount)
        for (int i=position; i<itemCount; i++)
            items[i] = items[i+1];
        itemCount--;
    }
    return ableToRemove;
}

template<class ItemType>
void ArrayList<ItemType>::clear() {itemCount = 0;}