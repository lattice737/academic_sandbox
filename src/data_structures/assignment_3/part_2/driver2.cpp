// Programmer:      Nicholas Martinez
// Project number:  3.2
// Project Desc:    Array-based implementation of a set
// Course:          COSC 2436 PF III Data Structures
// Date:            2/15/23

#include <iostream>
#include <string>
#include "ArraySet.h"
using namespace std;

void display(ArraySet<string>&);
void display(ArraySet<int>&);

int main()
{
	ArraySet<string> set;
	cout << "Testing array-based set:" << endl;
	cout << "The initial set is empty." << endl;
	cout << "isEmpty: returns " << set.isEmpty() 
         << "; should be 1 (true)" << endl;
	display(set);

	string items[] = {"one", "two", "three", "four", "one"};
	cout << "Add 5 items (1 duplicate) to the set: " << endl;
	for (int i = 0; i < 5; i++)
	{
		set.add(items[i]);
	}  // end for
   
    display(set);
    
    // Test adding duplicates
    cout << "add(\"three\"): returns " << set.add("three")
         << "; should be 0 (false)" << endl;

    cout << "isEmpty: returns " << set.isEmpty() 
         << "; should be 0 (false)" << endl;        
    cout << "getCurrentSize: returns " << set.getCurrentSize() 
         << "; should be 4" << endl;    
    cout << "contains(\"three\"): returns " << set.contains("three")
         << "; should be 1 (true)" << endl;
    cout << "remove(\"two\"): returns " << set.remove("two")
         << "; should be 1 (true)" << endl;
    cout << "remove(\"two\"): returns " << set.remove("two")
         << "; should be 0 (false)" << endl;
    cout << endl;
    
    display(set);
    
    cout << "After clearing the set, ";
    set.clear();
    
    cout << "isEmpty: returns " << set.isEmpty()
            << "; should be 1 (true)" << endl;

    // Test initialization

    int numbers[] = {6, 7, 8, 9, 9, 10, 11, 12};
    ArraySet<int> integerSet(numbers, 7);
    cout << "ArraySet has been initialized with a seven-element array with 1 duplicate" << endl;
    cout << "getCurrentSize: returns " << integerSet.getCurrentSize()
         << "; should be 6" << endl;

    display(integerSet);

    cout << "contains(2): returns " << integerSet.contains(2)
         << right << "; should be 0 (false)" << endl;
    
    return 0;
}   // end main

void display(ArraySet<string>& set)
{
	cout << "The set contains " << set.getCurrentSize()
        << " items:" << endl;
    vector<string> setItems = set.toVector();
    
    int numberOfEntries = static_cast<int>(setItems.size());
    cout << "{ ";
    for (int i = 0; i < numberOfEntries; i++)
    {
        cout << "\"" << setItems[i] << "\", ";
    }  // end for
        cout << "}";
        cout << endl << endl;
}  // end displayset

void display(ArraySet<int>& set)
{
	cout << "The set contains " << set.getCurrentSize()
        << " items:" << endl;
    vector<int> setItems = set.toVector();
    
    int numberOfEntries = static_cast<int>(setItems.size());
    cout << "{ ";
    for (int i = 0; i < numberOfEntries; i++)
    {
        cout << "" << setItems[i] << ", ";
    }  // end for
        cout << "}";
        cout << endl << endl;
}  // end displayset
