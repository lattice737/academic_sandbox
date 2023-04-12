// Chapter 12 Concepts

#include<iostream>
#include<iomanip>
#include<cctype>
#include<cstring>
#include<sstream>
#include<string>

using namespace std;

/*
Vocabulary
==========
* C-string - a sequence of characters stored in consecutive memory locations and terminated by a null character
* String literal (or string constant) - a character sequence enclosed in double quotes and written directly into a program

General
=======
~ The `string` library should be preferred over C-strings, because it provides many useful string-related functions and safeguards that
  C-strings do not
~ Understanding C-strings is essential, because the `string` class is built on top of C-strings, there exist programs that were written with C-strings
  before the `string` library was implemented, and C-strings must be used to represent string data when writing & maintaining low-level code
~ C-string representations:
  1) String literals
  2) Programmer-defined character arrays
  3) Character pointers (e.g. type char*)
~ The address of the first character of the character array represents a string literal's value
~ Using a "pointer to char" means using a pointer that references a C-string that has already been allocated as a string literal or a programmer-
  defined array
~ An advantage of using a pointer variable C-string representation is the ability to point to different C-strings
~ If an array holding the first string in a strcat() call is not large enough to hold both strings, strcat() will overflow the array boundaries--test
  using `sizeof(string1) >= (strlen(string1) + strlen(string2) + 1)`
~ C-strings cannot be compared using relational operators because they compare the C-string addresses rather than the values contained in the string
  arrays
~ Literal comparisons will usually yield false, because most compilers do not check to verify that a string literal has been encountered before, so
  the strings will be stored at different addresses
~ istringstream and ostringstream have the full power of ostream and istream objects but require sstream objects in order to simply use insertion
  and extraction operators for conversions
~ to_string() cannot handle conversion of integers to bases other than 10--an ostringstream object should be used for that conversion
~ Type size_t is defined in the standard library and is commonly used to represent an unsigned integer that is the size of, or an index into, an array,
  vector, or string
~ String constructors:
  1) string() - default constructor that creates an empty string (e.g. string str())
  2) string(const char* s) - convert constructor that produces a string object from C-string s
  3) string(const string& s) - copy constructor that produces a new string object from string object s
*/

int main() {
     char character,
          lowerCaseChar = 'a',
          upperCaseChar = 'B';

     // Character-testing functions

     cout << "\nEnter a character: ";
     cin >> character;
     cout << "isalpha('a') == " << isalpha(character) << endl
          << "isalnum('a') == " << isalnum(character) << endl
          << "isdigit('a') == " << isdigit(character) << endl
          << "islower('a') == " << islower(character) << endl
          << "isprint('a') == " << isprint(character) << endl
          << "ispunct('a') == " << ispunct(character) << endl
          << "isupper('a') == " << isupper(character) << endl
          << "isspace('a') == " << isspace(character) << endl;

     // Character-converting functions

     cout << "toupper('a') returns: " << toupper(lowerCaseChar) << endl
          << "tolower('B') returns: " << tolower(upperCaseChar) << endl;

     // String-literal character array

     const char* characterPointer = nullptr;
     characterPointer = "Hello World!";

     // Programmer-defined character array

     const int N_CHARS = 30;
     char definedCharArray[N_CHARS], 
          initializedCharArray[N_CHARS] = "Programming Fundamentals II",
          implicitCharArray[] = "Computer Organization & Machine Language";
     
     // Inputting characters to a C-string

     cout << "\nEnter a sentence less than 30 characters to store: ";
     cin.getline(definedCharArray, N_CHARS);
     cout << "\nThe sentence you entered is:";

     for (int i; definedCharArray[i] != '\0'; i++)
          cout << definedCharArray[i];

     // Character pointers to operate on an existing C-string

     char* anotherCharPointer;
     
     anotherCharPointer = implicitCharArray; // point to an existing C-string
     cout << anotherCharPointer << endl;
     
     anotherCharPointer = "Jane Doe";        // point to a different C-string
     cout << anotherCharPointer << endl;
          
     // Dynamically-allocated C-string

     const int NAME_LENGTH = 50;
     char* namePointer = nullptr;
     
     namePointer = new char[NAME_LENGTH];    // allocate heap memory for C-string

     cout << "\nEnter your full name: ";
     cin.getline(namePointer, NAME_LENGTH);  // memory must be allocated in order for this line to execute
     cout << "Hello, " << namePointer << endl;

     delete [ ] namePointer;  // free the memory after use
     namePointer = nullptr;

     // Built-in C-string functions

     char name[NAME_LENGTH] = "Marie ",
          surname[] = "Curie",
          someone[NAME_LENGTH];
     
     strcat(name, surname);  // result stored in 1st param reference
     strcpy(someone, "Fritz Haber");

     cout << "strlen(characterPointer) == " << strlen(characterPointer) << endl // length of string + 1
          << "strcat(name, surname) result: " << name << endl                   // surname variable will be unchanged
          << "strcpy(someone, \"Fritz Haber\") result: " << someone << endl
          << "strcmp(name, someone) == " << strcmp(name, someone) << endl;      // -ve when alphabetically before, +ve when alphabetically after, 0 when equal

     // String stream objects

     istringstream inputStream,
                   primes("2 3 5 7 11");
     ostringstream outputStream;
     const char* cString = "Fibonacci 0 1 1 2 3";
     int prime1, prime2, prime3, a, b, c, d, e;
     string sequence;

     // read input stream to variables
     primes >> prime1 >> prime2 >> prime3;
     outputStream << (prime1 + prime2 + prime3) / 3 << '\n';

     // read C-string to stream
     inputStream.str(cString);
     inputStream >> sequence >> a >> b >> c >> d >> e;
     outputStream << (a + b + c + d + e) / 5 << '\n';

     // change output mode to hex
     outputStream << hex;
     outputStream << 42;
     cout << outputStream.str();

     // to_string() & stoX() family

     string lifeUniverseEverything = to_string(42),
            miscellaneous = "-342.57is a number",
            binary = "010010is binary";
     double decimal;
     int integer,
         binaryInteger;
     size_t stop;

     decimal = stod(miscellaneous, &stop);   // parse string numeric to double; stop is subscript 7
     integer = stoi(miscellaneous, &stop);   // parse string numeric to integer; stop is subscript 4
     binaryInteger = stoi(binary, &stop, 2); // parse string binary to integer; stop is subscript 5

     // String class member functions
     // TODO

     string sentence = "",
            phrase = "",
            word = "";

     sentence.append(word);
     sentence.append(word, 2, 4);
     sentence.append(word, 4);
     sentence.append(5, '*');
     sentence.assign(phrase);
     sentence.at(5);
     sentence.begin();
     sentence.capacity();
     sentence.clear();
     sentence.compare(phrase);
     phrase.copy(word, 2, 4);
     phrase.c_str();
     phrase.data();
     phrase.empty();
     phrase.end();
     phrase.erase(2, 4);
     phrase.find(word, 4);
     phrase.find('\n', 2);
     phrase.insert(4, word);
     phrase.length();
     phrase.replace(2, 4, word);
     phrase.size();
     phrase.substr(2, 4);
     phrase.swap(word);

     return 0;
}

int countChars(const char* pointer, char ch) {
     int count = 0;
     while (*pointer != '\0') {
          if (*pointer == ch) count++;
          pointer++;
     }
     return count;
}