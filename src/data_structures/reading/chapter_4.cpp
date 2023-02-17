#include<iostream>

using namespace std;

/*
Vocabulary
==========
* Node - an object that contains data and a reference to another node, in a sequence of nodes
* Head pointer - a pointer with the sole purpose of pointing to the first of several linked nodes; it does not contain data
  and is not itself a node, only linking (or referencing) to the first node
* Traverse - an operation that visits each node in a linked chain
* Visit - an iteration of a traversal where a node is evaluated
* Defensive programming - development that prevents future errors and secures an implementation from client abuse
* Copy constructor - a constructor that duplicates an object when an object is assigned to a variable, an object is passed to
  a function by value, an object is returned from a valued function, or an object is defined and initialized using another,
  existing object
* Shallow copy - object duplication only by copying its data member values
* Deep copy - object duplication that includes data that is not explicitly defined as data members, such as a chain of pointers
  where only the head pointer is a data member
* Implicit location of elements - the relationship of a containers' elements and their predecessors/successors without accessing
  characteristic information about them
* Explicit location of elements - the relationship of a containers' elements and their predecessors/successors where their
  references are stored within the elements
* Direct access - the capability to retrieve any element of a container in constant access time
* Access time - the comparative time required to retrieve a container's element

General
=======
~ Dynamic allocation of a node: nodePointer = new Node<string>();
~ Access the value to which nodePointer points: nodePointer->getItem();
~ Access the next value to which nodePointer points (final value will be nullptr): nodePointer->getNext();
~ A head pointer has value nullptr
~ A new Node object is not needed before assigning a head pointer
~ Link-based implementaiton:
  1) Does not impose a fixed maximum size on the data structure (excluding system storage limit)
  2) Insertion & removal operations do not need to move data
~ The compiler-generated copy constructor and destructor are insufficient for a class with dynamically allocated memory
~ Traversal requires tracking the position of a node in a linked chain--this is represented by the Node instances, which
  are pointers
~ A common traversal error is to compare currentPointer->getNext() instead of currentPointer for nullptr; this will
  terminate before accessing the last node's data
~ A chain of dynamically allocated nodes cannot be emptied without traversing the chain--the nodes must each be deallocated
~ Compiler-generated copy constructors produce shallow copies, so the copy constructor can be omitted if only an object's
  values need to be copied
~ Copy constructors are expensive, traversing the original linked chain and duplicating each visited node
~ If a pointer variable is declared to implement the methods in a common interface, any instance that implements the interface
  can be used as the object that the pointer references (e.g. "BagInterface<string>* bagPointer = nullptr" can be assigned either
  a ArrayBag or a LinkedBag instance)
~ A collection of data in an array or linked chain is ordered, implying that most of the items will have one predecessor and
  one successor: array elements have implicitly located predecessors/successors where a value represents their positions in the
  array (e.g. array[i+1]); however, linked list nodes have explicitly located predecessors/successors, where each node contains
  an actual reference to its successor
~ Link-based implementation advantages:
  1) Container size can be increased during runtime
~ Array-based implementation advantages:
  1) Implicit element relationship
  2) Provides direct access to any specified item
  3) Fixed length means fixed cost--no risk of growing to prohibitively large size during runtime or time spent copying or
     deallocating elements
*/

int main() {
    return 0;
}