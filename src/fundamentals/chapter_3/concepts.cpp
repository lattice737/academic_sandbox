// Chapter 3 Concepts

#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<ctime>

using namespace std;

/*
Vocabulary
==========
* Stream extraction operator - `>>`
* Input buffer - the memory used to temporarily hold user input, until it is converted to a data type and assigned
* Expression - something that produces a single value when it's evaluated
* Operator precedence - the evalution sequence of two operators on a single operand
* Associativity - the order in which an operator works with its operands; either left-to-right or right-to-left
* Arguments - information that is sent to a function
* Coercion - The conversion of operands to match data type in order to evaluate an operation; either promotion or demotion
* Type cast expression - manual value promotion/demotion
* C-tyle cast - Manual type casting using prefix notation
* Prestandard cast - Manual type casting using functional notation
* Overflow - Unintended high-order bit representation of a value for a signed data type
* Underflow - Unintended lack of precision in a data type for values close to zero, producing a zero value
* Field width - the minimum number of character positions to use when displaying a value
* Member function - a function built into an object
* Array - a group of memory cells
* C-string - a string defined as a group of characters
* Buffer overrun - the overwriting of memory cells following those reserved for a C-string when a string larger than the allocated
                   length is assigned to a defined C-string
* Hand tracing - a debugging approach where the developer reads each statement one at a time, like a computer would execute them

General
=======
~ If a float is input to an int variable, the fractional digits are kept in the i/o stream
  (WARNING: this will affect following cin statements)
~ Unary negation has right-to-left associativity
~ C++ does not have an exponent operator; use pow(base: double, exponent: double)
~ Numeric data type ranking:
  long double > double > float > unsigned long long > long long > unsigned long > long > unsigned > int
  (Exception: when len(int) = len(long int), unsigned > long)
~ Mathematical expression rules:
  1) char, short, and unsigned short are promoted to int
  2) When operands have different type, the lower-ranking type is promoted to the higher-ranking type
  3) The value of an evaluated expression is converted to its assigned variable data type
~ Coercion does not modify a variable--conversion takes place on a copy of a variable's value
~ Precendence of combined assignment operators is lower than regular arithmetic operators
~ Precision setting persists after being modified
~ cin stops reading input when it reaches a newline character, but that newline char stays in the keyboard buffer
~ C-strings cannot be assigned a value with the assignment operator-- use strcpy()
~ C-string cin stops reading characters if it reads a whitespace before reaching the specified number of characters
*/

int main() {
    const double PI = 3.14159,
                 E = 2.71828;
    const int METERS_IN_MI = 160,
              WORD_SIZE = 25,
              SENTENCE_SIZE = 81,
              UPPER_BOUND = 100,
              LOWER_BOUND = 25;
    double radius,
           circle_area = PI * pow(radius, 2),
           doubleValue = 3.7,
           booksPerMonth,
           mondaySales = 321.57,
           tuesdaySales = 269.60,
           wednesdaySales = 307.00,
           totalSales,
           otherDouble = 456.0,
           x = 3,
           y = 4,
           absoluteValue,
           cosine,
           exponential,
           modulus,
           logarithm,
           log_base10,
           exponent,
           rounded,
           sine,
           square_root,
           tangent,
           hypotenuse;
    int integerValue,
        otherInteger = 3,
        thirdInteger = 7,
        books = 10,
        months = 6,
        ascii = 100,
        first_counter,
        second_counter,
        vonnegut_size,
        randomValue,
        otherRandomValue,
        timeRandomValue,
        randomizerCeiling = 99,
        fourthRandomValue,
        boundedRandomValue;
    unsigned seed,
             timeSeed;
    string name,
           vonnegut = "So it goes.",
           stars,
           first_string;
    char inputChar,
         anotherChar,
         charArray[WORD_SIZE] = "Initialized C-string",
         anotherCharArray[WORD_SIZE],
         inputCharArray[5],
         anotherInputCharArray[5],
         sentence[SENTENCE_SIZE];

    // input
    cout << "What is the radius of your circle? ";
    cin >> radius;
    cout << "Your circle has area " << circle_area << "square units\n";

    // type casting
    integerValue = static_cast<int>(doubleValue);
    cout << "\nDouble " << doubleValue << " is now typecast to integer " << integerValue << endl;

    booksPerMonth = static_cast<double>(books) / months; // type cast to prevent integer division
    cout << "\nYou plan to read " << books << " books at a rate of " << booksPerMonth << " books/mo\n";

    cout << "\nASCII value " << ascii << " represents character \'" << static_cast<char>(ascii) << "\'\n";
    cout << "C-style cast: int " << otherInteger << " -> (double)otherInteger -> double " << (double)otherInteger << endl;
    cout << "Prestandard cast: int " << thirdInteger << " -> double(thirdInteger) -> double " << double(thirdInteger) << endl;

    // multiple assignment
    first_counter = second_counter = 0;

    // combined (or compound or arithmetic) assignment operators
    first_counter += 1;
    second_counter -= -1;
    first_counter *= 1;
    second_counter /= 1;
    first_counter %= 2;

    // field width formatting (right-justified by default)
    cout << endl;
    cout << setw(8) << PI << setw(8) << E << endl;
    cout << setw(8) << first_counter << setw(8) << second_counter << endl;

    // significant figure precision formatting (six sigfigs by default)
    cout << endl;
    cout << setprecision(2) << circle_area << " square units\n";

    // fixed-point formatting
    totalSales = mondaySales + tuesdaySales + wednesdaySales;
    cout << "\n\nSales Figures\n";
    cout << "-------------\n";
    cout << fixed << setprecision(2); // fixed modifies the behavior of setprecision()
    cout << "Day 1: " << setw(8) << mondaySales << endl;
    cout << "Day 2: " << setw(8) << tuesdaySales << endl;
    cout << "Day 3: " << setw(8) << wednesdaySales << endl;
    cout << "Total: " << setw(8) << totalSales << endl;

    cout << "\nDefault float output: " << otherDouble << endl;
    cout << "showpoint: " << showpoint << otherDouble << endl; // "show the decimal"
    cout << "setprecision (sigificant figures): " << setprecision(2) << otherDouble << endl; // "show me this number of digits"
    cout << "setprecision + fixed (fractional places): " << fixed << otherDouble << endl; // "show me this number of decimal places"

    // justifiers
    cout << endl;
    cout << fixed << showpoint << setprecision(1); // showpoint is optional here
    cout << left << setw(10) << "Day" << right << setw(6) << "Sales\n";
    cout << left << setw(10) << "Monday" << right << setw(6) << mondaySales << endl;
    cout << left << setw(10) << "Tuesday" << right << setw(6) << tuesdaySales << endl;
    cout << left << setw(10) << "Wednesday" << right << setw(6) << wednesdaySales << endl;

    // string (with whitespace) input
    cout << "\nEnter your full name: " << endl;
    getline(cin, name);

    // character input
    cin.ignore(5, '\n'); // ignore the next 5 characters in the buffer or until a newline character is reached
    cout << "\nEnter a character: " << endl;
    cin.get(inputChar);

    cin.ignore(); // ignore the next character in the buffer
    cout << "Enter another character" << endl;
    inputChar = cin.get();

    cin.ignore();
    cout << "Press Enter to continue" << endl;
    cin.get();

    // string member functions
    vonnegut_size = vonnegut.length();
    stars.assign(10, '*');
    first_string = stars + " Hello, world ";
    first_string += stars;

    // C-strings
    strcpy(anotherCharArray, "Assigned C-string");

    // TODO need cin.ignore()?
    cout << "\nEnter a string with no spaces: ";
    cin >> setw(5) >> inputCharArray; // limits number of read in characters to 4 (1 less than setw arg); fifth byte reserved for /0
    
    // TODO need cin.ignore()?
    cout << "\nEnter another string without spaces: ";
    cin.width(5); // works the same as setw() + C-string
    cin >> anotherInputCharArray;

    // TODO need cin.ignore()?
    cout << "\nEnter a sentence: ";
    cin.getline(sentence, SENTENCE_SIZE); // will store up to 80 characters; 81st reserved for /0
    cout << "Your sentence: \'" << sentence << "\'";

    // mathematical library functions
    absoluteValue = abs(x);
    cosine = cos(x);
    exponential = exp(x);
    modulus = fmod(x, y);
    logarithm = log(x);
    log_base10 = log10(x);
    exponent = pow(x, y);
    rounded = round(x);
    sine = sin(x);
    square_root = sqrt(x);
    tangent = tan(x);
    hypotenuse = sqrt(pow(x, 2) + pow(y, 2));

    // random numbers
    randomValue = rand();

    // TODO add cin.ignore()?
    cout << "\nEnter a seed value: ";
    cin >> seed;
    srand(seed);
    otherRandomValue = rand();
    cout << "\nRandom value " << otherRandomValue << " was generated from your seed: " << seed << endl;

    timeSeed = time(0);
    srand(timeSeed);
    timeRandomValue = rand();
    cout << "Random value " << timeRandomValue << " was generated from time-generated seed: " << timeSeed << endl;

    fourthRandomValue = rand() % randomizerCeiling + 1; // upper-bounded randomizer
    boundedRandomValue = (rand() % (UPPER_BOUND - LOWER_BOUND + 1)) + LOWER_BOUND; // bounded randomizer


    return 0;
}