#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
using namespace std;
class Music {
public:
    Music();
    Music(const Music& orig);
    ~Music();
    
    string getArtistName();
    string getSongTitle();
    int getSongLength();
    int getTracks();
    int getReleaseDate();
    
    void setArtistName(string artistName);
    void setSongTitle(string songTitle);
    void setSongLength(int songLength);
    void setTracks(int tracks);
    void setReleaseDate(int releaseDate);
    void Print();
    void printAge();
    
private:
    string ArtistName;
    string SongTitle;
    int SongLength;
    int Tracks;
    int ReleaseDate;

};

#endif 

