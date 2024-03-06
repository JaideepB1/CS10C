#include "IntList.h"

#include <iostream>
#include <exception>

using namespace std;



#include <iostream>
ostream & operator<<(ostream &out, const IntList &rhs) {
  if (rhs.dummyTail->prev->prev == rhs.dummyHead) {
    IntNode* curr = rhs.dummyTail->prev;
    out << curr->data;
  }

  else {
    IntNode* curr = rhs.dummyHead->next;
    while (curr != rhs.dummyTail->prev) {  
      out << curr->data << " ";
      curr = curr->next;
    }  
    out << curr->data;
  }
  return out;
}

IntList::~IntList() {
  // You can't actually throw an exception in a destructor "as-is"
  // throw runtime_error(HERE);
  IntNode* head = dummyHead->next;
  IntNode* next = head->next;
  delete head;
  head = next;
}

void IntList::push_front(int value) {
  //Creates an intNode named newNode
  IntNode* newNode = new IntNode(value);

  if (empty()) {
    //If the list is empty then it sets the dummyheads 
    //next node and dummytails previous node to new node
    dummyHead->next = newNode;
    dummyTail->prev = newNode;
  }

  else {
    //Adds newNode in between firstNode and dummyHead and 
    //rearanges the next and prev for all three nodes
    IntNode* firstNode = dummyHead->next;
    dummyHead->next = newNode;
    newNode->next = firstNode;
    newNode->prev = dummyHead;
    firstNode->prev = newNode;
  }
}

void IntList::pop_front() {
  if (empty()) {
    //throws error if the list is empty
    throw runtime_error("List is empty");
  }

  else {
    //deletes the first node in the lsit and rearanges 
    //the second node and dummyHeads next and prev pointers
    IntNode* firstNode = dummyHead->next;
    IntNode* secondNode = firstNode->next;
    dummyHead->next = secondNode;
    secondNode->prev = dummyHead;
    delete firstNode;
  }
}

void IntList::push_back(int value) {
  IntNode* newNode = new IntNode(value);

  if (empty()) {
    //Adds newNode to the empty list
    dummyHead->next = newNode;
    dummyTail->prev = newNode;
  }

  else {
    //Adds newNode after the lastNode
    IntNode* lastNode = dummyTail->prev;
    dummyTail->prev = newNode;
    newNode->prev = lastNode;
    newNode->next = dummyTail;
    lastNode->next = newNode;
  }
}

void IntList::pop_back() {
  if (empty()) {
    throw runtime_error("List is empty");
  }

  else {
    //Deletes the lastNode and rearanges the secondLast
    // node and the dummyTails next and prev pointers
    IntNode* lastNode = dummyTail->prev;
    IntNode* secondLastNode = lastNode->prev;
    dummyTail->prev = secondLastNode;
    secondLastNode->next = dummyTail;
    delete lastNode;
  }
}

bool IntList::empty() const {
  //checks if the list is empty or not
  return dummyHead->next == dummyTail;
}

void IntList::printReverse() const {
  if (dummyTail->prev->prev == dummyHead) {
    //If theres only one node in the list then it couts the only node
    IntNode* curr = dummyTail->prev;
    cout << curr->data;
  }

  else {
    IntNode* curr = dummyTail->prev;
    while (curr != dummyHead->next) {  
      cout << curr->data << " ";
      curr = curr->prev;
    }  
    cout << curr->data;
    cout << endl;
  }
}

