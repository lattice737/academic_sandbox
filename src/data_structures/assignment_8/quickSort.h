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
void sortLastMiddleFirst(ItemType array[], int first, int mid, int last) {
    if (array[first] > array[mid])
        swapItems(array, first, mid);
    if (array[mid] > array[last])
        swapItems(array, mid, last);
    if (array[first] > array[mid]) // first & mid may have changed at this point
        swapItems(array, first, mid);
}

// TODO
template <class ItemType>
int partition(ItemType array[], int i, int j) {
    return -1;
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
