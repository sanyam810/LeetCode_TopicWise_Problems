/**
You are given the root of a binary search tree (BST),
where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Example :

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

**/

class Solution {
public:
    
    vector<int>v;
    int i=0;
    
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    
    void check(TreeNode* root){
        if(!root)return;
        check(root->left);
        if(v[i]!=root->val)swap(v[i],root->val);
        i++;
        check(root->right);
    }
    
    
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        sort(v.begin(),v.end());
        check(root);
        
        
    }
};

