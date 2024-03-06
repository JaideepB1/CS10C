include <iostream>
#include <stdexcept>
#include "Node.h"

using namespace std;

Node::Node (const string& key) {
    this->data = key;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}