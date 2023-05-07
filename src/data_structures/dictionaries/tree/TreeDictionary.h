/** A binary search tree implementation of the ADT dictionary
 that organizes its data in sorted search-key order.
 Search keys in the dictionary are unique.
 @file TreeDictionary.h */

#ifndef TREE_DICTIONARY_
#define TREE_DICTIONARY_

#include "DictionaryInterface.h"
#include "BinarySearchTree.h"
#include "Entry.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"

template <class KeyType, class ValueType>
class TreeDictionary : public DictionaryInterface<KeyType, ValueType> {
    private:
        BinarySearchTree<Entry<KeyType, ValueType>> entryTree;
    public:
        TreeDictionary();
        TreeDictionary(const TreeDictionary<KeyType, ValueType>& dictionary);
        virtual ~TreeDictionary();
        bool isEmpty() const;
        int getNumberOfEntries() const;
        bool add(const KeyType& searchKey, const ValueType& newValue);
        bool remove(const KeyType& searchKey);
        void clear();
        ValueType getValue(const KeyType& searchKey);
        bool contains(const KeyType& searchKey) const;

        /** Traverses the entries in this dictionary in sorted search-key order
            and calls a given client function once for the value in each entry. */
        void traverse(void visit(ValueType&)) const;
};

#include "TreeDictionary.cpp"
#endif