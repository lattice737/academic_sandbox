using namespace std;

/*
Vocabulary
==========
* Search key - the criterion used to search for an item in a collection of data
* Dictionary (or map or table) - a collection that uses a search key to identify its entries and has a special operation
  for entry lookup
* Key-value pair - a cohesive characterization of a value in a collection using a search key
* Nonlinear implementation - a collection ADT that is not organized as a one-dimensional sequence (e.g. binary tree)
* Hash function - an address calculator that determines where to store information, for near-instantaneous access
* Hashing - an implementation using a hash function
* Hash table - the array of addresses referenced by hash
* Perfect hash function - a hash function that maps each search key into a unique location of the hash table
* Collision - occurs when a hash function maps more than one entry into the same array location
* Digit selection - a hash function approach where entries' hashes are computed from some numeric representation of the
  entry's search key (e.g. certain places of an integer for integral entries); they are simple and fast but usually do not
  evently distribute entries into a hash table
* Folding - a hash function approach where entries' hashes are computed by summing the values that make up their search
  key numeric representations, either individually or as groups
* Modulo arithmetic - a hash function approach where entries' hashes are computed as i % tableSize where tableSize is a
  prime number
* Horner's rule - a hash function approach where string entry hashes are computed by expressing their search key binary
  representations as a polynomial kn * 32^n + ... + k2 * 32^2 + k1 * 32^1 + k0 * 32^0, where each character is a 5-bit
  binary number; this representation minimizes the number of arithmetic operations for hash calculation
* Collision-resolution scheme - 

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
~ A perfect hash function can be constructed if all possible search keys that actually occur in the dictionary are known;
  however, in practice, a hash function may map two or more search keys into the same integer
~ The only way to avoid collisions completely is for a hash table to be large enough that each possible search key can
  have its own location
~ In general, a hash function must be easy and fast to compute and place entries evenly throughout the hash table, where
  the size of the table affects the ability to evenly distribute entries
~ Best practice is for a hash function to utilize entries' entire search keys
~ For hash functions where overflow may occur, h(x) + x % tableSize prevents overflow
*/

int main() {
    return 0;
}