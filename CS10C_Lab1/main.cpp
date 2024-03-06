/*#include <iostream>

#include "Playlist.h"

using namespace std;

int main() {
  // REMOVE: The zybook wants you to hold onto the playlist title in
  // REMOVE: main.  I would have liked it as a member of the Playlist
  // REMOVE: but please follow the Zybook Lab prompt here
  string title;
  cout << "Enter playlist's title:" << endl;
  cin >> title;

  // Build a playlist which we will use to execute the commands
  // in the loop below
  Playlist P;

  while(true) {
    P.PrintMenu(title);

    // Read commands until error or end-of-file
    // It is much better to read a string here than a character
    // because it will read a single "chunk" of characters and
    // we don't have to deal with problems reading a character
    // without a newline, or when we make a mistake and don't
    // prompt for something that we needed.
    string command;
    if (!(cin >> command)) break;

    // We support seven commands.  The Lab prompt says only
    // to prompt again on error... so we don't output any message
    // on a bad command
    if (command == "a") {
      string id;
      string name;
      string artist;
      int time;
      cin >> id;
      cin >> name;
      cin >> artist;
      cin >> time;
      P.AddSong(id,name,artist,time);
    } else if (command == "d") {
      P.RemoveSong();
    } else if (command == "c") {
      P.ChangePositionSong();
    } else if (command == "s") {
      P.OutputSongsByArtist();
    } else if (command == "t") {
      P.OutputTotalTime();
    } else if (command == "o") {
      P.OutputFullPlaylist();
    } else if (command == "q") {
      break;
    }
  }

  // If cin is in an error state (even end-of-file), then
  // something went wrong
  if (!cin) {
    cout << "Program did not exit cleanly" << endl;
    return 1;
  }
  
  return 0;
}*/

#include <iostream>

#include "Playlist.h"

using namespace std;

int main() {
  // REMOVE: The zybook wants you to hold onto the playlist title in
  // REMOVE: main.  I would have liked it as a member of the Playlist
  // REMOVE: but please follow the Zybook Lab prompt here
  string title;
  cout << "Enter playlist's title:" << endl;
  getline(cin, title);

  // Build a playlist which we will use to execute the commands
  // in the loop below
  Playlist P;

  while(true) {
    P.PrintMenu(title);

    // Read commands until error or end-of-file
    // It is much better to read a string here than a character
    // because it will read a single "chunk" of characters and
    // we don't have to deal with problems reading a character
    // without a newline, or when we make a mistake and don't
    // prompt for something that we needed.
    string command;
    if (!(cin >> command)) break;

    // We support seven commands.  The Lab prompt says only
    // to prompt again on error... so we don't output any message
    // on a bad command
    if (command == "a") {
      string id;
      string song;
      string artist;
      int length;

      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> id;
      if (!cin) {
        throw runtime_error("Couldn't read id");
        return 1;
      }
      cin.ignore();
      cout << "Enter song's name:" << endl;
      getline(cin, song);
      if (!cin) {
        throw runtime_error("Couldn't read song name");
        return 1;
      }
      cout << "Enter artist's name:" << endl;
      getline(cin, artist);
      if (!cin) {
        throw runtime_error("Couldn't read artist name");
        return 1;
      }
      cout << "Enter song's length (in seconds):" << endl;
      cin >> length;
      if (!cin) {
        throw runtime_error("Couldn't read song length");
        return 1;
      }

      P.AddSong(id, song, artist, length);
    } else if (command == "d") {
      P.RemoveSong();
    } else if (command == "c") {
      P.ChangePositionSong();
    } else if (command == "s") {
      P.OutputSongsByArtist();
    } else if (command == "t") {
      P.OutputTotalTime();
    } else if (command == "o") {
      cout << title << " - OUTPUT FULL PLAYLIST" << endl;
      P.OutputFullPlaylist();
    } else if (command == "q") {
      break;
    }
  }

  // If cin is in an error state (even end-of-file), then
  // something went wrong
  if (!cin) {
    cout << "Program did not exit cleanly" << endl;
    return 1;
  }
  
  return 0;
}

