// Chapter 6 Concepts

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<cmath>

using namespace std;

/*
Vocabulary
==========
* Modular programming - a program that can be broken up into a set of maangeable functions (or modules)
* Function - a collection of statements that performs a specific task
* Divide & conquer - division of a larger problem into smaller, less complex problems
* Code reuse - implementation of a task so that it can be reused without repeating statements
* Void functions - functions that have no return value
* Function prototype - a compiler marker indicating that a function will be implemented
* Argument (or actual parameter) - a value that's sent into a function
* Parameter (or formal parameter) - a special variable that holds a value being passed as an argument into a function
* "Passed by value" - Information transmission to a function via parameter receiving of a passed value
* Value-returning functions - functions that return a value
* Local variable - a variable defined with a function, only accessible within that function
* Global variable - defined outside all functions; accessible to all functions until the program finishes running
* Local variable lifetime - the execution of a function where a local variable is defined
* Global constant - a named constant avaialable to all functions of a program
* Shadowing - the hiding of a global variable when a parameter or local variable of the same name is encountered
* Static variable - a variable that is persists after a function returns, until the end of runtime
* Default arguments - literals or constants passed to a function's parameters when the actual argument is omitted from the call;
  usually defined in the prototype
* Reference variable - a variable referring to the memory location of another variable, usually used as function parameters;
  acts an alias to the other variable
* Function signature - the function name and (ordered) parameter data types
* Stub - a dummy function that is called instead of an implemented function, usually only displaying a test message
* Driver - a test program that calls a function with test arguments and displays return values

General
=======
~ The compiler must know the number of parameters, the parameter data types, and the return type of the function
  before encountering a function call--function prototypes provide this information
~ The order of the function definitions doesn't matter when function prototypes are used
~ Only the parameter types are required for function prototypes; the parameter name is optional
~ When an argument is passed into a parameter by value, only a copy of the argument's value is passed, with its own memory location
~ The parameter names of a function prototype are dummy names and do not have to agree with the function header
~ Best practice is to implement value-returning functions to have one return statement placed at the end of the function
~ Linux/Mac: system("clear") clears the terminal and places the cursor back at the top
~ When a function block is called, its parameter variables and local variables are created in memory; they're destroyed when the
  function returns
~ Global variables initialize to zero (NULL for char) unless they're initialized
~ Risks of global variables
  1) Increased debugging difficulty - all statements must be reviewed
  2) Decreased modularity - strongly coupled to specific program
  3) Decreased comprehensibility - function cannot be understood independently
~ A function's local variables cannot be defined with the same names as its parameters
~ Best practice is to assign default arguments at the earliest function name occurrence, but they may be specified in the header
  when there is no prototype
~ When an argument is omitted from a function call, all following arguments must also be omitted
~ When a function uses a combination of parameters with & without default arguments, the default-argument parameters must be
  declared last
~ Any change made to a reference variable is actually made to the variable it references
~ "Pass by reference" - using a reference variable as a parameter (e.g. void doSomething(int &reference))to reference an actual
  argument, where changes to the parameter persist in the passed value
~ If a nonvariable argument (i.e. literal, constant, or expression) is passed by reference, an exception is thrown
~ Overloading distinguishes based on function signature--parameter lists must differ, and return type is not considered
~ exit() stops the program; exit code parameter (e.g. exit(0) stops program with exit code 0)
~ Best practice is to use exit() exclusively for error handling (e.g. returning a nonzero exit code)
~ Stubs confirm function calls, valid passed arguments, and proper handling of return values

Passing Table
=============
Case                                                    By Value    By Reference
1) constant arg                                         x
2) variable arg that should not be changed              x
3) one return value                                     x
4) two or more args that need to be changed                         x
5) an arg copy cannot be reasonably/correctly made                  x
6) an arg value needs to be known by the calling fxn                x
7) a fxn must change existing calling fxn values                    x
8) passing a file stream object to a fxn                            x
*/

// Function prototypes
void sayHelloWorld();
int addTwoIntegers(int, int);
double calculateCircleArea(double r);
double calculatePrismVolume(double l=1.0, double w=1.0, double h=1.0);
void displayName(string first, string middle="", string last="Doe");
void countIterations();
void squareInteger(int &yourInteger);   // <type> &<reference>
void squareFloat(double &yourDouble);   // <type>& <reference>
void sortAscending(int&, int&);
void readFile(ifstream&);
bool readFileData(ifstream& file, string& city, string& state);
void solveTheUniverse(int);

// Overloading for different parameter types
void squareNumber(int&);
void squareNumber(double&);

// Overloading for different numbers of parameters
int addIntegers(int, int);
int addIntegers(int, int, int);
int addIntegers(int, int, int, int);

/* Invalid overloading (for different return types) - 
int halveInteger(int);
double halveInteger(int);
*/

// Globals
char globalChar;            // global variable - avoid
int globalInteger;
const double PI=3.14159;    // global constant - OK
const string FIRST_NAME="Nicholas";
const string MIDDLE_NAME="Edward";
const string LAST_NAME="Martinez";
const string PATH="/Users/nicholas/academic_sandbox/src/fundamentals/chapter_6/";
const string EXAMPLE_FILE="example.txt";
const string CITY_FILE="cities.txt";

int main() {
    double length=5.0,
           mutableDouble=9.0;
    int leftInteger=2,
        rightInteger=3,
        mutableInteger=4,
        alwaysLeftInteger=10,
        alwaysRightInteger=1;
    ifstream inputFile(PATH+EXAMPLE_FILE),
             cityFile(PATH+CITY_FILE);
    string city,
           state;

    // Implementing functions
        
    sayHelloWorld();

    cout << leftInteger << " + " << rightInteger << " = " << addTwoIntegers(leftInteger, rightInteger) << endl;
    cout << "The area of a circle with radius " << length << " has area " << calculateCircleArea(length) << endl;
    cout << "Default prism volume has volume " << calculatePrismVolume() << endl;
    cout << "Custom prism volume, with L=" << leftInteger << " and W=" << rightInteger
         << " has volume " << calculatePrismVolume(leftInteger, rightInteger) << endl << endl;

    // displayName(NAME, LAST_NAME); - not allowed
    displayName(FIRST_NAME);
    displayName(FIRST_NAME, "", LAST_NAME);
    displayName(FIRST_NAME, MIDDLE_NAME);
    displayName(FIRST_NAME, MIDDLE_NAME, LAST_NAME);
    cout << endl;

    // Static variables

    for (int i=0; i<5; i++) {
        countIterations();
    }
    cout << endl;

    // Passing by reference

    cout << "mutableInteger is initially " << mutableInteger << endl;
    squareInteger(mutableInteger);
    cout << "Then mutableInteger becomes " << mutableInteger << " after passing by reference" << endl;

    cout << "mutableDouble is initially " << mutableDouble << endl;
    squareFloat(mutableDouble);
    cout << "Then mutableDouble becomes " << mutableDouble << " after passing by reference" << endl;

    cout << "Before sorting: " << alwaysLeftInteger << ", " << alwaysRightInteger << endl;
    sortAscending(alwaysLeftInteger, alwaysRightInteger);
    cout << "After sorting: " << alwaysLeftInteger << ", " << alwaysRightInteger << endl;

    if (inputFile.fail())
        cout << "A problem occurred when opening " << EXAMPLE_FILE << endl;
    else {
        readFile(inputFile);
        inputFile.close();
    }

    if (cityFile.fail())
        cout << "A problem occurred when opening " << CITY_FILE << endl;
    else {
        while (readFileData(cityFile, city, state))
            cout << "City: " << city << " | State: " << state << endl;
    }

    // Stubs

    confirmAnswerToLifeUniverseEverything(42);

    return 0;
}

void sayHelloWorld() {
    cout << "Hello world" << endl;
    cout << "Global int is " << globalInteger << endl;
    cout << "Global char variable default is " << globalChar << endl;
}

int addTwoIntegers(int x, int y) {
    return x + y;
}

double calculateCircleArea(double radius) {
    const double PI=3.14159;
    return PI * pow(radius, 2);
}

double calculatePrismVolume(double length, double width, double height) {
    return length * width * height;
}

void displayName(string firstName, string middleName, string lastName) {
    cout << (middleName.empty() ? firstName + " " + lastName : firstName + " " + middleName + " " + lastName);
    cout << endl;
}

void countIterations() {
    static int counter = 0;
    cout << "Iteration #" << counter++;
}

// %referenceInteger - store updated values of referenceInteger in the variable passed with referenceInteger
void squareInteger(int &referenceInteger) {
    referenceInteger *= referenceInteger;
}

void squareFloat(double& referenceFloat) {
    referenceFloat *= referenceFloat;
}

void sortAscending(int& integer1, int& integer2) {
    int localContainer;
    if (integer1 > integer2) {
        localContainer = integer1;  // container -> integer1 initial location
        integer1 = integer2;        // integer1 -> integer2 location    ***integer1 reassignment***
        integer2 = localContainer;  // integer2 -> container location -> integer1 initial location
    }                               // otherwise, 
}

void readFile(ifstream& file) {
    string line;
    while (file >> line)
        cout << line << (line == "-1" ? "" : ", ");
    cout << endl;
}

bool readFileData(ifstream &file, string &city, string &state) {
    bool foundData = file >> city >> state; // FIXME no suitable conversion function to bool
    return foundData;
}

void squareNumber(int &value) {
    value *= value;
}

void squareNumber(double &value) {
    value *= value;
}

int addIntegers(int a, int b) {
    return a + b;
}

int addIntegers(int a, int b, int c) {
    return a + b + c;
}

int addIntegers(int a, int b, int c, int d) {
    return a + b + c + d;
}

void confirmAnswerToLifeUniverseEverything(int answer) {
    cout << "*** Universe calculation to be implemented ***";
    cout << "Inputs: " << answer;
}