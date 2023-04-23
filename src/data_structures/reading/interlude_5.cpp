#include<iostream>
#include<string>
#include<cassert>
#include<stdexcept>

using namespace std;

/*
Vocabulary
==========
* Inheritance - a relationship between classes where a class derives properties from another, previously defined class
* Derived class - a class that inherits all the members of its base class, except the constructors and destructors
* Multiple inheritance - a relationship between classes where a class is derived from more than one base class
* Static binding (or early binding) - compiler determination of which form of an instance's method to use at compilation
  time, based on the class's relationship to other classes (prioritizing the base class)
* Dynamic binding (or late binding) - compiler determination of which form of an instance's method to use at runtime,
  based on the class's relationship to other classes
* Polymorphic method - a method with an outcome dependent on the objects on which the operation acts
* Overriding method - a virtual method in a derived class with the same declaration as an ancestor's virtual method
* Protected section - class members that are hidden from the client but are available to derived classes
* Is-a relationship (or public inheritance) - class implementations characterized by object type compatibility;
  "<subclass> is a <parent class>"
* Object type compatibility - a feature where whatever is true of the base class is also true of its derived classes
* As-a relationship (or private inheritance) - class implementations where public inheritance (and therefore object type
  compatibility) is inappropriate but a subclass requires access to another class's protected members or redefinition
  of another class's methods; "<subclass> is implemented as a <parent class>"
* Has-a relationship (or containment) - class implementations where another class is implemented but not inherited;
  "<class A> has a <class B>"
* Composition - an instance that exist independently of a containing class
* Aggregation - A form of containment where the contained item can exist independently of the containing class
* Abstract base class - a class that contains at least one pure virtual method that has no implementation
* 

General
=======
~ Multiple inheritance must be used with care, since it's possible for the base classes to have similarly named methods
~ Generally, if multiple inheritance is used, the derived class inherits code from only one base class, and any other
  base classes should be abstract base classes
~ As many new members can be added to a derived class as are needed
~ A method in a derived class redfines a nonvirtual method in the base class if the two methods have the same name and
  parameter declarations
~ A derived class cannot access the private members of the base class directly by name, even though they are inherited
~ Only virtual methods can be overridden, but the `virtual` keyword can be omitted in the derived class (although it,
  in combination with the `override` keyword, makes the implementation more legible)
~ The `final` keyword prevents method overriding (e.g. `void setItem(const ItemType& theItem) override final`)
~ As a general stylistic guideline for information hiding and keeping derived classes from coupling directly to base
  class data members, all data members of a class should be private; if needed, indirect access can be implemented by
  defining accessor or mutator methods that are public or protected
~ Public inheritance is the most important type of inheritance, used to extend the definition of a class
~ In general, a derived class is type-compatible with all of its ancestor classes, where an instance of a derived class
  can be used instead of a base class instance, but not vice-versa
~ Inheritances:
  1) Public inheritance: public and protected members of the base class remain, respectively, public and protected
     members of the derived class
  2) Protected inheritance: public and protected members of the base class are protected members of the derived class
  3) Private inheritance: public and protected members of the base class are private members of the derived class
~ Class relationship best practices:
  1) Favor containment over inheritance
  2) Use public inheritance when an is-a relationship exists
  3) Use private inheritance when you want to reuse a part of another class's implementation
~ Class constructor execution order:
  1) Base class constructor
  2) Member objects (in order of declaration)
  3) Constructor body
~ Class destructor execution order:
  1) Destructor body
  2) Member objects (in order of declaration)
  3) Base class destructor
~ An abstract base class cannot have instances and only serves as the basis of other classes
~ Any derived class that fails to implement all of the pure virtual methods of an ABC is also an abstract base class
~ An abstract base class can provide a constructor, but it cannot be pure, because constructors cannot be virtual
~ Abstract base class destructors should not be pure, because derived classes will call it; they should be implemented,
  even if simply having empty bodies--virtual destructors are recommended
~ An abstract base class is ideal for specifying an abstract data type; by defining an ADT's public interface as pure
  virtual methods, the ABC requires derived classes to implement them, ensuring a commmon interface across
  implementations
~ Abstract base classes must implement any virtual method that is not pure, providing a default implementation if a
  derived class does not supply its own
*/

int main() {
    return 0;
}