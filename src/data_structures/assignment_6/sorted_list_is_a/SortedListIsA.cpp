/* @file SortedListIsA.cpp */

#include "SortedListIsA.h"

template<class ItemType>
SortedListIsA<ItemType>::SortedListIsA() {}

template<class ItemType>
SortedListIsA<ItemType>::SortedListIsA(const SortedListIsA<ItemType>& sortedList) : LinkedList<ItemType>(sortedList) {}

template<class ItemType>
SortedListIsA<ItemType>::~SortedListIsA() {}

template<class ItemType>
bool SortedListIsA<ItemType>::insertSorted(const ItemType& newEntry) {
    int newPosition = abs(getPosition(newEntry));
    
    // The LinkedList version of insert is needed, since the
    // SortedListIsA version just returns false
    return LinkedList<ItemType>::insert(newPosition, newEntry);
}

template<class ItemType>
bool SortedListIsA<ItemType>::removeSorted(const ItemType& anEntry) {
    int position = getPosition(anEntry);
    bool ableToRemove = position > 0;

    if (ableToRemove)
        ableToRemove = LinkedList<ItemType>::remove(position);

    return ableToRemove;
}

template<class ItemType>
int SortedListIsA<ItemType>::getPosition(const ItemType& anEntry) const {
    int position = 1;
    int length = LinkedList<ItemType>::getLength();

    while(position <= length && anEntry > LinkedList<ItemType>::getEntry(position))
        position++;

    if (position > length || anEntry != LinkedList<ItemType>::getEntry(position))
        position = -position;

    return position;
}

template<class ItemType>
bool SortedListIsA<ItemType>::insert(int newPosition, const ItemType& newEntry) {
    return false;
}

template<class ItemType>
void SortedListIsA<ItemType>::replace(int newPosition, const ItemType& newEntry) {
    return false;
}