//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 04/14/2023
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
string createTargetFilename(string);
void decryptFileContents(fstream&, fstream&);

const int KEY=10;   // Encryption key: ASCII bias

int main() {
    const string PATH="/Users/nicholas/academic_sandbox/src/fundamentals/chapter_13/decryption/";  // Absolute path to dir
    string filename,            // Filename string to be entered by user
           decryptedFilename;   // New filename variable to be based on original filename
    fstream originalFile,       // Original file variable
            decryptedFile;      // Encrypted file variable

    // Take & validate filename and create decrypted filename

    cout << "Enter the file you would like to decrypt (with extension): ";
    cin >> filename;

    validateFilename(filename);
    decryptedFilename = createTargetFilename(filename);

    cout << "Decrypted filename: " << decryptedFilename << endl;

    // Decrypt encrypted file and write to new file

    originalFile.open(PATH+filename, ios::in);
    decryptedFile.open(PATH+decryptedFilename, ios::out);

    if (originalFile.fail()) return 1;

    decryptFileContents(originalFile, decryptedFile);

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
        validFilename = filename.find(".encrypt.") > 0;
    } while (!validFilename);
}

string createTargetFilename(string originalFilename) {
    const int ENCRYPT_STR=8;    // number of characters in "encrypt"
    string filestring,          // String preceding dot in original filename
           extension;           // File extension including dot in original filename
    int dot;                    // Index of dot in original filename

    dot = originalFilename.find(".");
    filestring = originalFilename.substr(0, dot);
    extension = originalFilename.substr(dot+ENCRYPT_STR, originalFilename.length());
    
    return filestring + ".decrypt" + extension;
}

void decryptFileContents(fstream& inputFile, fstream& outputFile) {
    string encryptString;   // ASCII value as string
    char decryptChar;       // Actual character decrypted from ASCII string
    int encryptChar;        // ASCII value as integer

    getline(inputFile, encryptString, '/');

    // Iteratively decrypt each encrypted ASCII value
    while(!inputFile.eof()) {
        encryptChar = stoi(encryptString);
        decryptChar = static_cast<char>(encryptChar - KEY);
        outputFile.put(decryptChar);
        getline(inputFile, encryptString, '/');
    }

    // Close files
    inputFile.close();
    outputFile.close();
}