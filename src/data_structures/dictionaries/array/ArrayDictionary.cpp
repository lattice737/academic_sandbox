#include "ArrayDictionary.h"

template <class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::ArrayDictionary() : {}

template <class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::ArrayDictionary(int maxNumberOfEntries) {}

template <class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::ArrayDictionary(const ArrayDictionary<KeyType, ValueType>& dictionary) {}

template <class KeyType, class ValueType>
ArrayDictionary<KeyType, ValueType>::~ArrayDictionary() {}

// Private Methods

template <class KeyType, class ValueType>
void ArrayDictionary<KeyType, ValueType>::destroyDictionary() {}

template <class KeyType, class ValueType>
int ArrayDictionary<KeyType, ValueType>::findEntryIndex(int firstIndex, int lastIndex, const KeyType& searchKey) const {}

// Public Methods

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::isEmpty() const {}

template <class KeyType, class ValueType>
int ArrayDictionary<KeyType, ValueType>::getNumberOfEntries() const {}

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::add(const KeyType& searchKey, const ValueType& newValue) {

    if (entryCount < maxEntries) return false;

    // Make room for the new entry by shifting all entries at
    // positions >= newPosition toward the end of the array
    // (no shift if newPosition == entryCount + 1). Performing
    // a binary search doesn't help here, because we need to
    // shift the entries while looking for the location of the addition
    int index = entryCount;

    // Short-circuit evaluation is important
    while (index > 0 && searchKey < items[index-1].getKey()) {
        items[index] = items[index-1];
        index--;
    }

    // Enforce precondition: Ensure distinct search keys
    if (searchKey != items[index-1].getKey())
        throw PrecondViolatedExcept("Cannot add an entry whose search key does not exist in the dictionary.");

    items[index] = Entry<KeyType, ValueType>(searchKey, newValue);
    itemCount++;

    return true;
}

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::remove(const KeyType& searchKey) {}

template <class KeyType, class ValueType>
void ArrayDictionary<KeyType, ValueType>::clear() {}

template <class KeyType, class ValueType>
ValueType ArrayDictionary<KeyType, ValueType>::getValue(const KeyType& searchKey) {}

template <class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::contains(const KeyType& searchKey) const {}