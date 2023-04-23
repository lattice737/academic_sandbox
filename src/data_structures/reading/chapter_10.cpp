using namespace std;

/*
Vocabulary
==========
* Cost - factors such as computing time & memory, difficulties encountered by users, and the consequences
  of incorrect behavior that characterize a program 
* Analysis of algorithms - the areas of computer science that provides tools for contrasting the efficiency
  of different algorithms
* Growth rate - an algorithm's proportional time requirement
* Growth rate function - a functional representation of algorithm order for performance comparison--an
  algorithm with growth rate function f(n) is said to be "order f(n)"
* Big O notation - representation of growth rate functions using capitalized O--order f(n) = O(f(n)) = O(n)
* Algorithm order - an algorithm is order f(n) if constants k and n0 exist such that the algorithm requires
  no more than k * f(n) time units to solve a problem of size n >= n0
* O(1) (constant) - implies a problem whose time requirement is constant and therefore independent of problem
  size n
* O(log(n)) (logarithmic) - the time requirement increases slowly as the problem size increases; squaring
  the problem size only doubles the time requirement, and the base of the log does not affect the growth rate
* O(n) (linear) - the time requirement increases directly with the size of the problem
* O(n*log(n)) - the time requirement increases more rapidly than a linear-order algorithm; usually, these
  algorithms divide a problem into smaller problems that are solved separately
* O(n^2) (quadratic) - the time requirement increases rapidly with problem size; often, these are algorithms
  that implement two nested loops and are practical only for small problems
* O(n^3) (cubic) - the time requirement incrases more rapidly with problem size than a quadratic-order
  algorithm; often, these are algorithms that implement three nested loops
* O(2^n) (exponential) - the time requirement increases too rapidly with problem size to be practical
* Worst-case analysis - an evaluation of algorithm efficiency that concludes that an algorithm is O(f(n)) if
  its worst case requires no more than k*f(n) time units to solve a problem with size n for all but a finite
  number of values of n; an algorithm's worst case may not occur frequently, but it can be guaranteed never
  to perform slower than the estimate
* Average-case analysis - an evaluation of algorithm efficiency that attempts to determine the average
  time required by an algorithm to solve problems of size n, where an algorithm is O(f(n)) if the average
  amount of time required is no more than k*f(n) time units for all but a finite number of values n; it is
  difficult to determine the distributions of various data values and determine the relative probabilities
  of encountering various problems of a given size

General
=======
~ In assessing whether a solution is good, the effort required to develop it, as well as any changes (i.e.
  bug fixes, extensions) that are made after the program has been deployed
~ A solution is good if the total cost it incurs over all phases of its life is minimal
~ People should not have to entrust their livelihoods or lives to programs that only its authors can
  understand and maintain
~ Efficiency should be the highest concern when developing an underlying algorithm
~ The choice of objects and design of the interactions between those objects have the most significant
  impact on efficiency
~ In modern computing, the value of the designers' and programmers' time is a much more significant factor
  than computing time in the cost of a solution
~ Reductions in computing costs due to clever coding tricks are often more than offset by reduced program
  readability, which increases human costs
~ Analysis should focus on gross differences in algorithm efficiency that are likely to dominate the overall
  cost of a solution
~ Factors that confound runtime comparison:
  1) Implementation style
  2) Hardware differences
  3) Quality of selected cases
~ Counting an algorithm's operations (when possible) is a way to assess its efficiency, where its execution
  time is related to the number of operations it must perform
~ When comparing solutions' efficiency, only significant differences need to be considered
~ The requirement n >= n0 in the definition of O(f(n)) formalizes the notion of sufficiently large problems
  --in general, many values of k and n can satisfy this definition
~ Common growth-rate functions:
  O(1) < O(log2n) < O(n) < O(n * log2n) < O(n^2) < O(n^3) < O(2^n)
~ Properties of growth-rate functions:
  1) Low-order terms can be ignored
  2) Scalar constants in the highest-order term can be ignored
  3) O(f[n]) + O(g[n]) = O(f[n] + g[n])
~ Deriving the exact time requirement is often difficult and sometimes impossible; however, only an estimate
  is needed to obtain an algorithm's growth rate
~ An algorithm may require different times to solve different problems of the same size, so worst-case and
  average-case analyses are usually considered
~ Algorithm considerations:
  1) Maximum problem size
  2) Frequency of ADT operations (e.g. many insertions & removals needed)
  3) Critical operations that must be efficient but may be less frequent
  4) Memory requirements
  5) Implementation style (e.g. simplicity)
*/

int main() {
    return 0;
}