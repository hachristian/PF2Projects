#include <iostream>
#include "Music.h"
using namespace std;

int main()
{
    cout << "Name: Julio Sibrian " << endl << "ID: 010892197" << endl;
    
    Music song1;
    Music song2(song1);
    string artist = "Kanye"; 
    string title = "Chickfila";
    int releaseDate = 2020;
    int songLength = 3;
    int tracks = 1;
    
    song1.setArtistName(artist);
    song1.setSongTitle(title);
    song1.setReleaseDate(releaseDate);
    song1.setSongLength(songLength);
    song1.setTracks(tracks);
    song1.getArtistName();
    song1.getSongTitle();
    song1.getReleaseDate();
    song1.getSongLength();
    song1.getTracks();
    song1.Print();
    song1.printAge();
    
    return 0;
}