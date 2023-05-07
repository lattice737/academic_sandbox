using namespace std;

/*
Vocabulary
==========
* Search key - the criterion used to search for an item in a collection of data
* Dictionary (or map or table) - a collection that uses a search key to identify its entries and has a special operation
  for entry lookup
* Key-value pair - a cohesive characterization of a value in a collection using a search key
* Nonlinear implementation - a collection ADT that is not organized as a one-dimensional sequence (e.g. binary tree)
* 

General
=======
~ Typically, the entries in an ADT dictionary are objects that contain several pieces of data
~ If entry retrieval is based on something other than its search key, the entire dictionary will have to be inspected
~ Changing the search key of an existing entry in the dictionary could make that entry or other entries impossible to find,
  so the client should not be able to modify an entry's search key once the entry is in the dictionary
~ A sorted linear array-based implementation of the ADT dictionary must shift data during entry additions and removals,
  which can be especially expensive for large dictionaries
~ An important advantage of a sorted-array-implementation of a dictionary is that the private method findEntryIndex() can
  use a recursive binary search to locate a search key
~ Although linear implementations of the ADT dictionary are acceptable for specific applications, they are not suitable as
  general-purpose classes
~ When the tree approaches a linear shape, the performance of dictionary operations is comparable to a linear, link-based
  implementation (worst-case)
~ 
*/

int main() {
    return 0;
}