// Chapter 7 Concepts

#include<iostream>
#include<string>
#include"Class.h"

using namespace std;

/*
Vocabulary
==========
* Abstract data type - a custom data type that specifies storable values and possible operations on those values without details
  about implementation; usually implemented as classes
* Abstraction - a model of something that includes general characteristics without specific instance details
* Procedural programming - a method of software development centered on the functions (or procedures) that carry out program tasks;
  the program's data (e.g. variables) is usually kept separate from these procedures, where values must be passed to the functions
* Object-oriented programming - a method of software development centered on creating and using objects to structure data and
  operations on that data
* Object - a software entity that combine both data and the procedures that work with it into a single unit
* Member variables (or attributes) - an object's data items
* Member functions (or methods) - the procedures that an object performs
* Encapsulation - the bundling of associated data and procedures with an object
* Data hiding - an object's ability to conceal its data from code accessing the object
* Class - a programmer-defined data type that describes what objects of the class will look like when they are created
* Access specifiers - designate the scope of access to certain class members--private for access only between member functions,
  public for access by functions outside the class; default (unnamed) is private
* Instance - an object created from a declared class
* Accessor (or get/getter function)- a member function that uses the value of a class variable but does not change it
* Mutator (or set/setter function) - a member function that stores or updates a value in a class variable
* Inline function - a member function defined within a class declaration
* Function implementation section - a sequence of function definitions that follow a class declaration
* Scope resolution operator (::) - indicates that a function is a member function for a specified class--required when a function
  is defined outside the class declaration
* Stale data - values that are dependent on other data but are not updated when the other data is updated
* Stack - a section of memory where items such as the return address and argument values are stored for a function call
* Inline expansion - the process for an inline function call, where the compiler replaces every call to the function with the
  actual function body statements in the program
* Constructor - a special public member function automatically called to produce a class object when used
* Default constructor - a constructor with no parameters
* Member initialization list - a list of member variable names with their initial values, appearing after the constructor heading
  and before the opening brace of the body; it contains the name of each variable to be initialized, followed by its initial value
  enclosed in parentheses
* In-place initialization - Initialization of member variables when they are defined in a class declaration
* Constructor delegation - a constructor's call to another constructor in a class
* Destructor - a member function that performs shutdown procedures when an object is destroyed, preceded with a tilde
* Constant reference - an object reference passed to a function that is unable to call the object's mutator functions or change the
  object's member data--only accessor functions designated as constant functions can be called
* Object composition - the use of one programmer-defined type within the class declaration of another
* Class specification file - a header file that contains a class declaration, usually with filename Class.h
* Class implementation file - a file containing a class's member function definitions, usually with filename Class.cpp
* Client program (or code) - the application program that runs the main function
* Include guard (#ifndef & #endif) - prevents the header file from being included more than once
* Include file directory - the directory containing all standard C++ header files
* Structure - a programmer-defined data type that can hold many different data values
* Initialization list - a list of values used to initialize a set of memory locations for a structure's data members 
* 

General
=======
~ As programs become larger and more complex, procedural programming's separation of a program's data and its operating code require
  major refactoring that introduces bug opportunities when program specifications change
~ Objects typically hide their data but allow outside code to access it using its member functions
~ Benefits of data hiding:
  1) Protection of data from accidental or intentional corruption
  2) Updates to the object's internal data will not require outside code refactoring
~ Class member functions can be defined either inside or outside the class declaration
~ For longer member functions, place a function prototype within the class declaration and define the function outside the class
  definition
~ When designing a class, best practice is not to use a member variable to store a calculated value that could potentially become
  stale
~ Inline functions increase the size of a program, and if the function is too large for practical inline expansion, the compiler will
  ignore it; however, small functions improve performance by omitting the overhead of a conventional function call
~ C++ automatically provides a constructor, but programmers usually develop custom constructors to initialize an object's member variables
~ When an object is defined using a default constructor, there must not be any parentheses (e.g. "Triangle triangleVariable;")
~ Best practice is to implement a default constructor
~ A colon at the end of a member function header indicates that a member initialization list follows
~ There must not be a semicolon after a member initialization list
~ When a constructor has a member initialization list, the initializations take place befor execution of any statements in the body
~ Member initialization lists are usually preferred because it can allow the compiler to generate more efficient code
~ Destructor characteristics:
  1) Have no return type
  2) Have no parameter list (cannot pass arguments)
  3) May only be defined once
~ Destructors are most useful when working with dynamically allocated objects
~ Passing an object by value requires making copies of all an object's members, which can slow down a program's execution when an object
  has many members; since passing by reference accesses objects directly, it's generally preferable to pass objects by reference
~ Objects passed by reference allow for member data alteration via their mutator functions, but they can be protected when passed as
  constant references
~ Class implementation files should be compiled and linked with the client program--`project` or `make` utilities automate this
~ "ifndef" = "if not defined"
~ An include guard checks for the existence of a constant CLASS_H and either defines it if it has not yet been defined or skips the
  reading of the file
~ When including a C++ system header file, the filename is enclosed in angled brackets, to indicate that it's located in the compiler's
  include file directory; header files located in the current project directory are enclosed in double quotes
~ Separate compilation:
  1) Compile Class.cpp -> Class.obj
  2) Compile driver.cpp -> driver.obj
  3) Link driver.obj & Class.obj -> driver.exe
~ Best practices:
  1) Separating client code from class details
      a) knowledge of implementation not needed for use
      b) class implementation does not need to be explicitly added to client code
  2) Separating class specification and implementation into distinct files
      a) only specification file & compiled implementation file are needed
      b) avoid implementation modification that may introduce bugs
      c) class modification does not require recompilation of client programs
  3) Avoiding cin & cout in member functions
      a) Client code is not constrained to a specific I/O implementation
      b) Provide getters without displaying them
      c) Provide setters without using cin
~ A class is an example of an abstract data type
~ Structure characteristics:
  1) struct keyword
  2) Only declares member variables--rarely include member functions
  3) Access specifiers not usually included
  4) Default to public access
~ Structure data members are accessed directly and can be used like regular variables
~ Structures cannot be compared with relational operators
~ Structure members cannot be initialized in the declaration; no member variables are created in memory until the structure
  is instantiated--there's no place to store an initial value during declaration
~ Structure initialization list drawbacks:
  1) cannot omit initialization of members between initialized members (e.g. "Structure myStructure = {member1, , member3}"")
  2) cannot include objects (e.g. strings) for many compilers
~ Best practice is to pass structures to functions by constant reference
~ By packaging multiple values inside a class or structure, more than one value can be returned from a function
~ 
*/

// Simple class

class Circle {
    private:
        const double PI=3.14159; // in-place initialization - C++11<
        double radius;
    public:
        void setRadius(double r) {radius = r;};
        double getRadius() {return radius;};
        double getArea(double r) {return PI * r * r;};
};

// Inline member function class

class Rectangle {
    private:
        double length;
        double width;
    public:
        void setLength(double);
        void setWidth(double);
        double getLength();
        double getWidth();
        double getArea();
};

void Rectangle::setLength(double newLength) {
    length = newLength > 0.0 ? newLength : 1.0;
}
void Rectangle::setWidth(double newWidth) {
    width = newWidth > 0.0 ? newWidth : 1.0;
}
double Rectangle::getLength() {
    return length;
}
double Rectangle::getWidth() {
    return width;
}
double Rectangle::getArea() {
    return length * width;
}

// Overloaded constructor class

class Triangle {
    private:
        double base;
        double height;
    public:
        Triangle(double newBase=1.0, double newHeight=1.0);
        void setBase(double);
        void setHeight(double);
        double getBase();
        double getHeight();
        double getArea();
};

Triangle::Triangle(double newBase, double newHeight) {
    base = newBase > 0.0 ? newBase : 1.0;
    height = newHeight > 0.0 ? newHeight : 1.0;
}
void Triangle::setBase(double newBase) {
    base = newBase > 0.0 ? newBase : height;
}
void Triangle::setHeight(double newHeight) {
    height = newHeight > 0.0 ? newHeight : height;
}
double Triangle::getBase() {
    return base;
}
double Triangle::getHeight() {
    return height;
}
double Triangle::getArea() {
    return 0.5 * base * height;
}

// Constructor member initialization list class

class Line {
    private:
        double length;
    public:
        Line() : length(1.0) {} // constructor definition - no semicolon
        Line(double);           // constructor declaration
        void setLength(double);
        double getLength();
};

Line::Line(double newLength) : length(newLength > 0.0 ? newLength : length) {} // Line(double) definition

void Line::setLength(double newLength) {
    length = newLength > 0.0 ? newLength : length;
}
double Line::getLength() {
    return length;
}

// Constructor delegation class with destructor

class Contact {
    private:
        string name;
        string email;
        string phone;
    public:
        Contact() : Contact("", "", "") {} // this constructor calls the following constructor
        Contact(string newName, string newEmail, string newPhone) {
            name = newName;
            email = newEmail;
            phone = newPhone;
        }
        ~Contact();
};

Contact::~Contact() {}

// Passing by constant reference class

class Cat {
    private:
        bool fed;
    public:
        Cat() : Cat(false) {}
        Cat(bool givenFood) {fed = givenFood;}
        void setFed(bool&);
        bool getFed() const; // only constant functions can be called by objects passed by constant reference
};

void Cat::setFed(bool& givenFood) {
    fed = givenFood;
}

bool Cat::getFed() const {
    return fed;
}

// Structures

struct Payroll {
    int employeeNumber;
    string name;
    double hours,
           payRate,
           grossPay;
};

struct Date {
    int day,
        month,
        year;
};

struct Light {
    string color;
    int lumens;
    Date dateOfPurchase;
    Light(string c="white", int l=800, Date p={2, 2, 2023}) { // constructor to initialize members
        color = c;
        lumens = l;
        dateOfPurchase = p;
    };
};

// Main function

void feedCat(const Cat&);

int main() {
    Date birthday = {11, 25, 1996}; // Structure definition - maps to order of initialized members
    Date christmas = {12, 25};      // Incomplete structure definition
    Light basic;

    return 0;
}

void feedCat(const Cat& cat) {
    cout << (cat.getFed() ? "Cat is already fed" : "Feeding cat") << endl;
}