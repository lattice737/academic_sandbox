// Chapter 9 Concepts

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;

/*
Vocabulary
==========
* Linear (or sequential) search algorithm - implementation of a loop to sequentially evaluate each element of a container
  to locate the desired value, indpendent of element order
* Binary search - an algorithm that iteratively halves its search range in a container of ascending/descending elements to
  locate a value
* Sort key (or key field) - the member variable being examined for a value of interest in a search of objects or structures with
  data members (e.g. for an array of Employee objects, perhaps only data member hourlyRate is evaluated for each object)
* Search key - the value of interest
* Sorting algorithm - a technique for stepping through an array and rearranging its contents in a specific order
* Bubble sort - a sorting algorithm that evaluates every pair of elements in an array and, with each pass, either swaps them or
  does nothing, until sorting is completed
* Selection sort - a sorting algorithm that places an element in its proper position with each pass
* Algorithm - a step-by-step procedure for solving a problem
* Space criterion - the amount of memory required for an algorithm to solve a problem
* Time criterion - the length of an algorithm's execution time
* Copmutational problem (P) - a collection of instances that make up a problem to be solved using an algorithm; it is characterized
  by the appearance of its input, its size, and what output it should produce
* Instance - a characteristic case of input data for an algorithm in some prescribed format
* Instance size - the amount of memory required to hold an instance's input data
* Basic operation (or step) - a step that can be executed by an algorithm in time bounded by a constant (regardless of input size)
* Complexity - The number of basic steps in an algorithm for a size-n input
* Worst-case complexity function [f(n)] - the number of steps that an algorithm performs on a size-n input that requires the most
  work and characterizes algorithm efficiency by indicating the longest time it can take to solve a size-n instance
* Average-case complexity function - a weighted average of the number of steps performed on each instance input, based on the
  relative frequencies of the different input occurrences
* Complexity classes - a family of functions O(g(n)) that grows no faster than function g(n)
* 

General
=======
~ Conventionally, -1 is returned when an item is not found in a container, because it is an invalid subscript; however,
  any nonvalid subscript may be returned
~ On average, for an array of N elements, a linear search will locate an value in N/2 attempts
~ The linear search is simple but inefficient, because it must evaluate every element when it fails to locate a value; so
  as the number of failed search attempts increases, so does the average number of comparisons
~ Binary searches can locate a value in any size array with a maximum of n comparisons, where n is the smallest integer that
  satisfies 2^n > len(array) (e.g. 16 comparisons needed for an array of 50,000 elements, where 2^16 = 65,536 and 2^15 = 32,758)
~ Functions can specify constant array parameters to safeguard them from changes
~ The bubble sort gets its name from its method of "sinking" larger values to the bottom of an array and "bubbling" its smaller
  values to the top of an array with each pass
~ Bubble sorts will pass N-1 times for an N-element array and do not have to evaluate every element once it has been properly
  placed
~ The classic bubble sort is inefficient because only one value is placed properly during each pass; however, the number of
  iterations can be reduced by incorporating the fact that no swaps are needed when the array is fully sorted
~ Even the enhanced bubble sort is inefficient, because values may only move toward their final position one place at a time
~ The selection sort algorithm only requires one swap on each pass, because it moves items immediately to their proper place
~ Selection sorting will execute N-1 passes for N-element arrays, but because fewer swaps are done per pass, it is more
  efficient than bubble sorting
~ Standard Template Library vectors can also be searched and sorted with these algorithms
~ Searching & sorting with vectors requires passing by reference instead of passing as constants and does not require a size
  parameter, since vectors have a size() member function
~ Shortcomings of implementing + measuring execution time:
  1) Measures program performance, not algorithm performance
  2) Results vary with programming language and compiler selection
  3) Results vary on OS and hardware
  4) Results may not be representative of performance with different inputs
~ If the number of bits occupied by an instance is fixed, then it is representative of the instance size; otherwise, there is
  no upper bound on the size of the elements
~ "Time bounded by a constant":
  * Element swapping is a basic step, because the time required does not increase/decrease with the addition/subtraction of
    elements
  * Finding the largest element of an array is not a basic step, because the task requires more time to complete with larger
    arrays and less time with shorter arrays
~ The definition of a basic step does not specify the size of the constant that bounds the step's execution time--this reflects
  the reality that the same operation may be execuited with different speeds on different hardware; consequently, any constant
  number of basic steps can be represented as a single basic step (e.g. an algorithm executing 5n basic steps can be
  characterized as executing n basic steps)
~ Ordinary arithmetic and logic operations such as addition and comparison are not basic unless a constant bound is set for
  the size of the numbers being added or compared
~ It only makes sense to describe an algorithm after the problem it is meant to solve has been described; a clear description
  of a problem's input, size, and output reduce ambiguity and generalize an algorithm to work with additional data sets
~ Pseudocode complexity evaluation:
  1: sum = 0
  2: k = 0
  3: while k < n do
  4:     sum += array[k]
  5:     k += 1;
  6: end while
  -------------
  1) lines 1 & 2 are executed once and are independent of array size -> basic step A
  2) lines 4 & 5 are executed each loop iteration and do not act on the whole array (independent) -> basic step B
  3) loop iterates n-times, so B will execute n-times -> n+1 (nB + A) operations performed
  4) for large n, 1 becomes negligible -> complexity is approximately n
~ For most algorithms, it is sufficient to identiy and count only one or two basic operations that are in some way crucial to
  the problem being solved
~ In cases where an algorithm may perform different amounts of work for different inputs of the same size, it's common to
  measure algorithm efficiency by the work done on an input of size n that requires the most work
~ Worst-case complexity evaluation of the binary search (value not found):
  1) Variable initialization requires constant time -> A
  2) L+1 steps are performed where L basic operations are bound to constant time -> L+1
  3) L ~ log2(n) where the searched regions of the array is halved every iteration and at most, 2 comparisons are performed
     each iteration -> 2log2(n) total operations
  5) Conclusion: In the worst case, binary search requires time proportional to log2(n)
~ The worst-case compleixty does not accurately reflect algorithm performance in practical situations where worst-case yields
  are rare; although average-case complexity estimation can characterize common performance, accurate estimates of input
  frequencies may be difficult to obtain
~ Algorithms can be compared by comparing their complexity functions f(n)/g(n) as n->inf, where the limit represents the
  number of steps multiple of f(n) relative to g(n)--constants represent equivalent efficiency
~ Algorithm comparisons:
  1) f = 3n^2 + 5n, g = n^2 : f/g = 3 + 5/n -> 3 as n->inf -- equivalent performance
  2) f = 3n^2 + 5n, g = 100n : f/g = 3n/100 + 5/100 -> n as n->inf -- F does more work with large inputs
  3) f = 3n^2 + 5n, g = n^3 : f/g = 3/n + 5/(n^2) -> 0 as n->inf -- G does more work with large inputs
~ If a positive constant k can be determined such that f(n)/g(n) <= k for all n>=1, then algorithm F is no worse than K times
  G for large problems--also: "f(n) is in O(g(n))" or f(n) <= k*g(n) when n>=1
~ Determining that f(n) is in O(g(n)): 3n^2 + 5n is in O(n^2)
  1) Express f(n)/g(n):
     f/g = 3 + 5/n
  2) Estimate a positive constant k that satisfies f(n)/g(n) <= k when n >= 1:
     5/n has max of 5, therefore 3 + 5/n <= 8 and k = 8
~ Big O notation:
  1) Algorithm comparison: An algorithm F is in O(g(n)) for some function g(n) if the worst-case complexity function f(n) of F
     is in Big O of g(n) (i.e. sequential array search is in O(n), binary array search is in O(log2(n)))
  2) Problem complexity: A computational problem is said to be in O(g(n)) if there exists an algorithm for the problem whose
     worst-case complexity function is in O(g(n)) (i.e. array sorting is in O(n^2), sorted-array searching is in O(log2(n)))
~ Complexity classes:
  1) Constant time [O(1)]: a function f(n) where constant k>0 such that f(n)<=k for all n>=1
  2) Logarithmic time [O(log2(n))]: log(n) grows much slower than n, so huge increases in problem size only slightly increase
     algorithm run time--characteristic of search problems that eliminate half of their search space with each basic operation
  3) Linear time [O(n)]: increases in problem size proportionally increase algorithm run time--characteristic of searches that
     make a single (or constant numbers of) passes over their input
  4) N-log-n time [O(n*log2(n))]: increases in problem size produce slight increases in algorithm runtime; also the average-case
     complexity of Quicksort
  5) Quadratic time [O(n^2)]: increases in problem size cause a much greater increase in algorithm runtime--characteristic of
     algorithms that make multiple passes over input data using two nested loops (e.g. worst-case complexity of bubble sort,
     selection sort, and Quicksort)

*/

struct Item {
  string label;
  int serialNo;
  double price;
};

int binarySearch(const int[], int, int);
void bubbleSort(const int[], int);
void enhancedBubbleSort(const int[], int);
void selectionSort(const int[], int);
int itemBinarySearch(vector<Item>&);
void itemSelectionSort(vector<Item>&);
void swap(int&, int&);
void swapItems(Item&, Item&);

int main() {
    int ordered[] = {0, 12, 33, 41, 60, 74, 97, 104, 112, 129, 130, 136, 150},
        unordered[] = {150, 12, 136, 60, 97, 0, 33, 41, 130, 104, 112, 74};

    // TODO add cases

    return 0;
}

int binarySearch(const int array[], int size, int value) {
    int first = 0,
        last = size-1,
        middle,
        position = -1;
    bool found = false;

    while (!found && first <= last) {
        middle = (first + last) / 2;
        if (array[middle] == value) {
            found = true;
            position = middle;
        } else if (array[middle] > value)
            last = middle-1;
        else
            first = middle+1;
    }
    return position;
}

void bubbleSort(const int array[], int size) {
    for (int maxElement=size-1; maxElement>0; maxElement--) {
        for (int i=0; i<maxElement; i++) {
            if (array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
            }
        }
    }
}

void enhancedBubbleSort(const int array[], int size) {
    bool swapped = true;
    for (int maxElement=size-1; maxElement>0 && swapped; maxElement--) {
        swapped = false;
        for (int i=0; i<maxElement; i++) {
            if (array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
                swapped = true;
            }
        }
    }
}

void selectionSort(const int array[], int size) {
    int minIndex, minValue;

    for (int start=0; start<(size-1); start++) {
        minIndex = start;
        minValue = array[start];
        for (int i=start+1; i<size; i++) {
            if (array[i] < minValue) {
                minValue = array[i];
                minIndex = i;
            }
        }
        swap(array[minIndex], array[start]);
    }
}

int itemBinarySearch(vector<Item> list, string text) {
    int first = 0,
        last = list.size()-1,
        middle,
        position = -1;
    bool found = false;

    while (!found && first <= last) {
        middle = (first + last) / 2;
        if (list[middle].label == text) {
            found = true;
            position = middle;
        } else if (list[middle].label > text)
            last = middle - 1;
        else
            first = middle + 1;
    }

    return position;
}

void itemSelectionSort(vector<Item> list) {
    int minIndex;
    double minValue;

    for (int start=0; start<list.size()-1; start++) {
        minIndex = start;
        minValue = list[start].price;
        for (int i=start+1; i<list.size(); i++) {
            if (list[i].price < minValue) {
                minValue = list[i].price;
                minIndex = i;
            }
        }
        swapItems(list[minIndex], list[start]);
    }
}

void swap(int& a, int& b) {
    int temporaryVar = a;
    a = b;
    b = temporaryVar;
}

void swapItems(Item& A, Item& B) {
    Item temporaryStruct = A;
    A = B;
    B = temporaryStruct;
}