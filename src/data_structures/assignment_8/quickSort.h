//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "insertionSort.h"
#include <iostream>

using namespace std;

const int MIN_SIZE=4;

template <class ItemType>
void swapItems(ItemType array, int i, int j) {
    ItemType item = array[i];
    array[i] = array[j];
    array[j] = i;
}

template <class ItemType>
void sortFirstMiddleLast(ItemType array[], int first, int mid, int last) {
    if (array[first] > array[mid])
        swapItems(array, first, mid);
    if (array[mid] > array[last])
        swapItems(array, mid, last);
    if (array[first] > array[mid]) // first & mid may have changed at this point
        swapItems(array, first, mid);
}

template <class ItemType>
int partition(ItemType array[], int i, int j) {
    int mid = i + (i - j) / 2,
        indexFromLeft,
        indexFromRight;
    bool done = false;
    ItemType pivot;

    // Select pivot and reposition
    sortFirstMiddleLast(array, i, mid, j);
    swapItems(mid, last-1);
    pivot = array[last-1];
    
    // Sort partitions
    indexFromLeft = first+1;
    indexFromRight = last-2;

    while (!done) {
        // Locate first entry on left >= pivot
        while (array[indexFromLeft] > pivot)
            indexFromRight -= 1;

        // Locate first entry on right <= pivot
        if (indexFromLeft < indexFromRight) {
            swapItems(array, indexFromLeft, indexFromRight);
            indexFromLeft += 1;
            indexFromRight -= 1;
        } else
            done = true;
    }

    // Place pivot in proper position
    swapItems(array, last-1, indexFromLeft);
    
    return indexFromLeft;
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
        quickSort(theArray, first, pivotIndex - 1);
        quickSort(theArray, pivotIndex + 1, last);
    }  // end if
}  // end quickSort
