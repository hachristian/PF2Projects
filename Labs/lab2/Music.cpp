#include "Music.h"

Music::Music() 
{
    cout << "In constructor\n";
    ArtistName = "";
    SongTitle = "";
    SongLength = 0;
    Tracks = 0;
    ReleaseDate = 0;
}

Music::Music(const Music& orig) 
{
    cout << "In copy constructor\n";
    ArtistName = orig.ArtistName;
    SongTitle = orig.SongTitle;
    SongLength = orig.SongLength;
    Tracks = orig.Tracks;
    ReleaseDate = orig.ReleaseDate;
    
}

Music::~Music() 
{
    cout << "In destructor\n";
}

string Music::getArtistName()
{
    cout << "In getArtistName method" << endl;
    return ArtistName;
}

int Music::getReleaseDate()
{
    cout << "In getReleaseDate method" << endl;
    return ReleaseDate;
}

string Music::getSongTitle()
{
    cout << "In getSongTitle method" << endl;
    return SongTitle;
}

int Music::getSongLength()
{
    cout << "In getSongLength" << endl;
    return SongLength;
}

int Music::getTracks()
{
    cout << "In getTracks" << endl;
    return Tracks;
}

void Music::setArtistName(string artistName)
{    
    cout << "In setArtistName method" << endl;
    ArtistName = artistName;
}

void Music::setReleaseDate(int releaseDate)
{
    cout << "In setReleaseDate method" << endl;
    ReleaseDate = releaseDate;
}

void Music::setSongTitle(string songTitle)
{
    cout << "In setSongTitle method" << endl;
    SongTitle = songTitle;
}

void Music::setSongLength(int songLength)
{
    cout << "In setSongLength" << endl;
    SongLength = songLength;
}

void Music::setTracks(int tracks)
{
    cout << "In getTracks" << endl;
    Tracks = tracks;
}

void Music::Print()
{
    cout << ArtistName << endl
    << SongTitle << endl
    << SongLength << endl
    << Tracks << endl
    << ReleaseDate << endl;
}

void Music::printAge()
{
    int year = 2020;
    year = year - ReleaseDate;
    cout << "Song age = " <<  year << endl;
}


