//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file  HashedDictionary.h */

#ifndef HASHED_DICTIONARY_
#define HASHED_DICTIONARY_

#include "DictionaryInterface.h"
#include "HashedEntry.h"
#include "NotFoundException.h"
#include <memory>

template <class KeyType, class ItemType>
class HashedDictionary : public DictionaryInterface<KeyType, ItemType>
{
private:
   // creates a unique pointer to an array of shared HashedEntry pointers
   static const int DEFAULT_CAPACITY = 17;
   HashedEntry<KeyType, ItemType> * hashTable[DEFAULT_CAPACITY];  // Array of pointers to entries
   int itemCount;                               // Count of dictionary entries
   int hashTableSize;                           // Table size must be prime
   
   void destroyDictionary();   
   int getHashIndex(const KeyType& itemKey) const;   
   int getNextPrime(int number) const;
   bool isPrime(int number) const;
   
public:   
   HashedDictionary();
   HashedDictionary(const HashedDictionary<KeyType, ItemType>& dict);
   
   virtual ~HashedDictionary();
   
   bool isEmpty() const;   
   int getNumberOfItems() const;   
   void clear();   
   bool add(const KeyType& itemKey, const ItemType& newItem);   
   bool remove(const KeyType& itemKey);
   ItemType getItem(const KeyType& itemKey) const  throw (NotFoundException);   
   bool contains(const KeyType& itemKey) const;   
   void traverse(void visit(ItemType&)) const;  
}; // end HashedDictionary

/** @file  HashedDictionary.cpp */

#include <cmath>    // For sqrt
#include <iostream> // For testing
#include <unordered_map>

//////////////////////////////////////////////////////////////////////
// Private helper methods
//////////////////////////////////////////////////////////////////////

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::destroyDictionary()
{
   HashedEntry<KeyType, ItemType> *deletePtr;	
   for (int i = 0; i < hashTableSize; i++)
   {
      // If there are hashed entries at this location,
      // we need to delete them
      while (hashTable[i] != nullptr)
      {
         deletePtr = hashTable[i];
		 hashTable[i] = hashTable[i]->getNext();
		 delete deletePtr;
		 deletePtr = nullptr;
      }  // end while
   }  // end for
   
   itemCount = 0;
}  // end destroyDictionary

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& key) const
{
   // We are creating a hash function type called hashFunction that hashes "KeyType"
   // First we create an an unordered_map object for our KeyType and ItemType
   std::unordered_map<KeyType, ItemType> mapper;
   
   // Then we call the hash_function method to return the hash function
   // for the KeyType and assign it to 'hashFunction'
   typename std::unordered_map<KeyType, ItemType>::hasher hashFunction = mapper.hash_function();
   
   // static_cast needed since hashFunction returns an unsigned long
   return static_cast<int>(hashFunction(key) % hashTableSize);
} // end getHashIndex


//////////////////////////////////////////////////////////////////////
// Constructors & Destructor
//////////////////////////////////////////////////////////////////////

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
:itemCount(0), hashTableSize(DEFAULT_CAPACITY)
{
	for (int i=0; i<DEFAULT_CAPACITY; i++ )
		hashTable[i] = nullptr;
}  // end

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary(const
                                                    HashedDictionary<KeyType, ItemType>& dict)
                  :itemCount(dict.itemCount),  hashTableSize(dict.hashTableSize)
{
   for (auto index : indices(dict.itemCount))
   {
      hashTable[index] = dict.hashTable[index];
   }  // end for
}  // end 

template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary()
{
   destroyDictionary();
} // end destructor

////////////////////////////////////////////////////////////////////
// Status and public maintenance (clear) methods
//////////////////////////////////////////////////////////////////////

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const
{
   return (itemCount == 0);
} // end isEmpty

template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const
{
   return itemCount;
} // end getNumberOfItems

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear()
{
   destroyDictionary();
} // end clear

///////////////////////////////////////////////////////////////////
// Container methods (add, remove, getItem, contains, traverse)
//////////////////////////////////////////////////////////////////////

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem)
{
   // Create entry to add to dictionary
   HashedEntry<KeyType, ItemType> * entryToAddPtr = new HashedEntry<KeyType, ItemType>(searchKey, newItem);
   
   // Compute the hashed index into the array
   int itemHashIndex = getHashIndex(searchKey);

   // Add the entry to the chain at itemHashIndex
   if (hashTable[itemHashIndex] == nullptr)
   {
	  hashTable[itemHashIndex] = entryToAddPtr;
   }
   else
   {
      entryToAddPtr->setNext(hashTable[itemHashIndex]);
      hashTable[itemHashIndex] = entryToAddPtr;
   } // end if
   
   return true;
} // end add

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType& searchKey)
{
   bool itemFound = false;
   
   // Compute the hashed index into the array
   int itemHashIndex = getHashIndex(searchKey);
   if (hashTable[itemHashIndex] != nullptr)
   {
      // Special case - first node has target
      if (searchKey == hashTable[itemHashIndex]->getKey())
      {
         HashedEntry<KeyType, ItemType> *deletePtr = hashTable[itemHashIndex];
		 hashTable[itemHashIndex] = hashTable[itemHashIndex]->getNext();
		 delete deletePtr;
		 deletePtr = nullptr;
         itemFound = true;
      }
      else // Search the rest of the chain
      {
         HashedEntry<KeyType, ItemType> * prevPtr = hashTable[itemHashIndex];
         HashedEntry<KeyType, ItemType> * curPtr = prevPtr->getNext();
         while ((curPtr != nullptr) && !itemFound )
         {
            // Found item in chain so remove that node
            if (searchKey == curPtr->getKey())
            {
               prevPtr->setNext(curPtr->getNext());
               delete curPtr;
               itemFound = true;
            }
            else // Look at next entry in chain
            {
               prevPtr = curPtr;
               curPtr = curPtr->getNext();
            } // end if
         } // end while
      } // end if
   } // end if
   
   return itemFound;
} // end remove

template <class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const
                                              noexcept(false)
{
   // Compute the hashed index into the array
   int itemHashIndex = getHashIndex(searchKey);
   HashedEntry<KeyType, ItemType> * chainPtr = hashTable[itemHashIndex];
   
   // Short circuit evaluation is important here
   while ((chainPtr != nullptr) && (searchKey != chainPtr->getKey()))
   {
      chainPtr = chainPtr->getNext();
   } // end while 
   
   if (chainPtr == nullptr)
      throw NotFoundException("\n\nItem not found in Dictionary!\n\n");
   
   return chainPtr->getItem();
} // end getItem

template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType& searchKey) const
{
   // Compute the hashed index into the array
   int itemHashIndex = getHashIndex(searchKey);
   HashedEntry<KeyType, ItemType> * chainPtr = hashTable[itemHashIndex];
   
   // Short circuit evaluation is important here
   while ((chainPtr != nullptr) && (searchKey != chainPtr->getKey()))
   {
      chainPtr = chainPtr->getNext();
   } // end while 
   
   return (chainPtr != nullptr);
} // end contains

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::traverse(void visit(ItemType&)) const
{
   // Simple because the array is sorted.
   for (int index=0; index<hashTableSize; index++)
   {
     HashedEntry<KeyType, ItemType> * chainPtr = hashTable[index];
     while (chainPtr != nullptr)
      {
         ItemType currentItem = chainPtr->getItem();
         visit(currentItem);
         chainPtr = chainPtr->getNext();
      } // end while 
   }  // end for 
}  //end traverse

#endif
