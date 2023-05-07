#include "TreeDictionary.h"

template <class KeyType, class ValueType>
TreeDictionary<KeyType, ValueType>::TreeDictionary() : {}

template <class KeyType, class ValueType>
TreeDictionary<KeyType, ValueType>::TreeDictionary(const TreeDictionary<KeyType, ValueType>& dictionary) {}

template <class KeyType, class ValueType>
TreeDictionary<KeyType, ValueType>::~TreeDictionary() {}

// Private Methods

template <class KeyType, class ValueType>
void TreeDictionary<KeyType, ValueType>::destroyDictionary() {}

template <class KeyType, class ValueType>
int TreeDictionary<KeyType, ValueType>::findEntryIndex(int firstIndex, int lastIndex, const KeyType& searchKey) const {}

// Public Methods

template <class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::isEmpty() const {}

template <class KeyType, class ValueType>
int TreeDictionary<KeyType, ValueType>::getNumberOfEntries() const {}

template <class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::add(const KeyType& searchKey, const ValueType& newValue) {
    Entry<KeyType, ValueType> newEntry(searchKey, newValue);

    if (entryTree.contains(newEntry))
        throw PrecondViolatedExcept("Cannot add an entry whose key does not exist in the dictionary.")

    return entryTree.add(Entry<KeyType, ValueType>(searchKey, newValue));
}

template <class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::remove(const KeyType& searchKey) {
    return entryTree.remove(Entry<KeyType, ValueType>(searchKey, valueType()));
}

template <class KeyType, class ValueType>
void TreeDictionary<KeyType, ValueType>::clear() {}

template <class KeyType, class ValueType>
ValueType TreeDictionary<KeyType, ValueType>::getValue(const KeyType& searchKey) {}

template <class KeyType, class ValueType>
bool TreeDictionary<KeyType, ValueType>::contains(const KeyType& searchKey) const {}