// Chapter 10 Concepts

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<memory>
#include<vector>

using namespace std;

/*
Vocabulary
==========
* Pointer - a value that represents the address of a memory location or holds the address of a variable
* Address operator (&) - returns the memory address of its operand
* Pointer variable - a variable that holds memory location addresses
* Indirection operator (*) - allows for passing from a pointer to the variable being pointed to
* Pointer dereferencing - usage of the indirection operator with a pointer that has been defined, in order to access the
  value stored at the address it holds
* Pointer constants - pointers reserved for arrays
* Null pointer - a pointer that has been initialized to address 0 (or NULL)
* Constant pointer - a pointer that cannot change the address it stores
* Dynamically allocated memory - allotment of unused memory large enough to hold a variable of a specific data type using
  the `new` operator
* Heap - special memory cells of a program that are reserved for dynamic assignment during runtime
* Exception - a mechanism for notifying a program that something has gone wrong with an operation that was being
  executed and that its results are unreliable; by default, the response to an exception is forcing program termination
* Dangling pointer - a pointer that points to a heap location that has been freed by `delete`
* Memory leak - occurs when memory allocated with `new` is not freed with `delete`, making it unavailable for use until a
  program's termination
* Structure pointer operator (->) - dereferences a pointer to a structure or class object, allowing for public member access
* Double deletion - use of `delete` on a pointer that has already been deleted--harmful when the pointer has been reallocated
* Smart pointer - an object that wraps a pointer and deletes dynamically allocated memory that is no longer being used
* Unique pointer - a pointer for a dynamically allocated object that should be owned only by a single pointer; the object is
  automatically deallocated if the pointer if the pointer is going out of scope or if ownership is transferred
* Shared pointer - a pointer that shares ownership of an object and maintains the count of co-owning pointers, called a
  reference count; the object is deleted when the reference count is zero
* Raw pointer - a pointer wrapped to produce a smart pointer
* Control block - a dynamically allocated object that tracks both a shared pointer's reference count and the raw pointer that
  points to the managed object; it is responsible for deleting the managed object when the reference count becomes zero
* The epoch - the reference time used to express time in computers--January 1, 1970 at midnight

General
=======
~ Every variable is assigned a memory location whose address can be retrieved using the address operator &
~ Current computer hardware can access data that resides at even addresses faster than data residing at odd addresses,
  so most compilers allocate space in such a way that individual variables are always assigned even addresses
~ C++ displays addresses in hexadecimal by default
~ int* ptr: "ptr is a pointer to int" = "the variable that ptr points to has type int"
~ Array names can be used as pointer constants, because an array name, with brackets and a subscript, represents the
  starting address of the array; similarly, pointers can be used as array names, without the need for dereferencing
~ Elements in an array can be accessed by subscript (e.g. array[i]) or by addition of its subscript to the array pointer
  (e.g. *(arrayPtr + i))
~ C++ performs no bounds checking with arrays, so it's possible to accidentally access a cell outside an array when
  stepping through an array
~ The only difference between array names and pointer variables is that the address of an array name cannot be changed
~ Legal pointer arithmetic:
  1) Increment/decrement operators
  2) Integer addition or subtraction, including += & -=
  3) subtraction between pointers
~ Pointers may only be initialized with addresses of objects already defined
~ Local pointer variables that have not been initialized do not hold valid addresses; use of these pointers will cause
  runtime errors
~ Convention for older versions of C++ has been to initialize pointers without a valid address to 0; many computers
  keep OS data in address 0, inaccessible to user programs, so it remains a safe value for indicating an invalid
  memory location
~ Many header files, such as iostream, fstream, and cstdlib, define constant NULL to represent the pointer value 0;
  therefore, pointer initialization can be rewritten if one of them is included--this is often preferred, since NULL
  is more clearly recognized as an initialized pointer
~ In C++11, empty braces at the end of a variable declaration initializes it to a null value (i.e. 0, 0.0, nullptr)
~ Best practices:
  1) Pointers should always be initialized or assigned a value close to where they are declared
  2) A pointer no longer pointing a valid location should be assigned nullptr unless the pointer is going out of scope
     or the program is about to terminate
~ The relational operators may be used to compare pointers--equivalent to comparing their address values by magnitude
~ Assigning a pointer to input without dereferencing can lead to potentially disastrous results
~ When passing the address of a constant into a pointer variable, the variable must be defined as a pointer to a
  constant
~ Pointer to const: points to a constant, where the data pointed to cannot change but the pointer may change
~ const pointer: pointer may not point to any other address
~ Constant pointers must be initialized with a starting value
~ Every call to `new` allocates storage from a special area of the program's memory called the heap; if a program
  makes too many requests for dynamic memory, the heap will become depleted and additional calls to `new` will fail
  (e.g. a bad_alloc exception is thrown)
~ To free a dynamically allocated block of memory and return it to the heap, use the `delete` operator and pass it
  the address of memory to be deallocated, then assign the pointer to nullptr--the only exception is cases where
  the deleted pointer will clearly never be used again (e.g. the end of a program)
~ Unless a pointer is going out of scope, best practice is to assign free store pointers to nullptr immediately after
  `delete` has been called on it--this prevents problems that can arise from using `delete` on a pointer more than
  once, because `delete` does nothing on a nullptr
~ Dangling pointer prevention:
  1) Assigning pointers to nullptr as soon as memory is freed
  2) Verifying that a pointer is not nullptr before accessing its memory
~ Memory leaks can be especially serious when they occur in loops--even more so in network-based programs that run
  continuously for months or years
~ A function can safely return a pointer to dynamically allocated storage that has not yet been deleted; however,
  functions should not return pointers to local variables, because the storage for such variables is automatically
  deallocated after the function returns
~ Storage for a static local variable is not deallocated upon function return, but there are other problems with
  returning static local pointers
~ Memory leak prevention:
  1) Functions invoking `new` should also invoke `delete`
  2) A class that invokes `new` in its constructors should invoke `delete` in its destructor--this destructor will
     automatically be called by the system whenever an object is deleted or goes out of scope
~ The structure pointer operator does not dereference a pointer that is a member of a structure or a class
~ Operators -> and . have higher precedence than dereferencing operator * when selecting class/structure members:
  1) objectPointer->member - accesses member pointed to by objectPointer
  2) *object.memberPointer - accesses the value pointed to by object.memberPointer
  3) (*objectPointer).member - accesses member of *objectPointer (equivalent to objectPointer->member)
  4) *objectPointer->memberPointer - accesses value pointed to by object->memberPointer
  5) *(*objectPointer).memberPointer - accesses value pointed to by (*objectPointer).memberPointer (equivalent to
     *structurePointer->memberPointer)
~ Smart pointers:
  1) Unique pointers
  2) Shared pointers
  3) Weak pointers
~ A smart pointer is said to own (or manage) the object that it points to; ownership can be transferred between
  pointers
~ To avoid memory leaks, objects that are managed by smart pointers should have no other references to them
~ Smart pointers do not support pointer arithmetic, but they are compatible with the * and -> operators through
  operator overloading
~ Unique pointers cannot be initialized with the value of another unique pointer object or be assigned another unique
  pointer
~ A unique pointer cannot be passed by value to function, because it involves copying the argument as a parameter;
  move(uniquePointer) must be passed to the function unless the unique pointer is passed by reference
~ The compiler automatically applies move() to return values of functions returning unique_ptr objects, so unique
  pointers can be returned by functions
~ Smart pointers should never be dynamically allocated; best practice is declare them as local variables of a function
  where they will delete their managed objects as they go out of scope
~ Manual deletion of a smart pointer's managed object can be done with its member function reset() or by assigning it
  nullptr
~ Unique pointer member functions:
  1) reset() - destroys managed object
  2) reset(T* rawPointer) - reassigns unique pointer to the value of rawPointer
  3) get() - returns raw pointer
~ The shared_ptr class overloads the * and -> operators
~ For a shared pointer, the shared pointer points to the control block, and the control block points to the managed
  object
~ Best practice with shared pointers is to avoid multiple groups of pointers managing the same raw pointer; if one
  of the groups deletes the object, then the other groups are left with a dangling pointer
~ Shared pointer member functions:
  1) get()
  2) reset()
  3) reset(T* rawPointer)
~ The time_t data type represents the number of seconds since the epoch
*/

class Rectangle {
    public:
        int width=1;
        int length=1;
        Rectangle();
        Rectangle(int newL, int newW) : width(newW), length(newL) {}
        int getArea() {return length * width;};
};

struct Student {
    string name;
    int* testScores;
    double average;
};

void doubleValue(int*);
void doubleValue(double*);
void getFloat(float*);
double sumArray(double*, int);
void displayConstantArray(const int*, int);
void displayNonconstantArray(int*, int);
int *calculateCubes(int);
int *calculateSquares(int);
void magnifyRectangle(Rectangle*, int);
void passSmartPointerByValue(unique_ptr<int>);
void passSmartPointerByReference(unique_ptr<int>&);

int main() {
    float floatVariable;
    float* floatPointer = &floatVariable;     // classic pointer declaration
    float *anotherFloatPointer;               // alternative pointer declaration
    float declaredFloat, *thirdFloatPointer;  // inline type & pointer declaration
    int anInteger = 10, *thisPointer = &anInteger;  // inline type & pointer definition
    int anotherInteger = 42, *thatPointer = &anotherInteger;
    double quarters[4], *proportions = quarters;
    char* zeroPointer = 0;      // traditional default pointer initialization
    char* nullPointer = NULL;   // equivalent to a zero-initialized pointer

    // Display memory address
    cout << long(&floatVariable);

    // Display float variable value via float pointer dereferencing
    cout << long(*floatPointer);

    // Pointer operations
    thisPointer - thatPointer;  // pointer subtraction
    thisPointer++;              // pointer increment
    thatPointer--;              // pointer decrement
    thisPointer += 2;           // integer addition
    thatPointer -= 5;           // integer subtraction

    // Null pointer
    cout << "pointer(0) = pointer(NULL) = nullptr: " << ((zeroPointer == nullPointer && nullPointer == nullptr) ? "true" : "false") << endl;

    // C++11 initialization to defaults
    int defaultInteger{};   // 0
    double defaultDouble{}; // 0.0
    char* defaultPointer{}; // nullptr

    // Passing pointers to functions

    doubleValue(&anInteger);
    doubleValue(&defaultDouble);
    getFloat(anotherFloatPointer);  // passing pointer instead of variable reference

    double doubles[] = {3.14, 4.37, 7.37, 42.0};  // already recognized as a pointer
    cout << "Sum of array is " << sumArray(doubles, 4) << endl;

    // Constant pointer parameters

    const int integerArray[] = {1, 2, 3, 4, 5};
    int anotherArray[] = {6, 7, 8, 9, 10};

    displayConstantArray(integerArray, 5);
    displayConstantArray(anotherArray, 5);
    // displayNonconstantArray(integerArray, 5); -- illegal
    displayNonconstantArray(anotherArray, 5);

    // Constant pointers
    int* const CONSTANT_POINTER = &anInteger; // pointer must always point to this address, but value at address may change
    const int* const CONST_PTR_CONST_VALUE = &anotherInteger; // pointer must always point to this address, and value cannot be changed

    // Dynamic memory allocation
    int* freeStorePointer = nullptr;  // pointer initialization--this is not dynamic memory allocation
    freeStorePointer = new int;       // the `new` operator allocates free store cell(s) for this variable
    *freeStorePointer = 42;           // assignment of a value to keep in the allocated cell
    freeStorePointer = new int[100];  // array created in free store--we can reassign int-type pointer to array name

    // Returning memory to the heap
    delete [ ] freeStorePointer;  // no brackets for a non-array type
    freeStorePointer = nullptr;

    // Array-returning function
    int* cubes = nullptr;       // initialize dynamically allocated pointer (array name)
    cubes = calculateCubes(4);  // int pointer can receive new int array

    // Class (and structure) pointers

    Rectangle* rectanglePointer = nullptr;
    Rectangle newRectangle;
    rectanglePointer = &newRectangle;

    cout << "Rectangle width: " << (*rectanglePointer).width << endl;  // indirection & dot operators to access data member
    cout << "Rectangle length: " << rectanglePointer->length << endl;  // structure pointer operator to access data member
    cout << "Rectangle area: " << rectanglePointer->getArea() << endl; // structure pointer operator to access member function 

    // Dynamically allocated objects

    Rectangle* freeStoreRectangle = new Rectangle;
    freeStoreRectangle->width = 3;
    freeStoreRectangle->length = 4;

    Rectangle* initializedRectangle = new Rectangle(5, 10);

    magnifyRectangle(initializedRectangle, 2);

    // Classes (and structures) with pointer members

    Student student1;
    Student* studentPointer;

    cout << "Value of testScores member for student1: " << *student1.testScores << endl;
    cout << "Value of testScores member for studentPointer: " << *studentPointer->testScores << endl; // equivalent to *(*studentPointer).testScores

    // Unique smart pointers

    unique_ptr<int> smartInt(new int);
    unique_ptr<double> smartDouble(new double);
    
    unique_ptr<int> secondSmartInt; // declared
    secondSmartInt = unique_ptr<int>(new int);

    *secondSmartInt = 42;
    *secondSmartInt += 1;
    cout << *secondSmartInt << endl;

    // Unsafe smart pointer assignment
    int* someIntPointer = new int;
    unique_ptr<int> uniquePointer(someIntPointer);

    // Smart pointer transfer of ownership - deallocation and nullptr assignment occurs implicitly
    uniquePointer = move(secondSmartInt); // transfer of value ownership from secondSmartInt to uniquePointer

    // Passing unique pointers to functions
    passSmartPointerByValue(move(uniquePointer));
    passSmartPointerByReference(uniquePointer);

    uniquePointer.reset();  // delete smart pointer's managed object

    // make_unique<T>() in C++14
    unique_ptr<int> cpp14smartPointer = make_unique<int>();

    // Smart pointer arrays
    unique_ptr<int[]> arraySmartPointer(new int[5]); // brackets flag array name for proper deletion
    unique_ptr<int[]> anotherArraySmartPointer = make_unique<int[]>(5); // equivalent to previous line

    // Shared pointers

    shared_ptr<int> sharedPointer(new int);
    *sharedPointer = 437;

    shared_ptr<Rectangle> rectangleSharedPointer(new Rectangle());
    shared_ptr<Rectangle> anotherRectangleSharedPointer(new Rectangle(2, 4));
    shared_ptr<Rectangle> thirdRectangleSharedPointer = make_shared<Rectangle>(8, 16);
    shared_ptr<Student> studentSharedPointer = shared_ptr<Student>(new Student());
    shared_ptr<Student> anotherStudentSharedPointer = make_shared<Student>(); // automatically allocates a single memory block large enough to hold the control block & the managed object
    
    shared_ptr<Rectangle> thirdRectangleSharedPointer = rectangleSharedPointer; // pointer sharing
    thirdRectangleSharedPointer = anotherRectangleSharedPointer; // ownership of rectangleSharedPointer relinquished--reference count decremented

    // Testing shared pointer ownership

    if (thirdRectangleSharedPointer)
        cout << "Shared pointer manages an object" << endl;
    else
        cout << "Shared pointer is empty" << endl;

    // Shared pointer container

    // shared_ptr<int[]> integerSharedPointer; // illegal
    shared_ptr<vector<int>> vectorSharedPointer; // vector must be used as container for shared pointers

    // Time since epoch
    time_t secondsSinceEpoch;
    time(&secondsSinceEpoch); // determines seconds since epoch

    return 0;
}

void doubleValue(int* integer) {
    *integer *= 2;
}

void doubleValue(double* decimal) {
    *decimal *= 2;
}

void getFloat(float* number) {
    cin >> *number;
}

double sumArray(double* array, int size) {
    double sum = 0.0;
    for (int i=0; i<size; i++) {
        cout << "Adding " << array[i] << " to sum" << endl;  // array may still be indexed as a pointer
        sum += *array++;  // steps through array without indexing
    }
    return sum;
}

void displayConstantArray(const int* integers, int size) {
    for (int i=0; i<size; i++) {
        cout << *(integers + i) << endl;
    }
    cout << endl;
}

void displayNonconstantArray(int* integers, int size) {
    for (int i=0; i<size; i++) {
        cout << *(integers + i) << endl;
    }
}

void displayTrueConstantArray(const int* const integers, int size) {
    for (int i=0; i<size; i++) {
        cout << *(integers + i) << endl;
    }
    cout << endl;
}

int *calculateCubes(int n) {
    int* cubeArray = new int[n];
    for (int i=0; i<n; i++) {
        cubeArray[i] = pow(i+1, 3);
    }
    return cubeArray;
}

int *calculateSquares(int n) {
    int array[100]; // this array is local
    for (int i=0; i<n; i++) {
        array[i] = pow(i+1, 2);
    }
    return array; // the array's address will be deallocated
}

void magnifyRectangle(Rectangle* rectangle, int factor) {
    rectangle->width *= factor;
    rectangle->length *= factor;
}

void passSmartPointerByValue(unique_ptr<int> pointer) {
    cout << *pointer << endl;
}

void passSmartPointerByReference(unique_ptr<int>& pointer) {
    cout << *pointer << endl;
}