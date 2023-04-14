//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 04/13/2023
// Status    : Completed
//
// This program encrypts the contents of a user-selected file
// using a bias for each character's ASCII value
//******************************************************************

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void validateFilename(string&);

int main() {
    const string PATH="/Users/nicholas/academic_sandbox/src/fundamentals/chapter_13/encryption/";  // Absolute path to dir
    const int KEY=10;           // Encryption key: ASCII bias
    string filename,            // Filename string to be entered by user
           filestring,          // Original component of filename
           extension,           // File extension
           encryptedFilename;   // New filename variable to be based on original filename
    fstream originalFile,       // Original file variable
            encryptedFile;      // Encrypted file variable
    bool validFilename;         // Truth of valid filename
    int charInt;                // Integral character value

    // Take & validate filename and create encrypted filename

    cout << "Enter the file you would like to encrypt (with extension): ";
    cin >> filename;

    validateFilename(filename);

    filestring = filename.substr(0, filename.find("."));
    extension = filename.substr(filename.find("."), filename.length());
    encryptedFilename = filestring + ".encrypt" + extension;

    cout << "Encrypted filename: " << encryptedFilename << endl;

    originalFile.open(PATH+filename, ios::in);
    encryptedFile.open(PATH+encryptedFilename, ios::out);

    if (originalFile.fail()) return 1;

    // Encrypt file contents

    charInt = originalFile.get();

    while (charInt != EOF) {
        encryptedFile << charInt + KEY;
        encryptedFile.put('/');
        charInt = originalFile.get();
    }

    originalFile.close();
    encryptedFile.close();

    return 0;
}

// Return true if the passsed filename string has 1 period
void validateFilename(string& filename) {
    int count;                  // Number of periods in filename string
    bool validFilename = true;  // Truth of valid filename

    do {
        // Prompt user for new filename
        if (!validFilename) {
            cout << "Filename \"" << filename << "\" is not valid. Enter a valid filename: ";
            cin >> filename;
        }

        // Count periods in entered filename
        count = 0;
        for (int i=0; i<filename.length(); i++)
            if (filename[i] == '.') count++;

        validFilename = count == 1 ? true : false;

    } while (!validFilename);
}