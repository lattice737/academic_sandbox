//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 04/14/2023
// Status    : Completed
//
// This program accepts a user-defined C-string and performs case-
// changing operations on it 
//******************************************************************

#include<iostream>
#include<iomanip>
#include<cctype>

using namespace std;

void upper(char*);
void lower(char*);
void flip(char*);

int main() {
    const int N = 100;  // C-string character limit
    char userEntry[N];  // User-defined C-string
    int padding = 46;   // Whitespace padding

    // Take user input as C-string

    cout << "\nEnter text less than " << N << " characters: ";
    cin.getline(userEntry, N-1);
    padding += sizeof(userEntry[0]) / sizeof(userEntry);

    // Display the C-string and invert, lower, and capitalize the C-string

    cout << setw(padding)
         << left << "Your string is: "
         << right << "\"" << userEntry << "\"" << endl;
    
    
    flip(userEntry);
    cout << setw(padding)
         << left << "Your string with inverted-case characters is: "
         << right << "\"" << userEntry << "\"" << endl;
    

    lower(userEntry);
    cout << setw(padding)
         << left << "Your string lowercased is: "
         << right << "\"" << userEntry << "\"" << endl;
    
    upper(userEntry);
    cout << setw(padding)
         << left << "Your string capitalized is: "
         << right << "\"" << userEntry << "\"";

    return 0;
}

// Capitalizes the characters of a passed C-string
void upper(char* string) {
    int i = 0;  // char index accumulator
    while (string[i] != '\0') {
        string[i] = toupper(string[i]);
        i++;
    }
}

// Lowercases the characters of a passed C-string
void lower(char* string) {
    int i = 0;  // char index accumulator
    while (string[i] != '\0') {
        string[i] = tolower(string[i]);
        i++;
    }
}

// Inverts the case of a passed C-string's characters
void flip(char* string) {
    int i = 0;  // char index accumulator
    while (string[i] != '\0') {
        string[i] = isupper(string[i]) ? tolower(string[i]) : toupper(string[i]);
        i++;
    }
}