//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 02/24/2023
// Status    : Completed
// 
// Sorts odd-length & even-length arrays, then displays their
// contents and their respective medians
//******************************************************************

#include<algorithm>
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>

using namespace std;

void sortArray(int[], int);
int getMedian(int[], int);
void printArray(int[], int);

int main() {
    const int EVENS_SIZE = 10,  // Length of even-length array
              ODDS_SIZE = 9;    // Length of odd-length array
    int evens[] = {17, 32, 45, 68, 99, 101, 67, 89, 22, 27},    // Even-length integer array
        odds[] = {17, 32, 45, 68, 99, 101, 67, 89, 22};         // Odd-length integer array
    
    sort(evens, evens+EVENS_SIZE);
    sort(odds, odds+ODDS_SIZE);
    printArray(evens, EVENS_SIZE);
    printArray(odds, ODDS_SIZE);

    return 0;
}

// Return median of array
int getMedian(int array[], int size) {
    int middle,         // Truncated split size for middle index
        rightMiddle,    // Index of the left of the middle two values
        leftMiddle;     // Index of the right of the middle two values

    // If array length is odd, return the middle value
    if (size % 2) {
        middle = size / 2;
        return *(array + middle);
    }

    // If array length is even, return the average of the two middle values
    rightMiddle = size / 2;
    leftMiddle = rightMiddle - 1;
    return (*(array + leftMiddle) + *(array + rightMiddle)) / 2;
}

// Display array and median
void printArray(int array[], int size) {
    cout << "Median of the " << (size % 2 ? "odd" : "even") << " array:" << endl;
    for (int i=0; i<size; i++)
        cout << *(array + i) << ' ';
    cout << "\nis " << getMedian(array, size);
    cout << endl;
}