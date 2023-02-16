#include<iostream>

using namespace std;

/*
Vocabulary
==========
* Runtime stack - the area of an application's memory where activation records are stored
* Early binding - compiler selection of objects' class identities before runtime, which will determine their data members
  and member functions
* Late binding - selection of objects' class identities at runtime
* Code (or text) storage - memory allocated by the OS for code, separate from the runtime stack
* Static storage - memory allocated by the OS for global and static variables, separate from the runtime stack
* Free store (or application heap) - additional memory available for a programmer to store data
* Pointer (variable) - contains the address of a memory cell in free store
* Reference - the address of a memory cell
* Memory leak - memory that has been allocated for use and is no longer needed but cannot be accessed or deallocated
*  

General
=======
~ When an ordinary variable is declared, the C++ compiler allocates a memory cell that can hold the specified data type,
  and the cell is referenced by the variable identifier
~ Each time a function is called, an activation record is created on the runtime stack; when the function returns, the
  activation record is destroyed, freeing the memory used for local variables and parameters
~ Constructors also trigger activation record creation, for the storage of object data members
~ Late binding requires that objects not be stored as an activation record on the runtime stack
~ Free store memory is used for a variable when the operator "new" is used--the memory address of the variable is returned
  so the program can use it
~ Unlike variables on the runtime stack, which have their memory automatically allocated and deallocated, free store variables
  persist in memory after the function or method that created them returns, until the programmer deallocates them
~ 
*/

int main() {
    return 0;
}