#include "ArrayList.h"
#include <stdexcept>
#include <iostream>
#include <string>

const int ITEM_COUNT = 6;

int main() {
    ListInterface<string>* listPtr = new ArrayList<string>();
    string data[] = {"one", "two", "three", "four", "five", "six"};
    
    cout << "isEmpty: returns " << (listPtr->isEmpty() ? "true" : "false") << "; should be true" << endl;

    for (int i=0; i<ITEM_COUNT; i++) {
        if (listPtr->insert(i+1, data[i])) {
            try {
                cout << "Inserted " << listPtr->getEntry(i+1) << " at position " << i+1 << endl;
            } catch (logic_error exception) {
                cout << "Failed to get entry at position " << i+1 << endl;
            }
        } else
            cout << "Cannot insert " << data[i] << " at position " << i+1 << endl;
    }
    return 0;
}