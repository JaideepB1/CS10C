
#include "Node.h"


Node::Node (const string& key) {
    this->small = key;
    this->large = "";
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}