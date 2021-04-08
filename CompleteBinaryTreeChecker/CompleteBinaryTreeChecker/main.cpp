//
//  main.cpp
//  CompleteBinaryTreeChecker
//
//  Created by HAO LI on 4/7/21.
//

#include <iostream>

using namespace std;

class Node{
public:
    int key;
    Node* left, *right;
    Node* newNode(int data){
        Node* myNode = new Node[sizeof(Node)];
        myNode->key = data;
        myNode->left = NULL;
        myNode->right = NULL;
        return myNode;
    }
    
};

class CompleteChecker{
public:
    int countNode(Node* root){
        if(!root){
            return 0;
        }
        return 1 + countNode(root->left) + countNode(root->right);
    }
    
    bool isComplete(Node* root, int count, int index){
        if(index >= count){
            return false;
        }
        return (isComplete(root->left, countNode(root->left), index * 2 + 1)) && (isComplete(root->right, countNode(root->right), index * 2 + 2));
    }
    
};

int main(int argc, const char * argv[]) {
    Node node;
    Node* root = NULL;
    root = node.newNode(1);
    root->left = node.newNode(2);
    root->right = node.newNode(3);
    root->left->left = node.newNode(4);
    root->left->right = node.newNode(5);
    
    CompleteChecker checker;
    int count = checker.countNode(root);
    cout << "This tree is complete: "<< checker.isComplete(root, count, 0);
    
    delete [] root->left->left;
    delete [] root->left->right;
    delete [] root->left;
    delete [] root->right;
    return 0;
}
