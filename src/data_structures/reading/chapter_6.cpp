using namespace std;

/*
Vocabulary
==========
* Last in, first out (LIFO) - characterization of a container, usually a stack, where the last item inserted is also the
  first one removed
* First in, first out (FIFO) - characterization of a container, usually a queue, where the first item inserted is also the
  first one removed
* Axiom - a mathematical rule implemented to be a true statement for an ADT's operation
* Loop invariant - a condition that is true before and after each iteration of an algorithm's loop

General
=======
~ Data management objectives:
  1) Identify useful sets of operations (e.g. abstract data types)
  2) Examine applications that use the abstract data types
  3) Construct implementations for the abstract data types (e.g. data structures & classes)
~ Data can be organized either by position or by value
~ The specification of an abstract data type that you can use to solve a particular problem can emergy during the design
  of the problem's solution
~ In the spirit of fail-safe programming, a function that implements the text's balanced-braces algorithm should check
  a stack's push() method return value
~ Knowing how to convert an expression from infix to postfix notation not only lead to an algorithm to evaluate infix
  expressions, but also will give you some insight into the compilation process
~ Algorithms that evaluate an infix expression or transform one to postfix form must determine which operands to apply
  to a given operator, in order to allow for precedence and left-to-right association where parentheses are omitted
~ Relationship between stacks and recursion implementations:
  1) Iterating: push onto stack = recursive function call
  2) Backtracking: pop from stack = return from a recursive call
  3) Termination: stack becomes empty = base case
~ It's always possible to capture the actions of a recursive function by using a stack
~ It's common for a compiler to use a stack to implement a recurisve function in a manner that resembles the box trace,
  storing activation records to recall argument values and local variables of the recursive calls
*/

int main() {
    return 0;
}