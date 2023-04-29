// Programmer:      Nicholas Martinez
// Project number:  8
// Project Desc:    Sorting algorithms
// Course:          COSC 2436 PF III Data Structures
// Date:            5//23

#include "insertionSort.h"
#include "quickSort.h"
#include <string>
#include <fstream>

using namespace std;

void addIntegers(int array[], int size) {
    for (int i=0; i<size; i++)
        array[i] = i + rand();
}

void addStrings(string array[], int size) {
    const string PATH="/Users/nicholas/academic_sandbox/src/data_structures/assignment_8/";
    string filename = PATH+"titanic.dat",
           name;
    fstream names(filename, ios::in);
    int i = 0;

    if (names.fail()) throw("\nCould not open file " + filename);

    while (names >> name)
        array[i++] = name;
}

int main() {
    const int N=25;
    int integers[N];
    string strings[N];

    addIntegers(integers, N);
    addStrings(strings, N);

    // TODO

    return 0;
}