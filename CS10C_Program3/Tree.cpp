#include "Tree.h"
#include <iostream>

using std::cout;

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    destructorHelper(root);
}

void Tree::destructorHelper(Node* currNode) {
    if (currNode != nullptr) {
        destructorHelper(currNode->left);
        destructorHelper(currNode->middle);
        destructorHelper(currNode->right);
    }
}

void Tree::insert(const string &newString) {
    if (root == nullptr) {
        root = new Node(newString);
    }

    else {
        insertHelper(root, newString);
    }
}

void Tree::insertHelper(Node* currNode, const string &newString) {
    if (currNode == nullptr) {
        currNode = new Node(newString);
    }

    
    
    if (currNode->large.empty()) {
        if (newString < currNode->small) {
            if (currNode->left == nullptr) {
                
                currNode->large = currNode->small;
                currNode->small = newString;
            }

            else {
                insertHelper(currNode->left, newString);
            }
        }

        else if (newString > currNode->small){
            if (currNode->right == nullptr) {
                currNode->large = newString;
            }

            else {
                insertHelper(currNode->right, newString);
            }
        }
    }

    else {
        if (newString < currNode->small) {
            if (currNode->left == nullptr) {
                split(currNode, newString);
            }

            else {
                insertHelper(currNode->left, newString);
            }
        }

        else if (newString > currNode->small){
            if (newString < currNode->large) {
                if (currNode->right == nullptr) {
                    split(currNode, newString);
                }

                else {
                    insertHelper(currNode->middle, newString);
                }
            }

            else {
                split(currNode, newString);
            }
        }
    }
    
}

void Tree::split(Node* currNode, const string &newString) {
    string midNode;
    Node* leftNode;
    Node* rightNode;

    if (newString > currNode->large) {
        midNode = currNode->large;
        leftNode = new Node(currNode->small);
        rightNode = new Node(newString);
    }

    else if (newString < currNode->small) {
        midNode = currNode->small;
        leftNode = new Node(newString);
        rightNode = new Node(currNode->large);
    }

    else {
        midNode = newString;
        leftNode = new Node(currNode->small);
        rightNode = new Node(currNode->large);
    }

    if (currNode->parent == nullptr) {
        root = new Node(midNode);
        root->right = rightNode;
        root->left = leftNode;
        rightNode->parent = root;
        leftNode->parent = root;
    }

    else {
        currNode->parent->large = midNode;
        currNode->parent->middle = leftNode;
        currNode->parent->right = rightNode;
        leftNode->parent = currNode->parent;
        rightNode->parent = currNode->parent;
    }
}

void Tree::preOrder() const {
    preOrderHelper(root);
    cout << endl;
}

void Tree::preOrderHelper(Node* currNode) const {
    if (currNode != nullptr) {
        if (currNode->large.empty()) {
            cout << currNode->small << ", ";
            preOrderHelper(currNode->left);
            preOrderHelper(currNode->right);
        }

        else {
            cout << currNode->small << ", ";
            preOrderHelper(currNode->left);
            cout << currNode->large << ", ";
            preOrderHelper(currNode->middle);
            preOrderHelper(currNode->right);
        }
    }
}

void Tree::inOrder() const {
    inOrderHelper(root);
    cout << endl;
}

void Tree::inOrderHelper(Node* currNode) const {
    if (currNode != nullptr) {
        if (currNode->large.empty()) {
            inOrderHelper(currNode->left);
            cout << currNode->small << ", ";
            inOrderHelper(currNode->right);
        }

        else {
            inOrderHelper(currNode->left);
            cout << currNode->small << ", ";
            inOrderHelper(currNode->middle);
            cout << currNode->large << ", ";
            inOrderHelper(currNode->right);
        }
    }
}

void Tree::postOrder() const {
    postOrderHelper(root);
    cout << endl;
}

void Tree::postOrderHelper(Node* currNode) const {
    if (currNode != nullptr) {
        if (currNode->large.empty()) {
            postOrderHelper(currNode->left);
            postOrderHelper(currNode->right);
            cout << currNode->small << ", ";
        }

        else {
            postOrderHelper(currNode->left);
            postOrderHelper(currNode->middle);
            cout << currNode->small << ", ";
            postOrderHelper(currNode->right);
            cout << currNode->large << ", ";
        }
    }
}

void Tree::remove(const string &newString) {
    removeHelper(root, newString);
}

void Tree::removeHelper(Node* currNode, const string &newString) {
    if (currNode != nullptr) {
        if (search(newString)) {
            if (currNode->small == newString) {
                if (currNode->parent == nullptr) {
                    if (currNode->left == nullptr && currNode->right == nullptr) {
                        if (currNode->large.empty()) {
                            delete currNode;
                            root = nullptr;
                        }

                        else {
                            currNode->small == currNode->large;
                            currNode->large = "";
                        }
                    }

                    else {
                        currNode->small = currNode->left->small;
                        currNode->large = currNode->right->small;
                        delete currNode->left;
                        delete currNode->right;
                        currNode->left = nullptr;
                        currNode->right = nullptr;
                    }
                }

                else {
                    if (currNode->large.empty()) {
                        if (currNode->parent->right == currNode) {
                            currNode->parent->large = currNode->parent->small;
                            currNode->parent->small = currNode->parent->left->small;
                        }

                        else if (currNode->parent->left == currNode) {
                            currNode->parent->large = currNode->parent->right->small;
                        }

                        delete currNode->parent->left;
                        delete currNode->parent->right;
                        
                        currNode->parent->left = nullptr;
                        currNode->parent->right = nullptr;
                    }

                    else {
                        currNode->small = currNode->large;
                        currNode->large = "";
                    }
                }
            }

            else if (currNode->large == newString) {
                if (currNode->parent == nullptr) {
                    if (currNode->left == nullptr && currNode->right == nullptr) {
                        currNode->large = "";
                    }

                    else {
                        currNode->small = currNode->left->small;
                        currNode->large = currNode->right->small;
                        delete currNode->left;
                        delete currNode->right;
                        currNode->left = nullptr;
                        currNode->right = nullptr;
                    }
                }

                else {
                    currNode->small = currNode->large;
                    currNode->large = "";
                }
            }

            else {
                if (newString < currNode->small) {
                    removeHelper(currNode->left, newString);
                }

                else if (!currNode->large.empty() && newString < currNode->large) {
                    removeHelper(currNode->middle, newString);
                }

                else {
                    removeHelper(currNode->right, newString);
                }
            }
        }
    }
}

bool Tree::search(const string &newString) const {
    bool searchVal = searchHelper(root, newString);
    return searchVal;
}

bool Tree::searchHelper(const Node *currNode, const string &newString) const {
    while (currNode != nullptr) {
        if (currNode->small == newString || currNode->large == newString) {
            return true;
        }

        else {
            if (newString < currNode->small) {
                searchHelper(currNode->left, newString);
            }

            else if (!currNode->large.empty() && newString < currNode->large) {
                searchHelper(currNode->middle, newString);
            }

            else {
                searchHelper(currNode->right, newString);
            }
        }
    }

    return false;
}