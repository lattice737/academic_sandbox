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
* Collision resolution scheme - a strategy for reducing the probability of indentical search key hash indices
* Probing - the process of determining another, empty (open) location to place an entry that has the hash index of an
  occupied location in a hash table
* Probe sequence - the set of locations examined during probing
* Open addressing - a collision resolution scheme that implements a probing tecnique when two entries share a hash key
  index
* Linear probing - sequential searching of a hash table, starting from the original has location; after reaching the last
  location, the search wraps to the beginning of the table if needed
* Primary clustering - the tendency of a hash table's entries to occupy consecutive locations, where clusters tend to vary
  in size and cause long probe searches
* Quadratic probing - a probing technique that searches in square steps (i.e. hash+1^2, hash+2^2, hash+3^2, etc)
* Secondary clustering - the delay of collision resolution when using quadratic probing
* Double-hashing - an open-addressing scheme that searches a hash table in a linear order starting at a hash key location
  h1(key) and uses a second hash function h2(key) to determine the search step size where h2(key) != 0 and h2 != h1
* Key-dependency - a hashing scheme property characterized by whether the sequence is based on hash keys
* Rehashing - the process of enlarging a hash table and computing new hash indices for its contents
* Restructuring - a collision resolution scheme where the hash table array is modified to accommodate more than one entry
* Bucket - a hash table location that is an array
* Separate chaining - a hash table structured as an array of linked chains, where the size of a dictionary is dynamic and 
  can exceed the size of the hash table; it represents the most time-efficient collision resolution scheme
* Load factor (alpha) - the ratio of the current number of table entries to maximum table size; a measure of hash table
  fullness, it is used for average-case hashing efficiency analysis
* Range query - retrieval of dictionary entries whose search keys are within a given value range
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
~ A perfect hash function can be constructed if all possible search keys that actually occur in the dictionary are known;
  however, in practice, a hash function may map two or more search keys into the same integer
~ The only way to avoid collisions completely is for a hash table to be large enough that each possible search key can
  have its own location
~ In general, a hash function must be easy and fast to compute and place entries evenly throughout the hash table, where
  the size of the table affects the ability to evenly distribute entries
~ Best practice is for a hash function to utilize entries' entire search keys
~ For hash functions where overflow may occur, h(x) + x % tableSize prevents overflow
~ Linear probing with removals requires flagging each location as occupied, empty, or removed, then accessors and mutators
  must account for them
~ One of the problems with linear probing schemes is that entries tend to cluster together
~ Double-hashing probe sequences will tend to visit all table locations if the size of the hash table and the size of the
  probe step are relatively prime; however, they are difficult to implement
~ With any open-addressing scheme, the probability of collision increases with hash table size; additionally, the table
  cannot be grown arbitrarily (size must be prime) and must be rehashed
~ Bucket size is the principal problem of bucket-structured hash tables: small buckets do not adequately resolve collision
  and large buckets risk wasting storage
~ Hashing efficiency decreases as load factor increases: As a table fills, load factor increases and the chance of collision
  increases, so search times also increases
~ Unlike other data structure implementations, hashing efficiency does not depend solely on the number of entries (n);
  optimal table size should estimate the largest possible n and small load factor (alpha <= 2/3)
~ Hashing efficiency for a particular search depends on the success of a search, where an unsuccessful search generally
  requires more time than a successful search
~ Average-case hashing efficiencies:
     Scheme               Successful                Unsuccessful
  1) Linear probing       0.5*[1 + 1/(1-alpha)]     0.5*[1 + 1/(1-alpha)^2]
  2) Quadratic probing    -loge(1-alpha)/alpha      1/(1-alpha)
  3) Double hashing       -loge(1-alpha)/alpha      1/(1-alpha)
  4) Separate chaining    1 + alpha/2               alpha
~ Fewer comparisons are required for quadratic probing and double hashing than linear probing, so smaller table can be used
~ Open-addressing schemes require a good estimate of the number of additions and removals, and small tables will fill up
  quickly, hurting efficiency
~ For separate chaining, load factor = n / number of chains (average chain length)
~ Chains may be large if most entries are hashed into the same location or table size is greatly underestimated (worst case)
~ When a hash table is about half full (alpha = 0.5), the techniques are nearly equally efficient; but as the dictionary
  fills (alpha -> 1), separate chaining is the most efficient technique
~ In the worst case, hashing can be much less efficient than other implementations (e.g. search tree), and separate chaining
  in particular has greater storage overhead due to the pointers in the linked chains, especially for smaller tables
~ Best practices for maintaining hashing efficiency:
  a) alpha < 0.5 for open addressing
  b) alpha < 1.0 for separate chaining
  c) increase the size of the table (e.g rehashing) for alpha > 1.0
~ Good hash functions:
  a) Fast and easy to compute: most common hash functions require only a single division (e.g. modulo), single multiplication,
     or some bit-level operation on the internal representation of the search key
  b) Even scattering
     i) Random data scattering: characterization of equally likely search keys for any given datum (e.g. h1(x) = x-prefix % 40
        v. h2(x) = x mod 101 -- only latter scatters evenly)
     ii) Nonrandom data scattering: characterization of some data pattern that produces uneven scattering (e.g. entries that
         are not equally likely); impossible to prevent, but likelihood of occurrence can be decreased
~ Much research has been done into the types of hash functions to use for reducing various types of patterns in data
~ General principles for reducing nonrandom data scattering:
  1) Hash function calculation should involve the entire search key
  2) Hash functions using modulo arithmetic should have prime bases (e.g. h(x) = x % base)
~ Because high quality hash functions scatter entries as randomly as possible (minimal ordering), dictionary traversal in
  sorted order performs poorly; in general, a search tree is preferred for ordered operations
~ For externally stored data, the difference in speed between a hashing entry retrieval and a search tree implementation can
  be significant; the efficiency and storage trade-offs make combination implementations common
~ 
*/

int main() {
    return 0;
}