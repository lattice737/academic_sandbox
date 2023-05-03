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

void addIntegers(int array[], int size) {
    for (int i=0; i<size; i++)
        array[i] = i + rand();
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
    const int N=25;
    int integers[N],
        first=0,
        last=N-1;
    string strings[N];

    addIntegers(integers, N);
    addStrings(strings, N);

    // Sort integer array

    cout << "Sorting list of " << (last-first+1) << " integers:" << endl;
    displayArray(integers, N);

    quickSort(integers, first, last);

    displayArray(integers, N);

    // Sort string array

    cout << "Sorting list of " << (last-first+1) << " strings:" << endl;
    displayArray(strings, N);

    quickSort(strings, first, last);

    displayArray(strings, N);


    return 0;
}