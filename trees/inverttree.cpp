#include<iostream>
using namespace std;

void helper(TreeNode* root){
        if(!root)return;
        TreeNode* temp= root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
    int main(){
        return 0;
    }