//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "insertionSort.h"
#include <iostream>

using namespace std;

const int MIN_SIZE=4;

template <class ItemType>
void sortFirstMiddleLast(ItemType array[], int first, int mid, int last) {
    if (array[first] > array[mid])
        swap(array[first], array[mid]);
    if (array[mid] > array[last])
        swap(array[mid], array[last]);
    if (array[first] > array[mid]) // first & mid may have changed at this point
        swap(array[first], array[mid]);
}

template <class ItemType>
int partition(ItemType itemArray[], int first, int last) {
    int mid = first + (last - first) / 2,
        indexFromRight,
        indexFromLeft,
        pivotIndex;
    bool done = false;
    ItemType pivot;

    // Select pivot & reposition
    sortFirstMiddleLast(itemArray, first, mid, last);
    swap(itemArray[mid], itemArray[last-1]);

    pivotIndex = last - 1;
    pivot = itemArray[pivotIndex];

    // Determine partitions
    indexFromLeft = first + 1;
    indexFromRight = last - 2;

    while (!done) {
        // Locate first entry on left that is >= pivot
        while (itemArray[indexFromLeft] < pivot)
            indexFromLeft += 1;
        
        // Locate first entry on right that is <= pivot
        while (itemArray[indexFromRight] > pivot)
            indexFromRight -= 1;

        if (indexFromLeft < indexFromRight) {
            swap(itemArray[indexFromLeft], itemArray[indexFromRight]);
            indexFromLeft += 1;
            indexFromRight -= 1;
        } else
            done = true;
    }

    // Place pivot between the partitions
    swap(itemArray[pivotIndex], itemArray[indexFromLeft]);
    pivotIndex = indexFromLeft;

    return pivotIndex;
}

/** Sorts an array into ascending order. Uses the quick sort with
    median-of-three pivot selection for arrays of at least MIN_SIZE
    entries, and uses the insertion sort for other arrays.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The index of the first element to consider in theArray.
 @param last  The index of the last element to consider in theArray. */
template <class ItemType>
void quickSort(ItemType theArray[], int first, int last)
{
    if ((last - first + 1) < MIN_SIZE)
    {
        cout << "Calling insertionSort() with array size = " << (last - first + 1) << endl;
        insertionSort(theArray, first, last);
    }
    else
    {
        // Create the partition: S1 | Pivot | S2
        int pivotIndex = partition(theArray, first, last);

        cout << "Calling quickSort() with L size = " << (pivotIndex - first) << " and R size = " << (last - pivotIndex) << endl;

        // Sort subarrays S1 and S2
        quickSort(theArray, first, pivotIndex-1);
        quickSort(theArray, pivotIndex+1, last);
    }  // end if
}  // end quickSort
