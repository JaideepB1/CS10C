#include "Playlist.h"

//Prints a menu with the options atached
void Playlist::PrintMenu(const string& title) const {
  cout << endl;
  cout << title << " PLAYLIST MENU" << endl;
  cout << "a - Add song" << endl;
  cout << "d - Remove song" << endl;
  cout << "c - Change position of song" << endl;
  cout << "s - Output songs by specific artist" << endl;
  cout << "t - Output total time of playlist (in seconds)" << endl;
  cout << "o - Output full playlist" << endl;
  cout << "q - Quit" << endl;
  cout << endl;
  cout << "Choose an option:" << endl;
}

void Playlist::AddSong(const string& id, const std::string& song, const std::string& artist, int length) {
  //Creates a new node with the function parameters
  PlaylistNode* newNode = new PlaylistNode(id, song, artist, length, nullptr);
  //Sets the head and tail equal to the node if the list is empty
  //If the list is not empty then it is added to the last node in the list and it becomes the new tail
  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  }

  else {
    tail->SetNext(newNode);
    tail = newNode;
  }
}
    
void Playlist::RemoveSong() {
  cout << "REMOVE SONG" << endl;
  cout << "Enter song's unique ID:" << endl;
  string id;
  cin >> id;
  PlaylistNode* prev = head;
  for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) {
    if (curr->GetID() == id) {
      //If the node is the only node in the list
      if (curr == head && curr == tail) {
        head = nullptr;
        tail = nullptr;
        cout << "\"" << curr->GetSongName() << "\"" << " removed." << endl;
        delete curr;
      }

      //If the node is the head and not the tail
      else if (curr == head && curr != tail) {
        head = curr->GetNext();
        cout << "\"" << curr->GetSongName() << "\"" << " removed." << endl;
        delete curr;
      }

      //if the node is the tail and not the head
      else if (curr != head && curr == tail) {
        tail = prev;
        cout << "\"" << curr->GetSongName() << "\"" << " removed." << endl;
        delete curr;
      }

      //if the node is neither the tail nor the head
      else {
        prev->SetNext(curr->GetNext());
        cout << "\"" << curr->GetSongName() << "\"" << " removed." << endl;
        delete curr;
      }
    }

    prev = curr;
  }
}
    
void Playlist::ChangePositionSong() {
  cout << "CHANGE POSITION OF SONG" << endl;

  //Finds the number of nodes in the list
  int n = 1;
  for(const PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) {
    n++;
  }

  //if the current position or new position is less than 1 then it is set to 1
  //if the current position or new position is more than n then it is set to n
  cout << "Enter song's current position:" << endl;
  int currPos;
  cin >> currPos;
  if (!cin) {
    throw runtime_error("Couldn't read current position");
  }
  if (currPos < 1) {
    currPos = 1;
  }
  else if (currPos > n) {
    currPos = n;
  }
  cout << currPos << endl;

  cout << "Enter new position for song:" << endl;
  int newPos;
  cin >> newPos;
  if (!cin) {
    throw runtime_error("Couldn't read new Position");
  }
  if (newPos < 1) {
    newPos = 1;
  }
  else if (newPos > n) {
    newPos = n;
  }
  cout << newPos << endl;

  //Finds the node in the current position, new position,
  // the node just before the current position and the node just before the new position if plausible
  PlaylistNode* currNode;
  int n2 = 0;
  for(PlaylistNode* curr = head; n2 != currPos; curr = curr->GetNext()) {
    currNode = curr;
    n2++;
  }

  PlaylistNode* newNode;
  int n3 = 0;
  for(PlaylistNode* curr = head; n3 != newPos; curr = curr->GetNext()) {
    newNode = curr;
    n3++;
  }

  PlaylistNode* prevCurrNode;
  if (currPos != 1) {
    int n4 = 0;
    for(PlaylistNode* prev = head; n4 != currPos - 1; prev = prev->GetNext()) {
      prevCurrNode = prev;
      n4++;
    }
  }

  PlaylistNode* prevNewNode;
  if (newPos != 1) {
    int n5 = 0;
    for(PlaylistNode* prev = head; n5 != newPos - 1; prev = prev->GetNext()) {
      prevNewNode = prev;
      n5++;
    }
  }
  
  //Get rid of the node in the current position
  if (currPos == 1) {
    head = currNode->GetNext();
  }

  else if (currPos == n) {
    prevCurrNode->SetNext(nullptr);
    tail = prevCurrNode;
  }

  else {
    prevCurrNode->SetNext(currNode->GetNext());
  }

  //Add the node in the current position to the new position
  if (newPos == 1) {
    currNode->SetNext(newNode);
    head = currNode;
  }

  else if (newPos == n) {
    newNode->SetNext(currNode);
    currNode->SetNext(nullptr);
    tail = currNode;
  }

  else if (currPos < newPos) {
    currNode->SetNext(newNode->GetNext());
    currNode->SetNext(currNode);
  }

  else {
    prevNewNode->SetNext(currNode);
    currNode->SetNext(newNode);
  }

  cout << "\"" << currNode->GetSongName() << "\"" << " move to position " << newPos << endl;

}
    
void Playlist::OutputSongsByArtist() const {
  cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
  cout << "Enter artist's name:" << endl;
  string name;
  getline(cin, name);
  cout << name << endl;
  int i = 1;
  //Traverses the for loop to see id the current node's artist name is the input name
  for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) {
    if (name == curr->GetArtistName()) {
      cout << i << "." << endl;
      curr->PrintPlaylistNode();
    }
  }
  i++;
}
    
void Playlist::OutputTotalTime() const {
  cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
  int time = 0;
  // PROFPAT: We write a lot of traversal loops with linked lists
  // PROFPAT: They come in a couple of forms, but this is very
  // PROFPAT: common.  Since this is a 'const' routine, the head
  // PROFPAT: pointer is const, so we use a const curr.
  for(const PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext()) {
    //Traverses the loop and adds the time of the song for each song in the playlist
    time += curr->GetSongLength();
  }
  cout << "Total time: " << time << " seconds" << endl;
}

void Playlist::OutputFullPlaylist() const {
  if (head == nullptr) {
    cout << "Playlist is empty" << endl;
  }

  else {
    int i = 1;
    PlaylistNode* tempNode = head;
    
    while (tempNode->GetNext() != nullptr) {
      cout << i << "." << endl;
      i++;
      tempNode->PrintPlaylistNode();
      cout << endl;
      cout << endl;
      tempNode = tempNode->GetNext();
    }

    cout << i << "." << endl;
    tempNode->PrintPlaylistNode();
    cout << endl;
    tempNode = tempNode->GetNext();
  }
}
    

