//******************************************************************
// Programmer: Nicholas Martinez
// Completed : 02/24/2023
// Status    : Completed
// 
// Builds a playlist of 10 songs and their artists from user input
// and displays it sorted by artist (ascending)
//******************************************************************

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct Song {
    string title;
    string artist;
};

void getPlaylist(Song[], int);
void sortPlaylist(Song[], int);
void displayPlaylist(Song[], int);

int main() {
    const int PLAYLIST_SIZE=10;     // Playlist array length
    Song playlist[PLAYLIST_SIZE];   // Playlist array

    getPlaylist(playlist, PLAYLIST_SIZE);
    sortPlaylist(playlist, PLAYLIST_SIZE);
    displayPlaylist(playlist, PLAYLIST_SIZE);

    return 0;
}

// Populates the playlist array from user input (no validation)
void getPlaylist(Song playlist[], int size) {
    string ordinal; // Prompt string specific to the order of the song to be entered
    for (int i=0; i<size; i++) {
        Song newSong;
        ordinal = (i == 0) ? "first" : (i == size-1) ? "last" : "next";
        cout << "Enter the " << ordinal << " song: ";
        getline(cin, newSong.title);
        cout << "Enter this song's artist: ";
        getline(cin, newSong.artist);
        playlist[i] = newSong;
    }
}

// Sorts the playlist in ascending order, by artist (does not sort title for same-artist cases)
void sortPlaylist(Song playlist[], int size) {
    int imin;           // 
    string artistMin;

    // Outer loop evaluates each playlist structure
    for (int i=0; i<size-1; i++) {

        imin = i;
        artistMin = playlist[i].artist;

        // Inner loop compares a given structure to subsequent structures
        for (int j=i+1; j<size; j++) {

            // Continue to next structure if artist is already in proper position
            if (playlist[j].artist > artistMin)
                continue;      

            artistMin = playlist[j].artist;
            imin = j;
        }

        swap(playlist[imin], playlist[i]);
    }
}

// Displays the playlist
void displayPlaylist(Song playlist[], int size) {
    string divider;

    // Display header
    cout << "\nYour playlist:\n"
         << left << setw(25) << "Artist" << left << "Title" << endl
         << divider.assign(55, '=') << endl;

    // Display song titles & artists
    for (int i=0; i<size; i++) {
        cout << left << setw(25) << playlist[i].artist << left << playlist[i].title << endl;
    }
}

// Swaps the values referenced by a & b
void swap(string& a, string& b) {
    string placeholder = a;
    a = b;
    b = placeholder;
}