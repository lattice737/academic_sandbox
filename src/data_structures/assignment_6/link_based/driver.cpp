

// ArrayList example driver
// This is not a thorough test of the class, but it exercises all class methods.

#include "LinkedList.h" // ADT list operations
#include <iostream>
#include <string>

using namespace std;

void displayList(ListInterface<string>* listPtr)
{
	if (listPtr->isEmpty())
		cout << "The list is empty" << endl;
	else {
		cout << "The list contains " << endl;
		for (int pos = 1; pos <= listPtr->getLength(); pos++)
			cout << listPtr->getEntry(pos) << " ";
		cout << endl;
	}
}

void testCopyConstructor() {
    ListInterface<string>* listPointer = new LinkedList<string>();

    listPointer->insert(0, "Simplex");
    listPointer->insert(1, "Polytope");
    listPointer->insert(2, "Manifold");

    displayList(listPointer);

    ListInterface<string>* listPointerCopy = listPointer;

    displayList(listPointerCopy);

    listPointer->remove(1);
    listPointer->insert(2, "Convex Hull");

    displayList(listPointer);
    displayList(listPointerCopy);

    return;
}



int main()
{
	// Test copy constructor
	testCopyConstructor();

	// Test list methods

	ListInterface<string>* listPtr = new LinkedList<string>();

	cout << "List should be empty" << endl;;
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
	listPtr->replace(5, "forty-two");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 5" << endl << endl;
	cout << "Position 5 has entry : " << listPtr->getEntry(5) << "; should be \"forty-two\"" << endl << endl;

	// Test invalid replacement position
	listPtr->replace(10, "twenty-one");
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