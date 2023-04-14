//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 04/13/2023
// Status    : Completed
//
// This program decrypts a file encrypted using an ASCII bias
// encryption scheme and writes the contents to a new file
//******************************************************************

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void validateFilename(string&);

int main() {
    const string PATH="/Users/nicholas/academic_sandbox/src/fundamentals/chapter_13/decryption/";  // Absolute path to dir
    const int KEY=10;           // Encryption key: ASCII bias
    string filename,            // Filename string to be entered by user
           filestring,          // Original component of filename
           extension,           // File extension
           decryptedFilename,   // New filename variable to be based on original filename
           encryptString;       // ASCII value as string
    fstream originalFile,       // Original file variable
            decryptedFile;      // Encrypted file variable
    bool validFilename;         // Truth of valid filename
    char decryptChar;           // Actual character decrypted from ASCII string
    int encryptChar;            // ASCII value as integer


    // Take & validate filename and create decrypted filename

    cout << "Enter the file you would like to decrypt (with extension): ";
    cin >> filename;

    validateFilename(filename);

    filestring = filename.substr(0, filename.find("."));
    extension = filename.substr(filename.find(".")+8, filename.length());
    decryptedFilename = filestring + ".decrypt" + extension;

    cout << "Decrypted filename: " << decryptedFilename << endl;

    originalFile.open(PATH+filename, ios::in);
    decryptedFile.open(PATH+decryptedFilename, ios::out);

    if (originalFile.fail()) return 1;

    // Decrypt file contents

    getline(originalFile, encryptString, '/');

    while(!originalFile.eof()) {
        encryptChar = stoi(encryptString);
        decryptChar = static_cast<char>(encryptChar - KEY);
        decryptedFile.put(decryptChar);
        getline(originalFile, encryptString, '/');
    }

    originalFile.close();
    decryptedFile.close();

    return 0;
}

// Return true if the passsed filename string contains ".encrypt."
void validateFilename(string& filename) {
    int count;                  // Number of periods in filename string
    bool validFilename = true;  // Truth of valid filename

    do {
        if (!validFilename) {
            cout << "Filename \"" << filename << "\" is not valid. Enter a valid filename: ";
            cin >> filename;
        }
        validFilename = filename.find(".encrypt.") >= 0;
    } while (!validFilename);
}