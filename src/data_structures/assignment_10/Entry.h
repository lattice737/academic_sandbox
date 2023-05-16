//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** A class of entry objects for an array-based implementation of the ADT dictionary.
    Listing 18-2.
 @file Entry.h */

#ifndef ENTRY_
#define ENTRY_

template <class KeyType, class ItemType>
class Entry
{
private:
   KeyType searchKey;
   ItemType item;
   
protected:
   void setKey(const KeyType& searchKey);
   
public:
   Entry();
   Entry(const KeyType& searchKey, const ItemType& newItem);
   ItemType getItem() const;
   KeyType getKey() const;
   void setItem(const ItemType& newItem);
   bool operator==(const Entry<KeyType, ItemType>& rightHandItem) const;
   bool operator>(const Entry<KeyType, ItemType>& rightHandItem) const;
}; // end Entry

//
//  Entry.cpp

template <class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry()
{ }

template <class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry(const KeyType& itemKey, const ItemType& newItem)
               :searchKey(itemKey), item(newItem)
{ }

template <class KeyType, class ItemType>
ItemType Entry<KeyType, ItemType>::getItem() const
{
   return item;
}


template <class KeyType, class ItemType>
KeyType Entry<KeyType, ItemType>::getKey() const
{
   return searchKey;
}


template <class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setItem(const ItemType& newItem)
{
   item = newItem;
}

template <class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setKey(const KeyType& itemKey)
{
   searchKey = itemKey;
}

template <class KeyType, class ItemType>
bool Entry<KeyType, ItemType>::operator==(const Entry<KeyType, ItemType>& rightHandItem) const
{
   return (searchKey == rightHandItem.getKey());
}  // end operator==


template <class KeyType, class ItemType>
bool Entry<KeyType, ItemType>::operator>(const Entry<KeyType, ItemType>& rightHandItem) const
{
   return (searchKey > rightHandItem.getKey());
}
#endif
