// Chapter 5 Concepts

#include<iostream>
#include<iomanip>
#include<cctype>
#include<fstream>

using namespace std;

/*
Vocabulary
==========
* Loop - a control structure that causes a statement or group of statements to repeat
* Loop control variable - the variable controlling the number of loops iterations
* Priming read - the first validation of a control variable, before a loop
* Postfix mode (e.g. variable++) - increments/decrements after the operand is used in an expression
* Prefix mode (e.g. ++variable) - increments/decrements before the operand is used in an expression
* Counter - a variable that increments/decrements with each iteration of a loop
* Accumulator - a variable that stores a sum of values
* Sentinel - a special value that cannot be mistaken for a collection member, indicating the end of the collection
* Count-controlled loop - a loop that repeats a specific number of times
* Initialization expression - initializes a for loop counter
* Test expression - tests a condition to control the execution of a for loop
* Update expression - a statement that increments the counter variable after each iteration in a for loop
* Text file - contains data that has been encoded using a scheme such as ASCII or Unicode
* Binary file - contains data that hasn't been converted to text
* Sequential access file - a file for which data is accessed from beginning to end (e.g. analogous to cassette tape)
* Random (or direct) access file - a file for which data at any location is accessible (e.g. analogous to MP3 player)
* Filename - disk file identifier
* File stream object - associated with a specific file and provides a way for programs to work with that file
* File buffer - a small portion of memory where file-bound data is first written, until it's full
* Read position - marks the location of the next byte to be read from a file

General
=======
~ The increment/decrement operators cannot operate on literals--only on lvalues
~ Increment/decrement operators should not be used in cout statements
~ A do-while loop must be terminated with a semicolon after the test expression's closing parenthesis
~ toupper() returns an ASCII integer as a literal and a character when assigned to a char type variable
~ Do not modify a for loop's counter variable in the loop body
~ Comma delimiting is not allowed in a for-loop test expression, and file reading
~ while loops are appropriate for input validation, sentinel-controlled looping
~ do-while loops are appropriate for menu-driven programs and user switches
~ for loops are appropriate for cases where the exact number of iterations is known
~ In order for a program to work with a file on a computer's disk, the program must create a file stream object in memory
~ "Stream" objects enable data to be copied from memory to a file and vice-versa
~ Closing files ensures that data in the buffer is written to file and preserves OS resources
~ open() in older versions of C++ do not accept strings--use <string>.c_str()
~ Files have an invisible EOF mark at their end, where `>>` returns false

*/

int main(){
    int integer = 1,
        postfixAssignment,
        prefixAssignment,
        mathInteger = 10,
        postfixProduct,
        prefixProduct,
        accumulator = 0,
        number,
        omittedInitialization = 0,
        omittedUpdate = 0;
    bool postfixRelation,
         prefixRelation,
         iterateTwice = false;
    char runAgain;
    
    // Incrementing & decrementing

    integer += 1;
    integer -= 1;

    cout << "Displays 1: " << integer++;
    cout << "Displays -1: " << --integer;

    postfixAssignment = integer++;
    prefixAssignment = --integer;

    cout << "\nanotherInteger has integer's original value: " << postfixAssignment << endl
         << "integer increments after the assignment: " << integer << endl
         << "thirdInteger has integerToIncrement's decremented value: " << prefixAssignment << endl
         << "integer was decremented before assignment: " << integer;

    postfixProduct = 5 * mathInteger++;
    prefixProduct = ++mathInteger / 12;
    
    cout << "\nPostfixed math expression: " << postfixProduct << endl
         << "Prefixed math expression: " << prefixProduct;

    postfixRelation = postfixProduct-- > 10;
    prefixRelation = --prefixProduct == true;
    
    cout << "\npostfixProduct-- > 10 == 49 > 10 == " << postfixRelation << endl
         << "--prefixProduct == 1 == " << prefixRelation;

    // do-while loops

    do
        cout << "\nThis should only appear once" << endl;
    while (iterateTwice);

    do {
        cout << "\nEnter an integer to add: ";
        cin >> number;
        accumulator += number;
        cout << "\nAdd another number? ";
        cin >> runAgain;
    } while (toupper(runAgain) == 'Y'); // 'Y' is a sentinel

    cout << "\nThe sum of your entered numbers is " << accumulator;

    // for loops

    for (int i = 1; i <= 10; i += 1)
        cout << i * i << endl;

    for (int x = 2, y = 3; x < 100; x += 2, y += 3) {
        cout << "\nNext multiple of 2: " << x << endl
             << "Next multiple of 3: " << y << endl;
    }

    for (; omittedInitialization < 5; integer++) {
        cout << integer << endl;
    }

    for (; omittedUpdate < 5; ) {
        cout << omittedUpdate++;
    }

    for (int headerOnly; headerOnly < 3; headerOnly++);

    // File handling

    string filename = "example.txt",
           path = "/Users/nicholas/academic_sandbox/src/fundamentals/chapter_5/";
    ofstream outputFile(path+filename); // opened during definition
    ifstream inputFile;
    int line;

    outputFile << "Here is some text I would like written to a file" << endl
               << "Here is a variable that I would like written to a file: " << integer << endl;

    outputFile.close();

    inputFile.open(path+filename);
    
    if (inputFile) { // or use inputFile.fail()
        while (inputFile >> line) // reads up to whitespace character (e.g. '\n')
            cout << line;
    } else {
        cout << "A problem occurred when opening the file";
    }

    inputFile.close();

    return 0;
}