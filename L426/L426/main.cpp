////
////  main.cpp
////  L426
////
////  Created by HAO LI on 3/21/21.
////
//
#include <iostream>
using namespace std;
//
class Node{
public:
    Node* left;
    Node* right;
    int value;

    Node(Node* left, Node*right, int value){
        this->left = left;
        this->right = right;
        this->value = value;
    }
};

class Solution{
public:
    Node* treeToDoublyList(Node* root){
        if(!root)
            return NULL;
        Node* leftHead = treeToDoublyList(root->left);
        Node* rightHead = treeToDoublyList(root->right);
        root->left = root;
        root ->right = root;
        return connect(connect(leftHead, root), rightHead);
    }

    Node* connect(Node* node1, Node* node2){
        if(!node1)
            return node2;
        if(!node2)
            return node1;

        Node* tail1 = node1->left;
        Node* tail2 = node2->left;

        tail1->right = node2;
        node2->left = tail1;

        tail2->right = node1;
        node1->left = tail2;

        return node1;
    }

    void printSolution(Node* head){
        Node* root = head;
        do{
            cout << root->value << " -> ";
            root = root->right;
        }while (root != head);
        cout <<endl;
    }
};

class Solution2 {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        Node *leftHead = treeToDoublyList(root->left);
        Node *rightHead = treeToDoublyList(root->right);
        root->left = root;
        root->right = root;
        return connect(connect(leftHead, root), rightHead);
    }
    Node* connect(Node* node1, Node* node2) {
        if (!node1) return node2;
        if (!node2) return node1;
        Node *tail1 = node1->left, *tail2 = node2->left;
        tail1->right = node2;
        node2->left = tail1;
        tail2->right = node1;
        node1->left = tail2;
        return node1;
    }
    
    void printSolution(Node* head){
        Node* root = head;
        do{
            cout << root->value << " -> ";
            root = root->right;
        }while (root != head);
        cout <<endl;
    }
};

int main() {
    
    
    Node* l1 = new Node(NULL, NULL, 2);
    
    Node* l2 = new Node(NULL, NULL, 5);
    
    Node* bst = new Node(l1, l2, 4);
    
    Solution s;
    
    s.printSolution(s.treeToDoublyList(bst));
    
    return 0;
}
