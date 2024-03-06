#include <iostream>
#ifndef __NODE_H__
#define __NODE_H__


using namespace std;

class Node {
    public:    
      string data;
      Node* parent;
      Node* left;
      Node* right;
    
      Node (const string& key);
};





#endif