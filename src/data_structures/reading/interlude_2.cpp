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
* Deallocation - freeing the memory cell pointed to by a pointer, using the delete operator and assigning the pointer to nullptr
* Dangling pointer - a consequence of deallocating a pointer without subsequently assigning nullptr to a pointer, where the
  pointer still contains the deallocated object's address
* Alias - the case of more than one pointer referring to the same object in free store
* Virtual method - a class method using the "virtual" keyword that can be overriden by derived classes, allowing for late binding
* Extensible - the flexibility of a parent class to permit derived-class implementation of additional capabilities, without
  direct access to its ancestors
* Resizable array - a dynamically-allocated array that can be reinstantiated with a new size using a pointer reference

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
~ The only way to access an object pointer's methods is with arrow notation, where -> indicates that the object whose method
  is being called is in free store:
  MagicBox<string>* myBoxPointer = new MagicBox<string>(); // myBoxPointer points to a MagicBox pointer
  string someItem = "Something";
  myBoxPointer->setItem(someItem); // "Something" will be stored in free store with the object
~ Pointers are simply another type of variable and follow the same rules as other variable types
~ Two pointer variables that can point to the same type can point to the same object--this is essentially copying the location
  value (but not copying the object itself)
~ Pointers cannot be simply declared; they must be initialized to nullptr (e.g. "ToyBox<int>* myToyPointer = nullptr")
~ If a method of a class uses new to create an object, some method of the class must eventually use delete to free the object's
  memory; it's a characteristic of safe and secure programming that any object allocating memory from the free store also
  assumes responsibility to deallocate that memory when it's no longer needed
~ A program can quickly run out of memory and crash if it has several memory leaks--even a single statement called multiple
  times can cause a memory leak
~ A more subtle memory leak occurs when a function or method creates an object in the free store and loses the pointer to it
  by either not returning that pointer to the caller or not storing it in a class data member
~ When a function returns a pointer to an object that it created in the free store, that program segment becomes responsible
  for deleting the object; documentation (including comments) should communicate this responsibility
~ Best practice is not to use a function that returns a pointer to a newly created object--instead, define a class that has a
  method for the task needed where the class will then be responsible for deleting the object to prevent a memory leak
~ Minimum components for a class that substitutes a pointer-returning function:
  1) A method that creates the object in free store
  2) A data field that points to the object
  3) A destructor that deletes the object when the class instance is no longer needed
~ Every C++ class has a destructor, to be called when the client uses the delete operator after instantiating using new
~ Often, the compiler-generated desstructor is sufficient for a class, but if the class itself creates an object in the free
  store as a data member, safe & secure programming practices oblige implementation of a destructor
~ When a class has an implemented destructor, the compiler can check a function using the class to make sure it instantiates
  an object before calling one of its member functions and automatically deallocate the object's memory safely by calling its
  class's destructor when the function ends execution
~ Dangling pointer causes:
  1) A pointer variable is not assign nullptr after a delete operation
  2) A pointer variable is declared rather than assigned nullptr--pointer will have undefined value;
  3) A pointer alias's sibling pointer deletes the memory cell value and address--alias still references the free store
     location, after the object no longer exists
~ Dangling pointer prevention:
  1) Assign pointer variables to nullptr to declare and after they're no longer needed
  2) Test whether a pointer variable value is nullptr before calling its member functions
  3) Avoid aliases when possible
  4) Do not delete an object in the free store until all other aliases no longer need it
  5) Set aliases that reference deleted objects to nullptr when their objects are deleted
~ Destructors can and should be virtual, to ensure that future descendants of the object can safely deallocate themselves
~ A member function's return type cannot be overridden
~ Array pointers can dynamically allocate memory for many objects at one time, using the new operator
~ The memory cells need to be returned to the system when a dynamically allocated array is no longer needed
  (e.g. "delete [ ] <arrayVariable>")
*/

int main() {

    // Dynamic array reallocation

    int arraySize = 50;
    double*anArray = new double[arraySize];  // array of memory cells allocated
    
    double* oldArray = anArray;           // copy pointer to array
    anArray = new double[2 * arraySize];  // dynamic reallocation

    for (int index=0; index<arraySize; index++)
        anArray[index] = oldArray[index];
  
    delete [ ] oldArray;

    return 0;
}