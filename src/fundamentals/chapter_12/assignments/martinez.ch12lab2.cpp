//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 04/13/2023
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
    char userEntry[N];  // User-defined C-string variable

    // Take user input as C-string

    cout << "\nEnter text less than " << N << " characters: ";
    cin.getline(userEntry, N-1);

    // Display the C-string and invert, lower, and capitalize the C-string

    cout << "\nYour string is: \"" << userEntry << "\"" << endl;
    flip(userEntry);
    cout << "Your string with inverted-case characters is: \"" << userEntry << "\"" << endl;
    lower(userEntry);
    cout << "Your string lowercased is: \"" << userEntry << "\"" << endl;
    upper(userEntry);
    cout << "Your string capitalized is: \"" << userEntry << "\"";

    return 0;
}

// Capitalizes the characters of a passed C-string
void upper(char* string) {
    int i = 0;
    while (string[i] != '\0' && isalpha(string[i])) {
        string[i] = toupper(string[i]);
        i++;
    }
}

// Lowercases the characters of a passed C-string
void lower(char* string) {
    int i = 0;
    while (string[i] != '\0' && isalpha(string[i])) {
        string[i] = tolower(string[i]);
        i++;
    }
}

// Inverts the case of a passed C-string's characters
void flip(char* string) {
    int i = 0;
    while (string[i] != '\0' && isalpha(string[i])) {
        string[i] = isupper(string[i]) ? tolower(string[i]) : toupper(string[i]);
        i++;
    }
}