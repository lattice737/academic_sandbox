// Chapter 8 Concepts

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

/*
Vocabulary
==========
* Size declarator - a constant, natural number representing the amount of elements an array can hold, specified at definition 
* Subscript - used as an index to locate a specific element in an array
* Implicit array sizing - array initialization without a size declarator
* Functional-notation initialization - uses parentheses instead of the assignment operator (e.g. int value(5);)
* Brace-notation initialization - uses braces instead of the assignment operator (e.g. int value{10};)--only available for C++11<
* Range-based for loop - iterates once for each element in an array
* Range variable - a built-in variable that stores a copy of the next array element for each iteration of a range-based for loop; its type
  must match the type of the array elements
* Parallel arrays - two or more arrays that store related data, usually of different types
* Standard template library (STL) - a collection of programmer-defined data types and algorithms available for use in C++ programs
* Containers - the conventional name for data types defined in the STL, because they store and organize data
* Sequence container - organizes data in a sequential fashion, similar to an array
* Associative container - organizes data with keys to allow rapid, random access to elements
* Vector - A sequence container that does not require a size declarator, automatically accommodates size for newly added values, and
  can report the number of elements it has

General
=======
~ Elements can be assigned to values consistent with the array type
~ Indexing is expressed as "<array var> sub <index>"
~ A globally defined numeric array has elements initialized to zero by default; a locally defined array has no initialized element values
~ An existing array variable cannot be reassigned a new array
~ cin & cout can be used with array element assignment & display, as long as they're done one element at a time
~ Many of the safeguards provided by other languages to prevent programs from unsafely accessing memory are absent in C++; what exactly
  occurs depends on how your system manages memory
~ An array can be partially initialized, but if an element is uninitialized, all following elements must be initialized as well
~ An initialization list must be specified if the size declarator is omitted
~ Brace notation offers the advantage of validating that the type of the initialized value matches the variable data type
~ Range-based for loop advantages:
  1) Automatically aware of the array size
  2) Allow for in-place element modification when range variable is declared as a reference variable
~ Range-based for loop disadvantages:
  1) No access to element subscripts
  2) No means to access elements of two or more different arrays
~ To copy values from one array to another, elements from the first array must be accessed and assigned to the second array one at a time
~ Strings are internally stored as arrays of characters, with elements that can be either treated as a set of individual characters or
  used as a single entity
~ There is no guarantee of how string objects will be implemented; many versions of C++ do terminate string objects with the null
  terminator, but it is never safe to assume they will always be terminated this way
~ The typedef keyword allows an alias to be associated with a simple or structured data type
~ The name of an array without a subscript does not hold any data--it holds the starting address of the array's location in memory; when
  passed to a function, the name of the array is passed so the function can access the elements
~ When an entire array is passed to a function, it's never passed by value--however, no & is included
~ Function prototype with array parameter: `void doSomething(int [], int);`
~ The const keyword prevents a function from changing an array passed to it; best practice is to use it anytime a function should not
  modify its array argument
~ When a 2D array is passed to a function, the parameter type must contain a size declarator for the number of columns (size of element
  arrays); this is necessary for allocating the proper amount of memory--the compiler needs to know how many bytes separate the rows
~ When passing a multidimensional array as an argument, only the first dimension's size declarator can be omitted in the parameter list
~ Vectors are contained in the std namespace; many older compilers do not allow namespaces or support the STL
~ There are two types of container in the STL: sequence and associative
~ Size declaration with vectors is done with parentheses, not brackets
~ Whenver an array of objects is created with no constructor arguments, the default constructor (if one exists) is used for each object
~ 
*/

class Circle {
    private:
        const double PI=3.14159;
        double radius;
        int centerX, centerY;
    public:
        Circle() {radius=1.0; centerX = centerY = 0;}
        Circle(double r) {radius=r; centerX = centerY = 0;}
        Circle(double r, int x, int y) {radius=r; centerX=x; centerY=y;}
        void setRadius(double r) {radius = r;}
        int getXcoord() {return centerX;}
        int getYcoord() {return centerY;}
        double findArea() {return PI * radius * radius;}
};

struct Book {
    string title;
    string author;
    string publisher;
    double price;
    Book(string t="Untitled", string a="Unknown", string p="Unknown", double c=10.99) {
        title=t;
        author=a;
        publisher=p;
        price=c;
    }
};

const int NUM_CIRCLES = 5;
const int TWO_D_ARRAY_SIZE = 2;
const int NUM_SECTIONS = 3,
          ROWS_IN_SECTION = 5,
          SEATS_IN_ROW = 8;

typedef int arrayType[];
typedef int intTable[][TWO_D_ARRAY_SIZE];
typedef double seatTable[][ROWS_IN_SECTION][SEATS_IN_ROW];
typedef Circle circleArray[];

void iterativelyIncrement(const arrayType, int);
void showElements(const arrayType, int);
void show2dElements(const intTable, int);
void showSeats(const seatTable);
vector<int> addElements(vector<int>);
void showCircles(circleArray, int); // array not compatible with const keyword

int main() {
    const int NUM_MONTHS = 12,
              SIZE = 6;
    int days[NUM_MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        sequence[] = {1, 2, 3, 4, 5, 6, 7, 8}, // implicit sizing
        numbers[7] = {1, 2, 4, 8}, // partial initialization
        hours[SIZE];
    int value(5);

    // range-based for loop
    for (auto daysPerMonth : days) {
        cout << daysPerMonth;
    }

    // range-based for loop with reference range variable (array modification)
    for (int &value : sequence) {
        value += 2;
    }

    // typedef keyword
    typedef int examScore;
    examScore exam1 = 95;

    // typedef keyword wtih array
    typedef double score[100];
    score finalExam;            // equivalent to: `double finalExam[100];`

    typedef int arrayType[];    // omitted size declarator

    iterativelyIncrement(sequence, 8);  // passing array to function
    showElements(numbers, 4);           // const keyword

    // 2D arrays
    int values[3][2] = {{8, 5}, {7, 9}, {6, 3}},
        moreValues[3][2] = {{2, 4},
                            {3, 9},
                            {4, 16}},
        oneDimInitializedArray[3][2] = {2, 8, 3, 27, 4, 64}, // will be mapped to {{2, 8}, {3, 27}, {4, 64}}
        partialArray[3][2] = {{1}, {3, 4}, {5}}; // elements 0,1 & 2,1 will be initialized to 0

    show2dElements(oneDimInitializedArray, 3);

    // 3D+ arrays
    double seats[NUM_SECTIONS][ROWS_IN_SECTION][SEATS_IN_ROW];

    showSeats(seats);

    // Vectors
    vector<int> integers,
                tenIntegers(10),            // size declaration
                fiveTwos(5, 2),             // size declaration, initialization values
                otherVectorInts(fiveTwos);  // initialization with another vector
    vector<string> names {"Diana", "Angela", "Liz"};
    vector<char> escapeLetters {'n', 't', 'b'};

    for (auto name : names) {
        cout << name << endl;
    }

    // Add elements to vector & show vector size
    addElements(integers);

    // Vector methods
    integers.pop_back();        // Remove last element
    integers.at(2);             // Returns element at passed subscript
    integers.clear();           // Remove all elements
    integers.empty();           // Return truth of vector emptiness
    tenIntegers.resize(15, 99); // Resize vector to length 15, (optionally) initialize new values to 99
    tenIntegers.swap(fiveTwos); // Swaps the elements of tenIntegers with those of fiveTwos

    // Object array initialization
    Circle circles[NUM_CIRCLES] = {0.0, 0.5, 1.0, 1.5, 2.0},      // will only initialize radii
           partialCircles[NUM_CIRCLES] = {2.25, 2.5, 2.75, 3.0};  // remaining element will be initialized with default constructor Circle()
    circleArray otherCircles = {5.0, 10.0, 15.0},
                specificCircles = {Circle(2.0, 1, 1), Circle(5.0, -1, -1), Circle(10.0), Circle(0.75, -1, 1), 3.0}; // various instantiation

    showCircles(otherCircles, NUM_CIRCLES);

    // Structure array
    Book readingList[10],
         favoriteBooks[2] = {Book("The Stranger", "Albert Camus", "Alfred Knopf", 13.50),
                             Book("The Color of Law", "Richard Rothstein", "Liveright", 12.53)};

    return 0;
}

void iterativelyIncrement(arrayType array, int size) {
    for (int i=0; i<size; i++) {
        array[i]++;
    }
}

void showElements(const arrayType array, int size) {
    for (int i=0; i<size; i++) {
        cout << array[i] << endl;
    }
}

void show2dElements(const intTable array, int rows) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<TWO_D_ARRAY_SIZE; j++) {
            cout << array[i][j] << endl;
        }
    }
};

void showSeats(const seatTable array) {
    for (int section=0; section<NUM_SECTIONS; section++) {
        for (int row=0; row<ROWS_IN_SECTION; row++) {
            for (int seat=0; seat<SEATS_IN_ROW; seat++) {
                cout << array[section][row][seat] << endl;
            }
        }
    }
}

vector<int> addElements(vector<int> list) {

    cout << list.size();
    
    for (int i=10; i<101; i+=10) {
        list.push_back(i);
    }
    
    cout << list.size();

    return list;
}

void showCircles(circleArray array, int size) {
    for (int i=0; i<size; i++) {
        cout << array[i].findArea() << endl;
    }
}