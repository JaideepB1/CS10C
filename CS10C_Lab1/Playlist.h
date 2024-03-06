// -*-c++-*-

// PROFPAT: Use this pragma in your header files.  It will save
// PROFPAT: you a lot of grief in your career.  You sometimes see
// PROFPAT: this with #define/#ifdef guards, but this is better
// PROFPAT: and safer since it works regardless of where the file
// PROFPAT: lives and cannot be spooffed with an accidental
// PROFPAT: #define
#pragma once



#include <iostream>
using namespace std;

class PlaylistNode {
  // PROFPAT: Printer methods should be defined as const
  // PROFPAT: since they don't change anything. Accessors
  // PROFPAT: that return internal pointers are normally defined
  // PROFPAT: as both const AND non-const.  Accessors that return
  // PROFPAT: large structures like strings/vectors typically
  // PROFPAT: are const AND return const references (e.g. GetSongName()
  // PROFPAT: should return a const string&) Accessors that return
  // PROFPAT: small items like ints or doubles are just const that
  // PROFPAT: return a non-const value like 'int myIntVal() const;'

  string uniqueID;
  string songName;
  string artistName;
  int songLength;
  PlaylistNode* nextNodePtr;
public:
  PlaylistNode() 
    : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(0)
  {}
  PlaylistNode(const string uniqueID, const string songName, const string artistName, int songLength, PlaylistNode* nextNodePtr)
    : uniqueID(uniqueID), songName(songName), artistName(artistName), songLength(songLength), nextNodePtr(nextNodePtr)
  {}
  void insertAfter(PlaylistNode* node) { this->nextNodePtr = node; }
  void SetNext(PlaylistNode* node) { nextNodePtr = node; }
  const string& GetID() const { return uniqueID; }
  const string& GetArtistName() const { return artistName; }
  const string& GetSongName() const { return songName; }
  int GetSongLength() const { return songLength; }
  PlaylistNode* GetNext() { return nextNodePtr; }
  const PlaylistNode* GetNext() const { return nextNodePtr; }
  const void PrintPlaylistNode() const {
    cout << "Unique ID: " << uniqueID << '\n';
    cout << "Song Name: " << songName << '\n';
    cout << "Artist Name: " << artistName << '\n';
    cout << "Song Length (in seconds): " << songLength;
  }
};

class Playlist {
  PlaylistNode* head;
  PlaylistNode* tail;
public:
  // PROFPAT: Please use the : form to initialize member variables
  // PROFPAT: This is the proper, professional way to do it
  // PROFPAT: It is also acceptable to use the C++14 style
  // PROFPAT: method where you would say 'PlaylistNode* head = nullptr;'
  // PROFPAT: above
  Playlist()
    : head(nullptr),tail(nullptr)
  {}
  // PROFPAT: I added the complete headers for PrintMenu() and
  // PROFPAT: AddSong() for you
  void PrintMenu(const string& title) const;
  void AddSong(const string& id, const std::string& song, const std::string& artist, int length);
  void RemoveSong();
  void ChangePositionSong();
  void OutputSongsByArtist() const;
  void OutputTotalTime() const;
  void OutputFullPlaylist() const;
};

