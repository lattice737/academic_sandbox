// Programmer:      Nicholas Martinez
// Project number:  8
// Project Desc:    Sorting algorithms
// Course:          COSC 2436 PF III Data Structures
// Date:            5//23

#include "quickSort.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string PATH="/Users/nicholas/academic_sandbox/src/data_structures/assignment_8/";

int* getIntegerArray(int size) {
    int array[size];
    int randomInt;
    for(int i = 0; i < size; i++)
        array[i] = rand() % 10;
}

void addStrings(string array[], int size) {
    string filename = PATH+"titanic.dat",
           name;
    fstream names(filename, ios::in);
    int i = 0;

    if (names.fail()) throw("\nCould not open file " + filename);

    while (names >> name)
        array[i++] = name;
}

void displayArray(int array[], int size) {
    for (int i=0; i<size; i++)
        cout << array[i] << (i+1 == size ? "\n" : ", ");
}

void displayArray(string array[], int size) {
    for (int i=0; i<size; i++)
        cout << array[i] << (i+1 == size ? "\n" : ", ");
}

int main() {
    const int MIN_ARRAY_SIZE=25,
              FIRST=0;
    string* strings;
    int* integers;
    int enteredSize,
        last;

    // Sort integer array

    cout << "Enter the size of the test integer array: ";
    cin >> enteredSize;
    last = enteredSize > MIN_ARRAY_SIZE ? enteredSize-1 : MIN_ARRAY_SIZE-1;
    integers = getIntegerArray(last+1);

    cout << "Sorting list of " << (last-FIRST+1) << " integers:" << endl;
    displayArray(integers, last+1);

    quickSort(integers, FIRST, last);
    displayArray(integers, last+1);

    // Sort string array
    
    cout << "Enter the size of the test string array: ";
    cin >> enteredSize;
    last = enteredSize > MIN_ARRAY_SIZE ? enteredSize-1 : MIN_ARRAY_SIZE-1;
    integers = getIntegerArray(last+1);

    cout << "Sorting list of " << (last-FIRST+1) << " strings:" << endl;
    displayArray(strings, last+1);

    quickSort(strings, FIRST, last+1);
    displayArray(strings, last+1);

    return 0;
}