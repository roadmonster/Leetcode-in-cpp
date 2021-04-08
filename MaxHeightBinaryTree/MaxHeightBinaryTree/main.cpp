//
//  main.cpp
//  MaxHeightBinaryTree
//
//  Created by HAO LI on 4/7/21.
//

#include <iostream>

using namespace std;

class Node{
public:
    int key;
    Node* left;
    Node* right;
    Node(int data){
        this->key =data;
        this->left = NULL;
        this->right = NULL;
    }
    
};

int getMaxHeight(Node*root){
    if(!root)
        return 0;
    return 1 + max(getMaxHeight(root->left), getMaxHeight(root->right));
}





int main(int argc, const char * argv[]) {
    Node root(1);
    Node left(2);
    Node right(4);
    Node ll(5);
    Node lll(6);
    Node llll(7);
    
    root.left = &left;
    root.right = &right;
    root.left->left = &ll;
    root.left->left->left = &lll;
    root.left->left->left->left = &llll;
    
    cout << "max height of this tree: " << getMaxHeight(&root) << endl;
    
    
    
    return 0;
}
