#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stack>
#include "arithmeticExpression.h"

using namespace std;

/* Initializes an empty tree and sets the infixExpression
to the value of parameter passed in. */
arithmeticExpression::arithmeticExpression(const string &val) {
    infixExpression = val;
    root = nullptr;
}

/* Implementation of destrucor is optional.
    The destructor should deallocate all the nodes in the tree. */
//~arithmeticExpression();

/* Converts the infixExpression to its equivalent postfix string
    and then generates the tree and assigns the root node to the 
    root data field. The key for the first node is 'a', 'b' for the second node and so on. */
void arithmeticExpression::buildTree() {
    string postfix = infix_to_postfix();
    stack<TreeNode*> s;

    for (unsigned i = 0; i < postfix.size(); i++) {
        char c = postfix.at(i);

        //finds if the character is not an alphabetical letter
        if (!isalpha(c)) {
            TreeNode* currNode = new TreeNode(c, 'a' + i);
            currNode->right = s.top();
            s.pop();
            currNode->left = s.top();
            s.pop();
            s.push(currNode);
        }

        else {
            s.push(new TreeNode(c, 'a' + i));
        }

        root = s.top();
    }
}

/* Calls the recursive infix function. */
void arithmeticExpression::infix() {
    infix(root);
}

/* Calls the recursive prefix function. */
void arithmeticExpression::prefix() {
    prefix(root);
}

/* Calls the recursive postfix function. */
void arithmeticExpression::postfix() {
    postfix(root);
}

/* Calls the recursive visualizeTree function and generates the .png file using system call. */
//void visualizeTree(const string &);


/* Helper function that returns an integer according to
    the priority of the given operator. */
int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

/* Helper function that returns the postfix notation equivalent
    to the given infix expression */
string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;

    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }

    while(!s.empty()){
        oss << s.top();
        s.pop();
    }

    return oss.str();
}

/* Helper function that outputs the infix notation of the arithmetic expression tree
    by performing the inorder traversal of the tree.
    An opening and closing parenthesis must be added at the 
    beginning and ending of each expression. */
void arithmeticExpression::infix(TreeNode *rootNode) {
    if (rootNode != nullptr) {
        if (rootNode->left != nullptr) {
            cout << "(";
        }

        infix(rootNode->left);
        cout << rootNode->data;
        infix(rootNode->right);

        if (rootNode->right != nullptr) {
            cout << ")";
        }
    }
}

/* Helper function that outputs the prefix notation of the arithmetic expression tree
    by performing the preorder traversal of the tree. */
void arithmeticExpression::prefix(TreeNode *rootNode) {
    if (rootNode != nullptr) {
        cout << rootNode->data;
        prefix(rootNode->left);
        prefix(rootNode->right);
    }
}

/* Helper function that outputs the postfix notation of the arithmetic expression tree
    by performing the postorder traversal of the tree. */
void arithmeticExpression::postfix(TreeNode *rootNode) {
    if (rootNode != nullptr) {
        postfix(rootNode->left);
        postfix(rootNode->right);
        cout << rootNode->data;
    }
}

/* Helper function for generating the dotty file. This is a recursive function. */
//void visualizeTree(ofstream &, TreeNode *);