// Chapter 13 Reading Notes

#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>

using namespace std;

/*
Vocabulary
==========
* Input stream - a sequence from which data can be read
* Output stream - a sequence from which data can be written
* Input-output stream - a sequence of data that allows both reading and writing
* Buffer flush - an OS practice where buffered data is written to the disk when a file is closed, in order to prevent data loss
  due to power failure or some other abnormal program termination
* File open mode - a setting that determines how a file can be used
* Record - a complete set of fields that characterize a single item of a dataset
* Parsing - the conversion of string representation to numeric values
* Formatting - the conversion of numeric values to string representation
* Binary data - data expressed in unformatted form; the content of binary files
* Text file - a file containing formatted data
* Object serialization - the process of transforming complex networks of objects interconnected through pointers into a form that
  can be stored in a file or some other medium outside central memory
* 

General
=======
~ C++ Stream Classes:
  1) Standard input & output: istream, ostream, fstream
  2) File input & output: ifstream, ofstream
  3) String reading & writing: istringstream, ostringstream
~ File Mode Flags:
  * Use the bitwise or `|` to combine modes
  1) app (append) - output to take place at the end of the file
  2) ate (at end) - output to initially take place at the end of the file
  3) binary - data read or written is binary
  4) in (input) - allow input operations
  5) out (output) - allow output operations
  6) trunc (truncate) - discard preexisting content and truncate file size to zero
~ Open files use OS resources, so it's important to close files when they are no longer needed
~ ios::out alone clears a file; combined with ios::app, new data will be appended to the end of the file
~ All stream objects have error state bits that indicate the condition of the stream
~ File Condition Bit Flags:
  1) ios::eofbit - set when the end of an input stream is encountered
  2) ios::failbit - set when an attempted operation has failed
  3) ios::hardfail - set when an unrecoverable failure has occurred
  4) ios::badbit - set when an invalid operation has been attempted
  5) ios::goodbit - set when none of the above flags are set; signals good condition
~ A stream object behaves as a Boolean expression that is true when no error flags are set and false otherwise
~ ifstream, fstream, and istringstream each have a family of get() member functions that can be used to read single
  characters
~ The peek() function is useful when you need to know what kind of data is about to be read without actually reading
~ Numeric characters are best read with `>>` and non-numeric characters are best read with get() or getline()
~ To "rewind" a file, the end of file flag must be cleared before calling seekg():
  >>> inputStream.clear();
  >>> inputStream.seekg(0L, ios::beg);
~ The write() member function of ostream & ofstream does not distinguish between numeric data types in the buffer; it
  treats the buffer as an array of bytes
~ Structures containing pointers cannot be correctly stored to the disk using this chapter's techniques, because when
  the structure is read into memory on subsequent program runs, program variables cannot be guaranteed to be at the
  same memory locations
~ File Positioning Flags:
  1) ios::beg - calculate offset from file beginning
  1) ios::end - calculate offset from file end
  1) ios::cur - calculate offset from current position in file
~ Negative offset with seekg() and seekp() navigates backward in the file
~ 
*/

int main() {
    fstream inFile, outFile, inOutFile;

    // File streams

    inFile.open("in.txt", ios::in);
    outFile.open("out.txt", ios::out);
    inOutFile.open("inOut.txt", ios::in | ios::out);

    // IO manipulators

    // dec          // display subsequent numerics as decimals
    // endl
    // fixed
    // flush        // flush output stream
    // hex
    // left
    // oct
    // right
    // scientific   // display floats using scientific notation
    // setfill(ch)  // pad with ch 
    // setprecision(n)
    // setw(n)
    // showbase     // display numeric bases
    // noshowbase
    // showpoint
    // noshowpoint
    // showpos      // display '+' with positive numbers
    // noshowpos

    // Bit flag member functions

    inOutFile.eof();
    inOutFile.fail();
    inOutFile.bad();
    inOutFile.good();
    inOutFile.clear();

    // Reading & writing member functions

    string variable;
    char character='a';
    ostringstream outputStream("Hello World!");
    istringstream inputStream("To be or not to be");

    getline(inOutFile, variable, '\n'); // string library
    inOutFile.get();
    inOutFile.get(character);
    inOutFile.peek();                   // return next char and remove it from stream--does not actually read
    outputStream.put(111);              // writes the integer code (ASCII) of a character to the stream

    // Random file access
    long inputCursor, outputCursor;

    inputStream.seekg(0L, ios::beg);        // "seek get": move to beginning of input file
    outputStream.seekp(0L, ios::beg);       // "seek put": move to beginning of output file
    inputCursor = inputStream.tellg();      // "tell get"
    outputCursor = outputStream.tellp();    // "tell put"

    // Address of the buffer to be interpreted as a pointer to char
    double digit = 45.9;
    double* digitPointer = &digit;
    char* charPointer;  // C++ does not support byte pointers; address of a buffer should be a char pointer

    charPointer = reinterpret_cast<char*>(digitPointer);    // type cast to have the compiler interpret the bits of one type as a different type

    // Binary writing & reading
    double digitArray[3] = { 12.3, 45.8, 19.0 };
    ofstream anotherOutputFile("stuff.dat", ios::binary);
    ifstream anotherInputFile;

    anotherOutputFile.write(reinterpret_cast<char*>(&digit), sizeof(digit));
    anotherOutputFile.write(reinterpret_cast<char*>(digitArray), sizeof(digitArray));
    anotherInputFile.read(reinterpret_cast<char*>(digitArray), sizeof(digitArray));

    return 0;
}