/** A class of entries to add to an array-based implementation of the
 ADT dictionary.
 @file Entry.h */

#ifndef ENTRY_
#define ENTRY_

template<class KeyType, class ValueType>
class Entry {
    private:
        KeyType key;
        ValueType value;
    protected:
        void setKey(const KeyType& searchKey);
    public:
        Entry();
        Entry(const KeyType& searchKey, const ValueType& newValue);
        ValueType getValue() const;
        KeyType getKey() const;
        void setValue(const ValueType& newValue);
        bool operator==(const Entry<KeyType, ValueType>& rightHandValue) const;
        bool operator>(const Entry<KeyType, ValueType>& rightHandValue) const;
};

#endif