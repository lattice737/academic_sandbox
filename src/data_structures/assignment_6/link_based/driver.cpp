// Programmer:      Nicholas Martinez
// Project number:  6.2
// Project Desc:    Link-based implementation of a list
// Course:          COSC 2436 PF III Data Structures
// Date:            4/28/23

// ArrayList example driver
// This is not a thorough test of the class, but it exercises all class methods.

#include "LinkedList.h" // ADT list operations
#include <iostream>
#include <string>

using namespace std;

void displayList(ListInterface<string>* listPtr, bool copy=false)
{
	if (listPtr->isEmpty())
		cout << "The list " << (copy ? "copy " : "") << "is empty" << endl;
	else {
		cout << "The list " << (copy ? "copy " : "") << "contains: ";
		for (int pos = 1; pos <= listPtr->getLength(); pos++)
			cout << "\"" << listPtr->getEntry(pos) << "\"" << (pos == listPtr->getLength() ? " " : ", ");
		cout << endl;
	}
}

void testCopyConstructor() {
    LinkedList<string>* listPointer = new LinkedList<string>();

	cout << "Testing copy constructor: Creating a list with 3 entries" << endl;

    listPointer->insert(1, "Simplex");
    listPointer->insert(2, "Polytope");
    listPointer->insert(3, "Manifold");

    displayList(listPointer);

	cout << "\nCopying list" << endl;

    LinkedList<string>* listPointerCopy = new LinkedList<string>(*listPointer);

    displayList(listPointerCopy, true);

    if (listPointerCopy->remove(1)) cout << "\nFirst entry removed from list copy";
    if (listPointerCopy->insert(2, "Hull")) cout << "\nInserted \"Hull\" to position 2 into list copy";
    if (listPointerCopy->insert(4, "Node")) cout << "\nInserted \"Node\" to position 4 into list copy";

    cout << "\nLength of first list " << (listPointer->getLength() == listPointerCopy->getLength() ? "is" : "is not") << " equal to copy of list; should not be equal";

	bool match;
	for (int i=1; i<listPointer->getLength(); i++) {
		try {
			match = listPointer->getEntry(i) == listPointerCopy->getEntry(i);
		} catch (PrecondViolatedExcep exception) {
			match = false;
		}
		if (!match) break;
	}

	cout << "\nLists contents " << (match ? "match" : "do not match") << "; should not match" << endl << endl;

	displayList(listPointer);
	displayList(listPointerCopy, true);

	cout << "\nDestroying these lists" << endl << endl;

	delete listPointer;
	listPointer = nullptr;
	delete listPointerCopy;
	listPointerCopy = nullptr;

    return;
}



int main()
{
	// Test copy constructor
	testCopyConstructor();

	// Test list methods

	ListInterface<string>* listPtr = new LinkedList<string>();

	cout << "Making new list; list should be empty" << endl;;
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;
	
	// Test insert()

	listPtr->insert(1, "two");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 1" << endl << endl;	
	
	listPtr->insert(1, "one");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 2" << endl << endl;		
	
	listPtr->insert(3, "three");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 3" << endl << endl;	
	
	listPtr->insert(3, "two.five");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 4" << endl << endl;	
	
	listPtr->insert(5, "five");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 5" << endl << endl;
	
	// Test replace

	// Test valid replacement position
	cout << "Replacing position 5 entry with \"forty-two\"";
	listPtr->replace(5, "forty-two");
	cout << "\nPosition 5 after replacement has entry : \"" << listPtr->getEntry(5) << "\"; should be \"forty-two\"" << endl;
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 5" << endl << endl;

	// Test invalid replacement position
	cout << "Replacing position 10 entry with \"twenty-one\"";
	try {
		listPtr->replace(10, "twenty-one");
	} catch (PrecondViolatedExcep except) {
		cout << "\nPrecondition exception caught when attempting to replace entry at illegal position 10; exception should be caught" << endl;
	}
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 5" << endl << endl;

	// Linked implementation does not have a fixed size, so no need to test for full List
	/*
	cout << "List should be full; next insert should fail" << endl;
	if (listPtr->insert(6, "six"))
         cout << "Inserted \"six\" at position 6" << endl;
    else
         cout << "Cannot insert \"six\" at position 6" << endl;
    displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 5" << endl << endl;
	*/

	// Test remove()
	
	cout << "Remove first entry" << endl;
	listPtr->remove(1);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 4" << endl << endl;
	
	cout << "Remove last entry" << endl;
	listPtr->remove(4);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 3" << endl << endl;
	
	cout << "Remove remaining entries" << endl;
	listPtr->remove(1);
	listPtr->remove(1);
	listPtr->remove(1);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;

	cout << "Try to remove entry from empty list" << endl;
	if (listPtr->remove(1))
         cout << "Removed an entry" << endl << endl;
    else
         cout << "Cannot remove entry" << endl << endl;
	
	// Test contains()

	cout << "Inserting one" << endl;
	listPtr->insert(1, "one");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 1" << endl << endl;		
	
	cout << "Inserting two" << endl;
	listPtr->insert(2, "two");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 2" << endl << endl;

	// Test for entry that should be in list
	cout << "Testing list for entry \"two\"" << endl;
	cout << "List " << (listPtr->contains("two") ? "contains" : "does not contain") << " \"two\"; should contain" << endl << endl;

	// Test for entry that should not be in list
	cout << "Testing list for entry \"C++\"" << endl; 
	cout << "List " << (listPtr->contains("C++") ? "contains" : "does not contain") << " \"C++\"; should not contain" << endl << endl;

	// Test clear()

	cout << "Clearing list" << endl;
	listPtr->clear();
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;	

	return 0;
}  // end main