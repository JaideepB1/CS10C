AVLTree::AVLTree() {
    root = nullptr;
}


void AVLTree::insert(const string &newString) { // Insert an item to the binary search tree and perform rotation if necessary.
    if (root == nullptr) {
        root = new Node(newString)
    }

    else {
        Node* currNode = root;

        while (currNode != nullptr) {
            if (newString < currNode->data) {
                if (currNode->left == nullptr) {
                    currNode->left = new Node(newString);
                    currNode->left->parent = currNode;
                }

                else {
                    currNode = currNode->left;
                }
            }

            if (newString > currNode->data) {
                if (currNode->right == nullptr) {
                    currNode->right = new Node(newString);
                    currNode->right->parent = currNode;
                }

                else {
                    currNode = currNode->right;
                }
            }

            if (newString == currNode->data) {
                break;
            }
        }

        while (curNode != nullptr) {
            if (balanceFactor(currNode) < -1 || balanceFactor(currNode) > 1) {
                rotate(currNode);
            }
            currNode = currNode->parent;
        }
    }

}

int AVLTree::balanceFactor(Node* currNode) { // Return the balance factor of a given node.
    if (currNode != nullptr) {
        int balenceVal = height(currNode->left) - height(curr->right);
        return balenceVal;
    }

    else {
        return 0;
    }
} 

void AVLTree::printBalanceFactors() { // Traverse and print the tree in inorder notation. Print the string followed by its balance factor in parentheses followed by a , and one space.
    printBalanceFactorsHelper(root);
} 

void AVLTree::printBalanceFactorsHelper(Node* currNode) {
    if (currNode != nullptr) {
        inOrderHelper(currNode->left);
        cout << currNode->data << "(" << balanceFactor(currNode) << "), ";
        inOrderHelper(currNode->right);
    }
}

/*void AVLTree::visualizeTree(const string &outputFilename) { // Generate dotty file and visualize the tree using dotty program. Call this function before and after rotation
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTre e(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}*/ 

void AVLTree::rotate(Node* currNode) {
    if (balanceFactor(currNode) > 1) {
        if (balanceFactor(currNode->left) == -1) {
            Node* nextNode = currNode->right->left;
            if (currNode->parent = nullptr) {

            }
        }
    }
} // Implement four possible imbalance cases and update the parent of the given node
void rotateLeft(Node *); // Rotate the subtree to left at the given node and returns the new subroot
void rotateRight(Node *); // Rotate the subtree to right at the given node and returns the new subroot
void setChild(Node *, const string &, Node* ); //private helper to set parameter's parent's left/right to its child 
void replaceChild(Node* , Node* , Node* ); // private helper to replace the child of a parent   
int height(Node *);
void visualizeTree(ofstream &, Node *);