//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 04/14/2023
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
string createTargetFilename(string);
void encryptFileContents(fstream&, fstream&);

const int KEY=10;   // Encryption key: ASCII bias

int main() {
    const string PATH="/Users/nicholas/academic_sandbox/src/fundamentals/chapter_13/encryption/";  // Absolute path to dir
    string filename,            // Filename string to be entered by user
           encryptedFilename;   // New filename variable to be based on original filename
    fstream originalFile,       // Original file variable
            encryptedFile;      // Encrypted file variable

    // Take & validate filename and create encrypted filename

    cout << "Enter the file you would like to encrypt (with extension): ";
    cin >> filename;

    validateFilename(filename);
    encryptedFilename = createTargetFilename(filename);

    cout << "Encrypted filename: " << encryptedFilename << endl;

    // Encrypt file contents to new file

    originalFile.open(PATH+filename, ios::in);
    encryptedFile.open(PATH+encryptedFilename, ios::out);

    if (originalFile.fail()) return 1;

    encryptFileContents(originalFile, encryptedFile);    

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

// Return the encrypted file's filename based on the original filename
string createTargetFilename(string originalFilename) {
    string filestring,  // String preceding dot in original filename
           extension;   // File extension including dot in original filename
    int dot;            // Index of dot in original filename

    dot = originalFilename.find(".");
    filestring = originalFilename.substr(0, dot);
    extension = originalFilename.substr(dot, originalFilename.length());

    return filestring + ".encrypt" + extension;
}

// Encrypt a passed input file's contents and write to a passed output file
void encryptFileContents(fstream& inputFile, fstream& outputFile) {
    int charInt;    // Integral character value
    
    charInt = inputFile.get();

    // Iteratively write each character ASCII + bias
    while (charInt != EOF) {
        outputFile << charInt + KEY;
        outputFile.put('/');
        charInt = inputFile.get();
    }

    // Close files
    inputFile.close();
    outputFile.close();
}