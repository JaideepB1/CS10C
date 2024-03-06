#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

class Tree {
private:
  Node *root;

public:
  Tree( );
  ~Tree( );
  void insert(const string &);
  void preOrder( ) const;
  void inOrder( ) const;
  void postOrder( ) const;
  void remove(const string &);
  bool search (const string &) const;

private:
  // Add additional functions/variables here
  void destructorHelper(Node* node);
  void preOrderHelper(Node* currNode) const;
  void inOrderHelper(Node* currNode) const;
  void postOrderHelper(Node* currNode) const;
  void insertHelper(Node* currNode, const string &newString);
  void removeHelper(Node* currNode, const string &newString);
  bool searchHelper(const Node *currNode, const string &newString) const;
  void split(Node* currNode, const string &newString);
};

#endif
