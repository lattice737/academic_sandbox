using namespace std;

/*
Vocabulary
==========
* Sorted list - a container of items that determines and maintains the order of its entries by their values
* 

General
=======
~ The problem of maintaining sorted data involves more than simply sorting it; often some data needs to be
  properly inserted or removed
~ ADT list operation worst-case efficiencies:
     Operation  |  Array-based  |  Link-based
  1) insert()      O(n)            O(n)
  2) remove()      O(n)            O(n)
  3) getEntry()    O(1)            O(n)
  4) replace()     O(1)            O(n)
  5) clear()       O(1)            O(n)
  6) getLength()   O(1)            O(1)
  7) isEmpty()     O(1)            O(1)
~ ADT list operation worst-case efficiencies using an ADT list instance:
     Operation      |  Array-based  |  Link-based
  1) insertSorted()    O(n)            O(n^2)
  2) removeSorted()    O(n)            O(n^2)
  3) getPosition()     O(n)            O(n^2)
  4) getEntry()        O(1)            O(n)
  5) clear()           O(1)            O(n)
  6) getLength()       O(1)            O(1)
  7) isEmpty()         O(1)            O(1)
~ Public inheritance should only be used when two classes have an is-a relationship
~ 
*/

int main() {
    return 0;
}