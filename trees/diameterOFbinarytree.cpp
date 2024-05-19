#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/diameter-of-binary-tree/
 int maxdiameter = 0;
    int level(TreeNode* root){
        if(!root)return 0;
        return 1+ max(level(root->left) , level(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int diameter = level(root->left)+ level(root->right);
        maxdiameter = max(maxdiameter , diameter);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxdiameter;
    }

int main(){
    return 0;
}