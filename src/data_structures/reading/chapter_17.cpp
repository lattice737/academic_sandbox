#include <iostream>

using namespace std;

/*
Vocabulary
==========
* Heap - a complete binary tree that is either empty or has a root that 1) contains a value greater than or equal to its children's
  values and 2) has heaps as its subtrees
* Maxheap - a heap where the root contains the largest value
* Minheap - a heap where the root contains the smallest value
* Semiheap - a heap where the root item is out of place
* 

General
=======
~ Heap distinctions from a binary search tree:
  1) A heap is ordered but not sorted (BSTs are sorted)
  2) Heaps are always complete binary trees (BSTs may be many shapes)
~ Because a heap is a complete binary tree, a simpler, less memory-expensive array-based implementation can be used, where the
  nodes are mapped to array indices
~ An array-based heap requires a complete binary tree in its operations to prevent parent-child relationship ambiguity
~ Maxheap remove() requires 3log2(n+1)+1 data moves - O(logn)
~ 
*/

int main() {
    return 0;
}