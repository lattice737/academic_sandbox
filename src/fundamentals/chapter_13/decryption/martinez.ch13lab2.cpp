//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 04/13/2023
// Status    : Completed
//
// 
//******************************************************************

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void validateFilename(string&);

int main() {
    const string PATH="/Users/nicholas/academic_sandbox/src/fundamentals/chapter_13/decryption/";  // Absolute path to dir
    const int KEY=10,           // Encryption key: ASCII bias
              ASCII_LEN=3;      // 
    string filename,            // Filename string to be entered by user
           filestring,          // Original component of filename
           extension,           // File extension
           decryptedFilename,   // New filename variable to be based on original filename
           encryptString;       // 
    fstream originalFile,       // Original file variable
            decryptedFile;      // Encrypted file variable
    bool validFilename;         // Truth of valid filename
    int encryptChar,            // 
        charInt;                // 
    char decryptChar;           // 

    // Take & validate filename and create encrypted filename

    cout << "Enter the file you would like to decrypt (with extension): ";
    cin >> filename;

    validateFilename(filename);

    filestring = filename.substr(0, filename.find("."));
    extension = filename.substr(filename.find("."), filename.length());
    decryptedFilename = filestring + ".decrypt" + extension;
    decryptedFilename = filename.replace(filename.find('.')+1, 7, "decrypt");

    cout << "Decrypted filename: " << decryptedFilename << endl;

    originalFile.open(PATH+filename, ios::in);
    decryptedFile.open(PATH+decryptedFilename, ios::out);

    if (originalFile.fail()) return 1;

    // Decrypt file contents

    do {
        getline(originalFile, encryptString, '/');
        cout << encryptString << endl; // TODO remove
        encryptChar = stoi(encryptString);
        decryptChar = static_cast<char>(encryptChar);
        decryptedFile.put(decryptChar);
    } while (!originalFile.eof());

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