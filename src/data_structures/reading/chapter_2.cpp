#include<iostream>
#include<string>

using namespace std;

/*
Vocabulary
==========
* Iterative solution - implements loops for solving a problem
* Sequential search - a search conducted by starting from one end of the collection and inspecting each item
* Binary search - a search conducted by bisecting a collection into two parts, selecting the section where the
  item must be, and then repeating this process until converging on the item
* Base case (or basis or degenerate case) - a special case with a known solution
* Divide & conquer - Division of a large problem into smaller, less complex problems until the base case is
  reached
* Recursive function - a function that calls itself
* Valued function - a function that returns a value
* Void function - a function with no return value
* Recurrence relation - an equation that expresses any given element of a sequence with respect to the preceding
  element
* Box trace - a recursion model that represents the calls of a recursive function by linking activation records
* Activation record - a box trace component that represents a function call and its arguments
* Target - the value of interest when searching a collection
* Multipath recursion - A recursive algorithm that solves more than one of its subproblems

General
=======
~ Not all recursive solutions are better than iterative solutions
~ Recursive function elements:
  1) Calls itself
  2) Successive calls decrease the collection by half
  3) When the base case is reached, recursive calls are stopped and the problem is solved directly
  4) Always reaches the base case
~ Without a base case, a recursive function will generate an infinite sequence of calls
~ When developing a recursive solution, the solutions to the smaller problems must return solutions to the
  original problem
~ An array is never passed to a function by value; therefore it is not copied
~ Array midpoint:
  1) mid = (first + last) / 2 -- risks overflow for large arrays
  2) mid = first + (last - first) / 2 -- equivalent to 1 but avoids overflow
~ As soon as an unsigned-integer computation exceeds the largest value for its type, it wraps around to the
  type's smallest value

*/

int factorial(int);
int summate(int);
void reverseWordFromBack(string);
void reverseWordFromFront(string);
void displayArrayBackward(const char[], int, int);
int multiplyArrayElements(const int[], int, int);
int orderedBinarySearch(const int[], int, int, int);

int main() {

    cout << "Recursion implementation of facotrial calculation" << endl
         << factorial(5) << endl;

    cout << "\nRecursion implementation of a sum calculation" << endl
         << summate(10) << endl;

    // String reversal by recursive removal of trailing character
    reverseWordFromBack("Nicholas");
    cout << endl;
    
    // String reversal by recursive removal of leading character
    reverseWordFromFront("Racecar");
    cout << endl;

    // Count down by recursive subtraction
    countDown(10);
    cout << endl;

    int integerArray[] = {2, 2, 2, 2, 2};

    cout << "\nRecursive multiplication of array elements"
         << multiplyArrayElements(integerArray, 0, 4) << endl;

    return 0;
}

/* Computes the factorial of the nonnegative integer i
 @pre       i must be greater than or equal to 0
 @post      None
 @return    The factorial of i; i is unchanged */
int factorial(int i) {
    return !i ? 1 : factorial(i-1);
}

/* Computes the sum of the integers from 1 to n
 @pre       n > 0
 @post      None
 @param n   A positive integer
 @return    The sum 1+2+...+n */
int summate(int n) {
    int sum = !n ? 1 : n + summate(n-1);
}

/* Writes a character string backward by recursively removing the last char
 @pre           The string to write backward
 @post          None
 @param word    The string to write backward */
void reverseWordFromBack(string word) {
    if (!word.empty()) {
        cout << word.substr(word.size()-1, 1);
        reverseWordFromBack(word.substr(word.size()-1, 1));
    }
}

/* Writes a character string backward by recursively removing the first char
 @pre           The string to write backward
 @post          None
 @param word    The string to write backward */
void reverseWordFromFront(string word) {
    if (!word.empty()) {
        cout << word.substr(0, word.size()-1);
        reverseWordFromFront(word.substr(0, word.size()-1));
    }
}

/* Writes a countdown from positive integer n to 1
 @pre           n > 0
 @post          None
 @param n       A positive integer */
void countDown(int n) {
    if (n > 1) {
        cout << n;
        countDown(n-1);
    }
}

/* Write the elements of an array in reverse
 @pre           Array with length > 0
 @post          None
 @param array   Array of length > 0
 @param first   Index of first character in array
 @param last    Index of last character in array */
void displayArrayBackward(const char cString[], int first, int last) {
    if (first <= last) {
        cout << cString[last];
        displayArrayBackward(cString, first, last-1);
    }
}

/* Multiply the elements of an array
 @pre             Integer array with length > 0
 @post            None
 @param intArray  Integer array of length > 0
 @param i         Index of first element
 @param n         Index of last element */
int multiplyArrayElements(const int intArray[], int i, int n) {
    return i == n ? intArray[i] : multiplyArrayElements(intArray, i, n-1);
}

/* Search the array intArray[i] through intArray[n] for a given value
 using a binary search tree
 @pre             i >= 0, n <= SIZE-1, where size is the maximum size of the array,
                  and intArray[i] <= intArray[i+1] <= ... <= intArray[n]
 @post            intArray is unchanged and either intArray[i] contains the given
                  value; otherwise index == -1
 @param intArray  Array to search
 @param i         The minimum index to start searching from
 @param n         The maximum index to stop searching at
 @param target    The value to find
 @return          Index of element equal to target, or -1 */
int orderedBinarySearch(const int intArray[], int i, int n, int target) {
    
    if (i > n)
        return -1;

    int mid = i + (n-i) / 2;

    if (target < intArray[mid])
        return orderedBinarySearch(intArray, i, mid-1, target);
    else if (target > intArray[mid])
        return orderedBinarySearch(intArray, mid+1, n, target);

    return mid;
}

int findArrayMaximum(const int intArray[], int i, int n, int target) {
    // TODO implement
    return 0;
}