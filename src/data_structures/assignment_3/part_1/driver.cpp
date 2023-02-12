// Programmer:      Nicholas Martinez
// Project number:  3.1
// Project Desc:    Multipath binary search tree
// Course:          COSC 2436 PF III Data Structures
// Date:            2/10/23

#include<iostream>
#include<iomanip>

using namespace std;

int maxArray(int[], int, int);

int main() {
    const int ORDERED_MAX = 20,
              ORDERED_LEN = 10,
              UNORDERD_MAX = 20,
              UNORDERED_LEN = 11,
              SMALL_MAX = 100,
              SMALL_LEN = 3,
              UNARY_MAX = 42,
              UNARY_LEN = 1,
              FIRST = 0;
    int orderedArray[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20},
        unorderedArray[] = {16, 10, 4, 20, 8, 2, 12, 14, 18, 6, 0},
        smallArray[] = {1, 100, 50},
        unaryArray[] = {42};
    bool orderedResult,
         unorderedResult,
         smallResult,
         unaryResult;
    
    orderedResult = maxArray(orderedArray, FIRST, ORDERED_LEN) == ORDERED_MAX;
    unorderedResult = maxArray(unorderedArray, FIRST, UNORDERED_LEN) == UNORDERD_MAX;
    smallResult = maxArray(smallArray, FIRST, SMALL_LEN) == SMALL_MAX;
    unaryResult = maxArray(unaryArray, FIRST, UNARY_LEN) == UNARY_MAX;

    cout << left << setw(38) << "maxArray(orderedArray, 0, 10) = 20: " << (orderedResult ? "true" : "false") << endl
         << left << setw(38) << "maxArray(unorderedArray, 0, 11) = 20: " << (unorderedResult ? "true" : "false") << endl
         << left << setw(38) << "maxArray(smallArray, 0, 3) = 100: " << (smallResult ? "true" : "false") << endl
         << left << setw(38) << "maxArray(unaryArray, 0, 1) = 1: " << (unaryResult ? "true" : "false") << endl;

    return 0;
}

int maxArray(int anArray[], int i, int n) {

    if (i == n-1)
        return anArray[i];

    int mid = !((n-i) % 2) ? i + (n-i) / 2 : i + 1 + (n-i) / 2;

    return max(maxArray(anArray, i, mid), maxArray(anArray, mid, n));
}

// maxArray(ordered, 0, 10)
// |_ max(maxArray(0, 6), maxArray(6, 10)) -> max(max(6, 12), max(16, 20)) = 20
//     |_ maxArray(0, 3), maxArray(3, 6)
//     |   |_ maxArray(0, 2), maxArray(2, 3)
//     |   |  |_ maxArray(0, 1), maxArray(1, 2), 6
//     |   |       |_ max(max(2, 4), 6) = 6
//     |   |_ maxArray(3, 4), maxArray(4, 6)
//     |       |_ max(8, maxArray(4, 6))
//     |           |_ 8, maxArray(4, 5), maxArray(5, 6)
//     |               |_ max(8, max(10, 12)) = 12
//     |_ max(maxArray(6, 8), maxArray(8, 10))
//         |_ maxArray(6, 7), maxArray(7, 8)
//         |   |_ max(14, 16) = 16
//         |_ maxArray(8, 9), maxArray(9, 10)
//             |_ max(18, 20) = 20