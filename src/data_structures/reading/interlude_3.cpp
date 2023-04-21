#include<iostream>
#include<string>
#include<cassert>
#include<stdexcept>

using namespace std;

/*
Vocabulary
==========
* Exception - an object that signals the rest of the program that something unexpected has happened
* Exception handling - detection of and response to exceptions, using `try` and `catch` blocks
* Thrown exception - an exception executed using a `throw` statement, that bypasses normal execution
  and immediately returns control to the client
* `try` block - a block of statements that might throw an exception
* `catch` block - a block of statements following a `try` block that reacts to a specific exception
* `catch` block parameter - a `catch` block identifier that provides a name for the caught exception
  that can be used within it; it represents the actual exception object provided by the `throw`
  statement

General
=======
~ Assertions can be used to validate a method's preconditions or postconditions
~ The assert() function is a debugging tool, not a substitute for the if-statement
~ Assertions are useful when testing and debugging a program
~ A good debugging technique is halting the program as soon as a problematic condition becomes
  evident, in order to narrow the focus of the search for errors
~ An assertion can be implemented as a comment or using the assert() function
~ For errors that are either unimportant to a client's goals or simple for a client to fix, assertions
  are an extreme solution
~ When a `throw` statement executes, an object of type ExceptionClass is created, and the exception
  is thrown and propagated back to the point where the function was called to keep the statements in
  the function that follow the `throw` statement do not execute
~ C++ Exception Families (all derived from `exception`):
  1) logic_error: internal logic errors (i.e. unmet precondition, failure to satisfy an invariant)
     a) invalid_argument: invalid argument in function call
     b) length_error: an object to be created was too large
     c) out_of_range: a container was subscripted past its range
  2) runtime_error: errors detectable only at runtime
     a) overflow_error: arithmetic overflow has occurred
     b) range_error: computation result could not be represented by the desired type
     c) underflow_error: arithmetic underflow has occurred
  3) Programmer-defined exceptions
~ When exceptions are thrown, there should first be a test for an error or unusual condition using
  an if-statement
~ To restrict the exceptions that a function or method can throw, include a `throw` clause in its
  header, followed by a list of comma-separated exception types in parentheses; this ensures that
  the function can only throw the listed exceptions
~ When to throw an exception:
  1) If several resolutions to an abnormal occurrence are possible, so you want the client to choose
     one
  2) If you detect that a developer has used a method improperly, throw a runtime exception
  3) If you can resolve the unusual situation in a reasonable manner, implement exception handling
     instead of throwing an exception
~ A constructor should throw an exception if it cannot complete its execution successfully, in order
  to prevent a client's use of a malformed object--be sure to return any allocated memory to free
  store to prevent memory leaks
~ Only `logic_error` exceptions and its descendant exceptions can be handled
~ In general, the `new` operator should not be used inside of a `try` block, because an exception will
  complicate determination of memory allocation and deallocation; otherwise, the following `catch`
  blocks must include memory deallocation statements
~ When an exception occurs in a `try` block, the block's local object destructors are called to release
  all allocated resources in the block
~ A `try` block should contain as few statements as possible--ideally, only the statement that may
  throw an exception
~ Every exception class in the C++ Standard Library defines the accessor method `what`, which returns
  a descriptive string created when the exception is thrown
~ `catch` blocks must be ordered so that the most specific exception classes are caught before the
  more general exception classes
~ Best practice is to avoid using `exception` in a `catch` block
~ Whether or not to place a `try` block inside a loop body or wrapped around the loop is a design
  choice; the wrong choice may not deliver the best information for resolving it to the client
~ Programmer-defined exceptions can implement additional error details than the standard exception
  classes
*/

class ProgrammerDefinedException: public exception {
    public:
        ProgrammerDefinedException(const string& message="") : exception("Custom exception message: " + message) {}
};

int main() {

    try {
        // Implement statement that may throw an exception
    } catch (invalid_argument logicError) {
        cout << "Invalid argument: " << logicError.what() << endl;
        // Implement invalid_argument fix
    } catch (length_error logicError) {
        cout << "Length error: " << logicError.what() << endl;
        // Implement length_error fix
    } catch (out_of_range logicError) {
        cout << "Out of range: " << logicError.what() << endl;
        // Implement out_of_range fix
    } catch (exception generalError) {
        cout << "Some error occurred: " << generalError.what() << endl;
        // Implement general fix
    }

    throw ProgrammerDefinedException("Programmer-defined exception throwing");

    return 0;
}