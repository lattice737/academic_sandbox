//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 02/24/2023
// Status    : Completed
// 
// This program takes the number of movies seen in a month by
// students surveyed, sorts those values and calculates their
// average
//******************************************************************

#include<algorithm>
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int* allocateStudents(int&);
void getMoviesWatched(int*, int);
void displayMoviesWatched(int*, int);
double calculateAverage(int*, int);

int main() {
    int* moviesWatched = nullptr;   // Pointer to hold integer array of reported movies watched (int)
    int numberOfStudents;           // Size of integer array

    cout << "This program calculates the average number of movies seen in a month by students surveyed\n" << endl;

    // Initialize main array & length
    moviesWatched = allocateStudents(numberOfStudents);

    // Populate, sort, and display array
    getMoviesWatched(moviesWatched, numberOfStudents);
    sort(moviesWatched, moviesWatched+numberOfStudents);
    displayMoviesWatched(moviesWatched, numberOfStudents);
    
    // Display average of array elements
    cout << "Average " << fixed << setprecision(1) << calculateAverage(moviesWatched, numberOfStudents);

    // Return memory to free store
    delete [] moviesWatched;
    moviesWatched = nullptr;

    return 0;
}

// Dynamically allocate student array and return array size based on input number of students
int* allocateStudents(int& studentsSurveyed) {
    // Initial user prompt
    cout << "How many students were surveyed? ";
    cin >> studentsSurveyed;

    // Validate user input
    while (studentsSurveyed < 1) {
        cout << "Entered value must be a positive integer greater than zero. Try again" << endl;
        cout << "How many students were surveyed? ";
        cin >> studentsSurveyed;
    }

    return new int[studentsSurveyed];;
}

// Assign the movies watched values to the array
void getMoviesWatched(int* array, int size) {
    string cardinal;    // Dynamically update prompt based on subscript of element
    int moviesSeen;     // Integral number of movies seen for a given student

    // Populate each student's movies watched value
    for (int i=0; i<size; i++) {
        cardinal = i == 0 ? "first" : (i == size-1 ? "last" : "next");
        cout << "How many movies did the " << cardinal << " student see in a month? ";
        cin >> moviesSeen;
        
        // Validate user input
        while (moviesSeen < 0) {
            cout << "Number of movies seen must be a positive integer. Try again" << endl;
            cout << "How many movies did the " << cardinal << " student see in a month? ";
            cin >> moviesSeen;
        }

        *(array + i) = moviesSeen;
    }
}

// Display movies watched reported by each student
void displayMoviesWatched(int* array, int size) {
    cout << "\nNumber of Movies Watched" << endl
         << "------------------------" << endl;
    for (int i=0; i<size; i++)
        cout << *(array + i) << endl;
    cout << "---------" << endl;
}

// Return the average of an integer array's elements
double calculateAverage(int* array, int size) {
    int total = 0; // Running total of integer array elements
    for (int i=0; i<size; i++)
        total += *(array+i);
    return static_cast<double>(total) / size;
}