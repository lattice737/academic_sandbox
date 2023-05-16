//� Created by Frank M. Carrano and Timothy M. Henry.
//� Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
//#include "ArrayDictionary.h"
#include "HashedDictionary.h"
//#include "TreeDictionary.h"


void display1(std::string& anItem);
void display2(int& anItem);
void dictionaryTest1(HashedDictionary<int, std::string>* testDictionary);


int main()
{

   std::cout << "Testing HashedDictionary" << std::endl << std::endl ;
   HashedDictionary<int, std::string>* dict1 = new HashedDictionary<int, std::string>();
   dictionaryTest1(dict1);
   
   return 0;
}  // end main

void display1(std::string& anItem)
{
   std::cout << "Displaying item - " << anItem << std::endl;
}  // end display1

void display2(int& anItem)
{
   std::cout << "Displaying item - " << anItem << std::endl;
}  // end display2

void dictionaryTest1(HashedDictionary<int, std::string>* testDictionary)
{
   testDictionary->add(6, "F");
   testDictionary->add(7, "G");
   testDictionary->add(4, "D");
   testDictionary->add(8, "H");
   testDictionary->add(3, "C");
   testDictionary->add(5, "E");
   testDictionary->add(1, "A");
   testDictionary->add(2, "B");
   testDictionary->add(27, "AA");
   testDictionary->add(26, "Z");
   testDictionary->add(20, "T");
   testDictionary->add(21, "U");
   testDictionary->add(22, "V");
   testDictionary->add(53, "AAA");
   std::cout << std::endl;
   
   testDictionary->remove(1);
   testDictionary->remove(8);
   testDictionary->remove(4);
   
   std::cout << "\nTrying to remove 4/D again\n";
   if (testDictionary->remove(4))
      std::cout << "Removed second 4 :-(\n\n";
   else
      std::cout << "Could not remove second 4 :-)\n\n";
   
   std::cout << "Getting key/item 2/B: "<< testDictionary->getItem(2) << std::endl;
   
   std::cout << "Getting key/item 7/G: "<< testDictionary->getItem(7) << std::endl;
   
   std::cout << "Getting key/item 5/E: "<< testDictionary->getItem(5) << std::endl;
   
   std::cout << "Contains key/item 8/H: "<< testDictionary->contains(8) << std::endl;
   
   std::cout << "Contains key/item 0/??: "<< testDictionary->contains(0) << std::endl;
   
   testDictionary->clear();
   
   std::cout << "\nTrying to traverse after clear\n";
   testDictionary->traverse(display1);
   std::cout << "If nothing displayed, that is good!\n";
   
   if (testDictionary->remove(20))
      std::cout << "Removed 20 from an empty dictionary :-(\n\n";
   else
      std::cout << "Could not remove 20 from an empty dictionary :-)\n\n";   
}  // end dictionaryTest1


/*
 Testing ArrayDictionary
 
 Traversing data items in sorted search-key order:
 Displaying item - A
 Displaying item - B
 Displaying item - C
 Displaying item - D
 Displaying item - E
 Displaying item - F
 Displaying item - G
 Displaying item - H
 
 After Removing 10/A, 40/D & 80/H, traverse data items in sorted search-key order:
 Displaying item - B
 Displaying item - C
 Displaying item - E
 Displaying item - F
 Displaying item - G
 
 Trying to remove 40/D again
 Could not remove second 40 :-)
 
 Getting key/item 20/B: B
 Getting key/item 70/G: G
 Getting key/item 50/E: E
 Contains key/item 80/H: 0
 Contains key/item 00/??: 0
 
 Trying to traverse after clear
 If nothing displayed, that is good!
 Could not remove 20 from an empty dictionary :-)

*/

