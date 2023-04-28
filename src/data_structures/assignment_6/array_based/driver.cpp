#include "ArrayList.h"
#include <iostream>
#include <string>

using namespace std;

void displayList(ListInterface<string>* listPtr) {

    cout << endl << "The list contains: ";

    for (int pos = 1; pos <= listPtr->getLength(); pos++) {
        try{
            cout << "\"" << listPtr->getEntry(pos) << "\"" << (pos == listPtr->getLength() ? "" : ", ");
        } catch(PrecondViolatedExcep except) {
            cout << "Exception thrown getting entry inserted at position " << pos << endl;
            cout << except.what() << endl;
        }
    }

	cout << endl << endl;
}

bool sequencesMatch(ListInterface<string>* listPointer, string expectedEntries[], int expectedSize) {
    bool sameSize = listPointer->getLength() == expectedSize;
    
    if (!sameSize) return false;
    
    for (int i=1; i<=expectedSize; i++)
        if (listPointer->getEntry(i) != expectedEntries[i-1]) return false; 
    
    return true;
}

bool testIsEmpty(ListInterface<string>* listPointer, bool expected) {
    bool passed = listPointer->isEmpty() == expected;
    cout << "isEmpty() test " << (passed ? "passed" : "failed") << endl;
    return passed;
}

bool testInsert(ListInterface<string>* listPointer, int position, string entry, bool expected) {
    bool passed = listPointer->insert(position, entry) == expected;
    cout << "insert(" << position << ", \"" << entry << "\") test " << (passed ? "passed" : "failed") << endl;
    return passed;
}

bool testGetLength(ListInterface<string>* listPointer, int size, bool expected) {
    bool passed = (listPointer->getLength() == size) == expected;
    cout << "getLength() test " << (passed ? "passed" : "failed") << endl;
    return passed;
}

bool testGetEntry(ListInterface<string>* listPointer, int position, string entry, bool expected) {
    bool result,
         exception = false;
    try {
        result = listPointer->getEntry(position) == entry;
    } catch (PrecondViolatedExcep except) {
        result = false;
        exception = true;
    }
    cout << "getEntry(" << position << ") test " << (result == expected ? "passed" : "failed") << (exception ? " with precondition exception" : "") << endl;
    return result == expected;
}

bool testReplace(ListInterface<string>* listPointer, int position, string newEntry, bool expected) {
    bool result = true,
         exception = false;
    try {
        listPointer->replace(position, newEntry);
    } catch (PrecondViolatedExcep except) {
        result = listPointer->getEntry(position) == newEntry;
    }
    cout << "replace(" << position << ", \"" << newEntry << "\") test " << (result == expected ? "passed" : "failed") << (exception ? " with precondition exception" : "") << endl;
    return result == expected;
}

bool testRemove(ListInterface<string>* listPointer, int position, bool expected) {
    bool passed = listPointer->remove(position) == expected;
    cout << "remove(" << position << ") test " << (passed ? "passed" : "failed") << endl;
    return passed;
}

bool testClear(ListInterface<string>* listPointer, bool expected) {
    listPointer->clear();
    bool passed = listPointer->isEmpty() == expected;
    cout << "clear() test " << (passed ? "passed" : "failed") << endl;
    return passed;
}

bool testContains(ListInterface<string>* listPointer, string entry, bool expected) {
    bool passed = listPointer->contains(entry) == expected;
    cout << "contains(\"" << entry << "\") test " << (passed ? "passed" : "failed") << endl;
    return passed;
}

int main() {
    const int NUM_TESTS=23;
    ListInterface<string>* listPtr = new ArrayList<string>();
    bool expected;
    int passed = 0;
    
    cout << "Testing the Array-Based List:\n" << endl;
        
    string data[] = {"one", "two", "three", "four", "five", "six"};

    // Test empty list

    passed += testIsEmpty(listPtr, true);
    
    // Test insert operation - one illegal insertion

    for (int i=0; i<6; i++) {
        expected = data[i] != "six" ? true : false;
        passed += testInsert(listPtr, i+1, data[i], expected);
        passed += testGetEntry(listPtr, i+1, data[i], expected);
    }

    displayList(listPtr);

    // Test nonzero length and replace operation
    
    passed += testIsEmpty(listPtr, false);
    passed += testGetLength(listPtr, 5, true);
    passed += testReplace(listPtr, 3, "XXX", true);

    displayList(listPtr);

    // Test remove operation

    passed += testRemove(listPtr, 2, true);
    passed += testRemove(listPtr, 1, true);
    passed += testRemove(listPtr, 6, false);

    displayList(listPtr);

    // Test entry finder and clear operation

    passed += testContains(listPtr, "XXX", true);
    passed += testContains(listPtr, "C++", false);
    passed += testClear(listPtr, true);
    passed += testGetEntry(listPtr, 6, "dummy", false);  // Exception case

    // Display test suite results

    if (passed == NUM_TESTS)
        cout << endl << "All tests passed.";
    else
        cout << endl << passed << '/' << NUM_TESTS << " passed.";
    
    return 0;
}

/*
 Testing the Array-Based List:
 isEmpty: returns 1; should be 1 (true)
 Inserted one at position 1
 Inserted two at position 2
 Inserted three at position 3
 Inserted four at position 4
 Inserted five at position 5
 Cannot insert six at position 6
 The list contains 
 one two three four five 
 isEmpty: returns 0; should be 0 (false)
 getLength returns : 5; should be 5
 The entry at position 4 is four; should be four
 After replacing the entry at position 3 with XXX: The list contains 
 one two XXX four five 
 remove(2): returns 1; should be 1 (true)
 remove(1): returns 1; should be 1 (true)
 remove(6): returns 0; should be 0 (false)
 The list contains 
 XXX four five 
 clear: 
 isEmpty: returns 1; should be 1 (true)
 Attempt an illegal retrieval from position 6: 
 Precondition Violated Exception: getEntry() called with an empty list or invalid position.
 
*/