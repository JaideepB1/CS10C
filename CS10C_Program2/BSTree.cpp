#include "BSTree.h"

#include <iostream>
#include <stdexcept>

using namespace std;

void BSTree::insert(const string& key) {
  // Edge case:  The tree is empty
  // Edge case: If we find the key in the tree, just increment its count
  // Typical case, we find a hole where this key belongs
  // ==> if we would go left and there is no child there, insert new node to left
  // ==> if we would go right and there is no child there, insert new node to right

  //If empty it adds a new Node as the root
  if (root == nullptr) {
    root = new Node(key);
  }

  else {
    Node* currNode = root;
    while (currNode != nullptr) {
      //If the key value is less than the value of the 
      //node it moves to the left if there is a node and if not it creates one
      if (key  < currNode->key) {
        if (currNode->left == nullptr) {
          currNode->left = new Node(key);
          return;
        }

        else {
          currNode = currNode->left;
        }
      }

      else if (key > currNode->key) {
        if (currNode->right == nullptr) {
          currNode->right = new Node(key);
          return;
        }

        else {
          currNode = currNode->right;
        }
      }

      //If the node already exists the count is increased by 1
      else {
        currNode->count += 1;
        return;
      }
    }
  }

  //throw runtime_error("not done insert");
}
bool BSTree::search(const string& key) const {
  // Search can be done in a loop (or recursively).  A loop is best here
  Node* currNode = root;
  //searches through the BST while the end is not reached
  while (currNode != nullptr) {
    if (key > currNode->key) {
      currNode = currNode->right;
    }

    else if (key < currNode->key) {
      currNode = currNode->left;
    }

    //returns true if the value is found
    else if (key == currNode->key) {
      return true;
    }
  }

  return false;
  //throw runtime_error("not done search");
}

string BSTree::largest() const {
  // Edge case: Tree is empty (return "")
  // Largest can be done in a loop (or recursively).  A loop is best here
  if (root == nullptr) {
    return string();
  }

  Node* currNode = root;

  //Keeps travelling to the right of the BST to find the larges value
  while (currNode->right != nullptr) {
    currNode = currNode->right;
  }
  return currNode->key;

  //throw runtime_error("not done largest");
}

string BSTree::smallest() const {
  // Smallest can be done in a loop (or recursively).  A loop is best here
  // Edge case: Tree is empty
  if (root == nullptr) {
    return string();
  }

  Node* currNode = root;
  
  //Keeps travelling to the left of the BST while it can to find the smallest value
  while (currNode->left != nullptr) {
    currNode = currNode->left;
  }
  return currNode->key;

  //throw runtime_error("not done smallest");
}

int BSTree::height(const string& key) const {
  // First find the node with this key, then run "height_of" to get
  // the height that zybooks wants
  Node* currNode = root;

  while (currNode != nullptr) {
    if (key == currNode->key) {
      break;
    }

    if (key < currNode->key) {
      currNode = currNode->left;
    }

    if (key > currNode->key) {
      currNode = currNode->right;
    }
  }

  int heightVal = height_of(currNode);
  return heightVal;
  
  //throw runtime_error("not done height");
}

void BSTree::remove(const string& key) {
  remove(nullptr, root, key);
  //throw runtime_error("not done remove");
}

void BSTree::preOrder() const {
  // This wants a ", " after each node and exactly one newline once done
  if (root == nullptr) {
    return;
  }
  return preOrder(root);
  //throw runtime_error("not done preOrder");
}

void BSTree::postOrder() const {
  // This wants a ", " after each node and exactly one newline once done
  if (root == nullptr) {
    return;
  }
  return postOrder(root);
  //throw runtime_error("not done postOrder");
}

void BSTree::inOrder() const {
  // This wants a ", " after each node and exactly one newline once done
  if (root == nullptr) {
    return;
  }
  return inOrder(root);
  //throw runtime_error("not done inOrder");
}

void BSTree::remove(Node* parent, Node* tree, const string& key) {
  // Hint: A good approach is to find the parent and the curr node that holds that key
  // Edge case: The key is not found (do nothing)
  // Edge case.  The key count is greater than 1.  Just decrement the count
  // Edge case: leaf (no children).  Just remove from parent
  //  ==> case 1: parent is nullptr (we are removing the last node from root)
  //  ==> case 2: curr is the left child, remove it from parent
  //  ==> case 3: curr is the right child, remove it from parent
  // Typical case.  Find the target
  // It is either the largest key in the left tree (if one exists)
  // or the smallest key in the right tree (since not a leaf one will exist)
  // Copy the target information into the node we found, set the target count to
  // one, and recursively remove it from left or right subtree (current node is the parent)
  if (tree == nullptr) {
    //If empty nothing is returned
    return;
  }

  if (key > tree->key) {
    remove(tree, tree->right, key);
  }

  else if (key < tree->key) {
    remove(tree, tree->left, key);
  }

  else if (tree->key == key) {
    if (tree->count > 1) { 
      //If the tree has a count greater than 1 the count is decreased
      tree->count -= 1;
    }

    else if (tree->left == nullptr && tree->right == nullptr) {
      //If it is a leaf node then the node is directly deleted
      delete tree;
    }

    else if (tree->left != nullptr) {
      //If the node has a node to the left then it finds the largest node 
      //smaller than the it and repalces the values of it and the found node
      Node* curr = tree->left;
      while (curr != nullptr) {
        curr = curr->right;
      }
      tree->key = curr->key;
      tree->count = curr->count;
      delete curr;
    }

    else if (tree->right != nullptr) {
      Node* curr = tree->right;
      while (curr != nullptr) {
        curr = curr->left;
      }
      tree->key = curr->key;
      tree->count = curr->count;
      delete curr;
    }
  }
  //throw runtime_error("not done remove");
}

int BSTree::height_of(Node* tree) const {
  // The height (length of longest path to the bottom) of an empty tree is -1
  // Otherwise, you pick the larger of the left height and the right height
  // and add one to that
  if (tree == nullptr) {
    return -1;
  }

  int leftHeight = height_of(tree->left);
  int rightHeight = height_of(tree->right);
  int heightVal = 1 + max(leftHeight, rightHeight);
  return heightVal;

  //throw runtime_error("not done height_of");
}

void BSTree::preOrder(Node* tree) const {
  // print key, do left, do right
  if (tree != nullptr) {
    cout << tree->key << "(" << tree->count << "), ";
    preOrder(tree->left);
    preOrder(tree->right);
  }
  //throw runtime_error("not done preOrder");
}

void BSTree::postOrder(Node* tree) const {
  // do left, do right, print key
  if (tree != nullptr) {
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->key << "(" << tree->count << "), ";
  }
  //throw runtime_error("not done postOrder");
}

void BSTree::inOrder(Node* tree) const {
  // do left, print key, do right
  if (tree != nullptr) {
    inOrder(tree->left);
    cout << tree->key << "(" << tree->count << "), ";
    inOrder(tree->right);
  }
  //throw runtime_error("not done inOrder");
}

// This is a pre-order traversal that shows the full state of the tree
// (but it is a code turd)
void BSTree::debug(Node* tree, int indent) const {
  if (tree == nullptr) return;
  for(int i=0;i<4*indent;++i) cout << ' ';
  cout << tree << ' ' << *tree << endl;
  debug(tree->left,indent+1);
  for(int i=0;i<4*indent;++i) cout << ' ';
  cout << "-" << endl;
  debug(tree->right,indent+1);
}
