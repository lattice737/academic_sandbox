// Chapter 11 Concepts

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

/*
Vocabulary
==========
* Implicit object parameter - an object pointer (or address) passed by the compiler to every instance member function call in order to
  execute the function through the object; it is accessible through the keyword `this`
* Constant member function - a member function that does not modify the object through which it is called
* Instance members - the data members and member functions that can only be accessed through a specific instance
* Static members - the data members and member functions of a class that don't need to be associated with any specific instance
* Declaration - provides information about the existence and type of a variable or function
* Definition - provides all the information contained in a declaration and additionally causes memory to be allocated for the variable or
  function being defined
* Friend - a function that is not a class member but has access to a class's private members
* Memberwise assignment - using the assignment operator of two like objects, where the lvalue object will have its own values reassigned
  to the rvalue object's member values
* Copy constructor - a special constructor called by the compiler whenever a new object is initialized with the data of another object of
  the same class, a function call receives a value parameter of the same class type, or a function returns an object of the class by value
* Default copy constructor - copies an existing object's member values to a new object via memberwise assignment if a copy constructor
  is not implemented
* Operator overloading - implementation of a different version of an operator to be used for a certain class
* Operator function - a class member function that overloads an operator
* Copy assignment operator - an overloaded implementation of the assignment operator for a class
* 

General
=======
~ By default the compiler provides each member function of a class with an implicit parameter, called `this` that points to the object
  through which the member function is called
~ A member function with a formal parameter with the same identifier as a class member will hide the class member, making it inaccessible
  inside the function; The `this` pointer can be used to make the class member visible
~ The `const` keyword is used with a member function parameter to prevent the function from modifying it; when placed after a member
  function definition's parameter list, it indicates to the compiler that the member function cannot modify the object
~ A function that promises not to modify some parameter may not pass that parameter to another function unless that function also promises
  not to modify it
~ By default, each class instance has its own copy of the class's member variables, separate and distinct from the member variables of
  other objects of the same class
~ Static member variables must be declared inside the class and defined outside of it
~ Static member functions are normally used to work with static member variables of a class and generally should not access any nonstatic
  members of their class
~ Calls to static member functions are usually made by connecting the function name to the class name with the scope resolution operator;
  if any objects of the class are defined, they can also be called with the dot operator
~ Static member functions can be called before any class instances have been create, making them ideal for complex initialization tasks
  that have to be done before instantiation
~ Class data propagation:
  1) Member function definition -> class
  2) Function call -> instances
  3) Non-static local variables -> instance members
~ Classes keep a list of their friends, and only the external functions or classes whose names appear in the list are granted access
~ Best practice is to declare as friends only those functions that must have access to a class's private members
~ Memberwise assignment is an undesirable action for classes with pointer members, where the pointers of new objects will point to the
  same locations of another object's pointers--a programmer-defined copy constructor can ameliorate this behavior by allocating new
  memory for the new object's pointer members
~ A copy constructor must have a single parameter that is a reference to the same class; the parameter should be have keyword const and
  pass arguments by reference
~ Overloaded operators allow for cascaded assignment statements (e.g. a = b = c)
~ Best practice methods for for a class that dynamically allocates memory:
  1) Destructor
  2) Copy constructor
  3) Move constructor
  4) Copy assignment operator
  5) Move assignment operator
~ 
*/

class Person {
    private:
        static bool related;
        string name="John";
        bool alive=true;
        int age;
    public:
        void setAge(int age) {this->age = age;} // exposing attr with this after parameter hides it
        void sayName() const {cout << name << endl;}; // immutable-instance member function
        void getInstanceAddress() {cout << this << endl;}; // accessing implicit object parameter address
        bool isAlive() {return (*this).alive;}; // accessing implicit object parameter attr
        void spellWord(const string& word) { // constant member function
            for (auto ch : word)
                cout << ch << endl;
        }
        static bool isRelated() {return related;};
        static void print(Person person) {cout << "Name: " << person.name << "\nAge: " << person.age << endl;};
};

class Region {
    private:
        static double nationalBudget;
        double regionalBudget;
    public:
        Region(): regionalBudget(0.0) {}
        Region(double regionalBudget) {(*this).regionalBudget = regionalBudget;}
        double getRegionalBudget() const {return regionalBudget;};
        void addRegionalBudget(double amount) {regionalBudget += amount; nationalBudget += regionalBudget;};
        friend void Territory::addTerritoryBudget(double);
};

// Territory is within region but considered distinct
class Territory {
    private:
        double territoryBudget;
    public:
        Territory(): territoryBudget(0.0) {}
        Territory(double territoryBudget) {(*this).territoryBudget = territoryBudget;}
        double getTerritoryBudget() const {return territoryBudget;};
        void addTerritoryBudget(double amount) {territoryBudget += amount; Region::nationalBudget += territoryBudget;};
};

class NumberArray {
    private:
        double *pointer;
        int size;
    public:
        NumberArray& operator=(const NumberArray& right); // overloaded operator
        NumberArray(const NumberArray&);
        NumberArray(int size, double value);
        ~NumberArray() { if (size>0) delete [] pointer;}
        void print() const;
        void setValue(double value);
};
NumberArray& NumberArray::operator=(const NumberArray& right) {
    if (this == &right)
        return *this;

    if (size > 0)
        delete [] pointer;
    
    size = right.size;
    pointer = new double[size];
    
    for (int i=0; i<size; i++)
        pointer[i] = right.pointer[i];
}


int main() {
    Person someone = Person();

    // Static members
    cout << Person::isRelated() << endl;
    cout << someone.isRelated() << endl;
    Person::print(someone);

    // Assignment operator overloading
    NumberArray left(3, 10.5);
    NumberArray right(5, 20.5);

    left.operator=(right); // explicit call of overloaded function
    left = right; // implicit call of overloaded function

    //

    return 0;
}