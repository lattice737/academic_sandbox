#include <iostream>

using namespace std;

/*
Vocabulary
==========
* Sorting - the process of organizing a collection of data into either ascending or descending order
* Internal sort - requires that a data collection fit entirely into a computer's main memory
* External sort - sorting that uses memory residing in secondary storage
* Sort key - the data member that will be used to sort a collection of objects
* Selection sort - the iterative searching for the maximum value in a progressively shrinking slice of the collection and placing it at
  the end of the slice
* Bubble sort - iterative comparison of adjacent items, exchanging out of order items; items are "bubbled" to their proper position with
  each pass
* Insertion sort - the iterative placement each value in a collection at its proper position
* Merge sort - a recursive sort that halves a collection, sorts the halves, and then merges them, achieving equal performance regardless
  of the initial order of the items
* Quick sort - a sort that partitions a collection into items that are greater/less than or equal to the pivot
* 

General
=======
~ As a first step in analyzing algorithms, the compare/exchange/move operations should be counted, as they are generally more expensive
  than operations that control loops or manipulate array indices--especially when the data being sorted is more complex
~ Selection sort has time complexity O(n^2) (quadratic) and is therefore only appropriate for small problems
~ When data items are large but the sort key is short (or an integer), then data moves may instead be costly and comparisons inexpensive,
  so a selection sort would be appropriate
~ The fact that the items in the sorted region of a collection are sorted among themselves during an insertion sort is an assertion of
  the algorithm
~ Because there are either log2n or (log2n+1) levels, the merge sort is O(nlogn) for both the worst and average cases
~ The drawback of a merge sort is the need for an auxiliary array, which requires extra storage and necessary entry copying
~ 
*/

template<class ItemType>
int getArrayLength(ItemType array[]) {
    return sizeof(array) / sizeof(array[0]);
}

template<class ItemType>
void displayArray(ItemType array[], int size) {
    cout << "Sorted array: ";
    for (int i=0; i<n; i++)
        cout << array[i] << (i == n-1 ? "\n" : ", ");
}

/** Finds the largest item in an array.
 @pre  The size of the array is >= 1.
 @post  The arguments are unchanged.
 @param array  The given array.
 @param size  The number of elements in the passed array.
 @return  The index of the largest entry in the array. */
template<class ItemType>
int findIndexOfLargest(const ItemType array[], int size) {
    int largest = 0;  // Index of largest entry to this point
    for (int i=0; i<size; i++)
        if (array[i] > array[largest]) largest = i;
    return largest;
}

/** Sorts the items in an array into ascending order.
 @pre  None.
 @post  The array is sorted into ascending order; the size of the array
    is unchanged.
 @param array  The array to sort.
 @param n  The size of passed array. */
template<class ItemType>
void selectionSort(ItemType array[], int n) {
    // Time complexity: n^2/2 + 5n/2 - 3 -> n^2 + n -> O(n^2)
    int largest;
    for (int last=n-1; last>=1; last--) {
        largest = findIndexOfLargest(array, last+1);  // n(n-2)/2 comparisons
        swap(array[largest], array[last]);  // 3(n-1) moves
    }
    displayArray(array, n);
}

/** Sorts the items in an array into the specified order.
 @pre  None.
 @post  The passed array is sorted into the specified order; n is unchanged.
 @param array  The passed array.
 @param n  The size of the passed array.
 @param ascending  The sort to use; default ascending. */
template<class ItemType>
void bubbleSort(ItemType array[], int n, bool ascending=true) {
    // Time complexity: n^2 - n -> O(n^2)
    bool sorted = false,
         test;
    int pass = 1;
    while (!sorted && pass<n) {
        sorted = true;
        for (int i=0; i<n-pass; i++) {
            test = ascending ? (array[i] > array[i+1]) : (array[i] < array[i+1]); // n(n-1)/2 comparisons
            if (test) {
                swap(array[i], array[i+1]); // n(n-1)/2 exchanges that require 3(n-1) moves
                sorted = false;
            }
        }
        pass++;
    }
    displayArray(array, n);
}

/** Sorts the items in an array into ascending order.
 @pre  None.
 @post  The passed array is sorted in ascending order; n is unchanged.
 @param array  The passed array.
 @param size  The size of the passed array. */
template<class ItemType>
void insertionSort(ItemType array[], int n) {
    // Time complexity: n(n-1) + 2(n-1) -> n^2 + n -> O(n^2)

    ItemType nextItem;
    int i;
    
    // Initially, the sorted region is array[0]
    //            the unsorted region is array[1..n-1]
    // Generally, the sorted region is array[0..unsorted-1]
    //            the unsorted region is array[unsorted..n-1]
    for (int unsorted=1; unsorted<n; i++) {  // 2(n-1) moves
    
        nextItem = array[unsorted];
        i = unsorted;
    
        while (i>0 && array[i-1]>nextItem) {  // n(n-1)/2 comparisons
            array[i] = array[i-1];  // n(n-1)/2 additions
            i--;
        }
    
        array[i] = nextItem;
    }
    
    displayArray(array, n);
}

/** Merges two sorted array segments array[first..mid] and
    array[mid+1..last] into one sorted array.
 @pre  first <= mid <= last. The subarrays arra[first..mid] and
    array[mid+1..last] are each sorted in increasing order.
 @post  arra[first..last] is sorted.
 @param array  The passed array.
 @param first  The index of the beginning of the first segment in
    the passed array.
 @param mid  The index of the end of the first segment inthe passed
    array; mid+1 marks the beginning of the second segment.
 @param last  The index of the last element in the second segment of
    the passed array.
 @note  This function merges the two subarrays into a temporary
    array and copies the result into the originally passed array. */
template<class ItemType>
void merge(ItemType array[], int first, int mid, int last) {
    const int MAX_SIZE=5;
    ItemType placeholder[MAX_SIZE];
    int first1 = first, // Start of first slice
        last1 = mid,    // End of first slice
        first2 = mid+1, // Start of second slice
        last2 = last,   // End of second slice
        i = first1;
    
    // While both slices are not empty, copy the smaller item into the placeholder
    while (first1 <= last1 && first2 <= last2) {
        if (array[first1] <= array[first2]) {
            placeholder[i] = array[first1];
            first1++;
        } else {
            placeholder[i] = array[first2];
            first2++;
        }
        i++;
    }

    // Finish off first slice if necessary
    while (first1 <= last1) {
        placeholder[i] = array[first1];
        first1++;
        i++;
    }

    // Finish off second slice if necessary
    while (first2 <= last2) {
        placeholder[i] = array[first2];
        first2++;
        i++;
    }

    // Copy the result back into the passed array
    for (i=first; i<last; i++)
        array[i] = placeholder[i];
}

/** Sorts the items in an array into ascending order.
 @pre  array[first..last] is an array.
 @post  arra[first..last] is sorted in ascending order.
 @param array  The passed array.
 @param first  The index of the first element to consider in the passed array.
 @param last  The index of the last element to consider in the passed array. */
template<class ItemType>
void mergeSort(ItemType array[], int first, int last) {
    // Time complexity:
    // 3n - 2^m for m-calls to merge(); 1+log2(n) recursive calls to mergeSort()
    // -> O(log2[n] * n) where each recursion requires O(n) operations for O(log2[n]) recursive calls
    // -> O(nlog[n])

    if (first >= last) displayArray(array, last+1);

    int mid = first + (last-mid) / 2;
    
    // 3(n/2)-1 operations
    mergeSort(array, first, mid);
    mergeSort(array, mid+1, last);

    // 3(n-1) operations -> n/2^m operations for 2^m calls
    merge(array, first, mid, last);
    
    displayArray(array, last+1);
}



int main() {
    int fiveIntegers[] = {29, 10, 14, 37, 13},
        questionOne[] = {20, 80, 40, 25, 60, 30},
        questionFour[] = {25, 30, 20, 80, 40, 60};

    selectionSort(fiveIntegers, getArrayLength(fiveIntegers));
    selectionSort(questionOne, getArrayLength(questionOne));
    bubbleSort(questionFour, getArrayLength(questionFour));
    bubbleSort(questionFour, getArrayLength(questionFour), false);

    return 0;
}

