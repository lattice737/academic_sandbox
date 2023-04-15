//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 04/14/2023
// Status    : Completed
//
// This program takes a user inputted sentence that has no spaces
// and capitalized words, displaying the sentence properly formatted
//******************************************************************

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main() {
    const int N=150;    // Sentence character limit
    char sentence[N];   // Sentence C-string array
    int i=0;            // Subscript accumulator

    // Take a sentence with capitalized words and no spaces

    cout << "\nEnter a sentence with less than " << N << " characters and without spaces where each word is capitalized: ";
    cin.getline(sentence, N);
    cout << "\nYour sentence properly formatted is:" << endl;

    // Display the sentence with proper syntax

    while (sentence[i] != '\0') {
        if (i && isupper(sentence[i]))
            cout << ' ' << static_cast<char>(tolower(sentence[i]));
        else
            cout << sentence[i];
        i++;
    }

    return 0;
}