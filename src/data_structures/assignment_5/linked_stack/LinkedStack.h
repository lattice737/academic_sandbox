/** ADT stack: Link-based implementation.
 @file LinkedStack.h */

#ifndef LINKED_STACK_
#define LINKED_STACK_

#include "StackInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType> {
    private:
        Node<ItemType>* topPtr;
    public:
        LinkedStack();                                          // default
        LinkedStack(const LinkedStack<ItemType>& anotherStack); // copy
        virtual ~LinkedStack();                                 // destructor
        bool isEmpty() const;
        bool push(const ItemType& newItem) throw(MemoryAllocationExcept);
        bool pop();
        ItemType peek() const throw(PrecondViolatedExcept);
};

#include "LinkedStack.cpp"
#endif