/** SortedListHasA.cpp */

#include "SortedListHasA.h"

template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA() : listPtr(make_unique<LinkeedList<ItemType>>()) {}

template<class ItemType>
SortedListHasA<ItemType>::SortedListHasA(const SortedListHasA<ItemType>& sortedList) {
    for (int position=1; position <= sortedList.getLength(); position++)
        listPtr->insert(position, sortedList.getEntry(position));
}

template<class ItemType>
SortedListHasA<ItemType>::~SortedListHasA() {
    clear();
}

template<class ItemType>
bool SortedListHasA<ItemType>::insertSorted(const ItemType& newEntry) {
    int newPosition = abs(getPosition(newEntry));
    return listPtr->insert(newPosition, newEntry);
}

// TODO
template<class ItemType>
bool SortedListHasA<ItemType>::removeSorted(const ItemType& newEntry) {}

// O(n^2) with linked list (nested loop)
// TODO
template<class ItemType>
int SortedListHasA<ItemType>::getPosition(const ItemType& newEntry) const {
    // TODO: use getLength() & getEntry()
}

template<class ItemType>
bool SortedListHasA<ItemType>::isEmpty() const {
    return listPtr->itemCount == 0;
}

template<class ItemType>
int SortedListHasA<ItemType>::getLength() const {
    return listPtr->itemCount;
}

template<class ItemType>
bool SortedListHasA<ItemType>::remove(int position) {
    return listPtr->remove(position);
}

template<class ItemType>
void SortedListHasA<ItemType>::clear() {
    while (!isEmpty()) remove(1);
}

template<class ItemType>
ItemType SortedListHasA<ItemType>::getEntry(int position) const noexcept(false) {
    return LinkedList<ItemType>::getEntry(position);
}