using namespace std;

/*
Vocabulary
==========
* Tail pointer - a dedicated pointer used to reference the node on the end of a chain in a link-based implementation
  of the queue (avoiding the need to traverse for access)
* Linear chain - a link-based implementation that models a one-dimensional sequence of nodes, regardless of external
  pointers
* Circular chain - a link-based implementation where the last node points to the first node; for a queue, this means
  only a back pointer is required
* Rightward drift - the tendency of items in a queue to displace to the end of an array-based implementation of a
  queue after a sequence of additions and removals, making it appear (incorrectly) full
* Circular array - an array that models a circle by incrementing the last item's index (back) to add items and
  incrementing the first item's index (front) when removing items, where the indices wrap around to 0 when they advance
  past the last usable index (DEFAULT_CAPACITY - 1)
*

General
=======
~ None of the nodes in a circular chain point to the nullptr
~ Shifting array-based queue entries to the left after removals prevents rightward drift, but the cost of shifting is
  generally expensive
~ The wraparound effect of a circular queue is implemented using modulo arithmetic when incrementing front and back
~ Empty+full detection in array-based queues:
  1) Use an accumulator variable
     a) Full condition: count == DEFAULT_CAPACITY
     b) Empty condition: count == 0
  2) Use a boolean variable
     a) Full condition: front == (back+1) % DEFAULT_CAPACITY
     b) Empty condition: front == back
*/

int main()
{
    return 0;
}