//
//  main.cpp
//  L230KthSmallestElem
//
//  Created by HAO LI on 3/26/21.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution{
public:
    int kthSmallest(TreeNode* root, int k){
        int cnt = 0;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (p || s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            cnt++;
            if(cnt ==k)
                return p-> val;
            p = p->right;
        }
        return 0;
    }
    
    int kthSmallest2(TreeNode* root, int k){
        int cnt = count(root->left);
        if(k <= cnt){
            return kthSmallest2(root->left, k);
        }else if(k > cnt + 1){
            return kthSmallest2(root->right, k-cnt-1);
        }
        return root->val;
        return 0;
    }
    
    int count(TreeNode* node){
        if(!node)
            return 0;
        return 1 + count(node->left) + count(node->right);
    }
};

class SolutionFollowUp{
public:
    struct MyTreeNode{
        int val;
        int count;
        MyTreeNode* left;
        MyTreeNode* right;
        MyTreeNode(int x): val(x), count(1), left(NULL), right(NULL){};
    };
    
    MyTreeNode* build(TreeNode* root){
        if(!root)
            return NULL;
        MyTreeNode* node = new MyTreeNode(root->val);
        node->left = build(root->left);
        node->right = build(root->right);
        if(node->left){
            node->count +=  node->left->count;
        }
        if(node->right){
            node->count += node->right->count;
        }
        
        return node;
    }
    
    int kthSmallest(TreeNode* root, int k){
        MyTreeNode* node = build(root);
        return helper(node, k);
    }
    
    int helper(MyTreeNode* node, int k){
        if(node->left){
            int cnt = node->left->count;
            if(k <= cnt){
                return helper(node->left, k);
            }else if(k > cnt + 1){
                return helper(node->right, k - cnt -1);
            }
            return node->val;
        }else{
            if(k == 1)
                return node->val;
            return helper(node->right, k -1);
        }
    }
};


int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(3);
    TreeNode* left = new TreeNode(1);
    TreeNode* right = new TreeNode(4);
    TreeNode* leftRight = new TreeNode(2);
    root->left = left;
    root->right = right;
    root->left->right = leftRight;
    
    Solution s;
    cout << "Test restult should be 1\nOutput: " << s.kthSmallest(root, 1) << endl;
    
    cout << "Test2 restult should be 1\nOutput: " << s.kthSmallest2(root, 1) << endl;
    
    SolutionFollowUp sfp;
    
    cout << "Test 3 restult should be 1\nOutput: " << sfp.kthSmallest(root, 1) << endl;
}
