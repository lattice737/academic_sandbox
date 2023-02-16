#include<iostream>
#include<string>

using namespace std;

/*
Vocabulary
==========
* Abstract data type - a collection of data, together with a set of operations on that data
* Data structure - a construct that you can define within a programming language to store a collection of data
* Core methods - class methods that are central to the purpose of the class and allow reasonable testing
* Core group - a group of core methods and any of their helper methods
* Helper methods - additional methods that core methods may call, also part of the core group
* Array-based implementation - a class implemented to store data in an array
* Stub - an incomplete definition of a method, intended to satisfy syntax validation during development
* 

General
=======
~ Data structures for implementing an ADT should only be considered after its operations have been clearly specified
~ The description of an ADT's operations must be rigorous enough to specify completely their effect on the data, yet it must not
  specify how to store the data nor how to carry out the operations
~ In general, an ADT should be refined through successive levels of abstraction yielding successively more concrete descriptions
  of the ADT
~ Implementing an ADT as a C++ class provides a way to enforce the wall of an ADT, preventing access of the data structure in any
  way other than by using the ADT's operations and preventing accidental damage of the data by the client
~ In general, a class should not be first completely defined and then tested; a group of core methods should be implemented and
  tested first to simplify task development
~ Method testing requires methods that access the class's data
~ When implementing an ADT that represents data collection, the items and the quantity of items need to be stored
~ Certain truths (or assertions) about the planned implementation need to be established so that the action of each method is not
  detrimental to the other methods
~ Advantages of private data members:
  1) Control of how a client can access or change values, to protect the integrity of the data structure
  2) Limited debugging scope, to only the logic within the class
~ When a method doesn't alter a class's data members, make it a const method as a safeguared against an implementation error
~ Any method that returns an index to a private array should be declared as private
~ Variables that are local to a method's implementation should not have the same name as the class data members
~ Instead of writing a complete implementation of each method from the start, unstarted methods can be given incomplete definitions
  until it's time to implement them
~ Value-returning method stubs should return a dummy value, but void method stubs can have an empty body
~ Stub calls within a test program should display a message to indicate that they were called
~ Do not wait until implementation of an ADT is complete before testing
~ If a class constructor is defined but no default constructor is defined, the compiler will not produce one
~ The appropriateness of an array-based implementation requires that the number of items in the array is known in advance and that
  the storage required to declare a sufficiently large array for the maximum number of elements is not wasteful
~ Stylistically, one return statement is preferred for each method
~ 
*/

int main() {

}