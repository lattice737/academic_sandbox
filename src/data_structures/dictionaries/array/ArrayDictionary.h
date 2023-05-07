/** An array-based implementation of the ADT dictionary
 that organizes its entries in sorted search-key order.
 Search keys in the dictionary are unique.
 @file ArrayDictionary.h */

#ifndef ARRAY_DICTIONARY_
#define ARRAY_DICTIONARY_

#include "DictionaryInterface.h"
#include "Entry.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcept.h"

template <class KeyType, class ValueType>
class ArrayDictionary : public DictionaryInterface<KeyType, ValueType> {
    private:
        static const int DEFAULT_CAPACITY = 21;
        std::unique_ptr<Entry<KeyType, ValueType>[]> entries;
        int entryCount;
        int maxEntries;
        void destroyDictionary();
        int findEntryIndex(int firstIndex, int lastIndex, const KeyType& searchKey) const;
    public:
        ArrayDictionary();
        ArrayDictionary(int maxNumberOfEntries);
        ArrayDictionary(const ArrayDictionary<KeyType, ValueType>& dictionary);
        virtual ~ArrayDictionary();
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

#include "ArrayDictionary.cpp"
#endif