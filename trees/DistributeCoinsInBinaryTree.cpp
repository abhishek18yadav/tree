#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
int moves;
    int f(TreeNode* root){
        if(!root)return 0;
        int left = f(root->left);
        int right = f(root->right);
        moves += abs(left)+abs(right);
        
        return (root->val-1 + left + right);

    }
    int distributeCoins(TreeNode* root) {
         moves=0;
        int ans=f(root);
        return moves;
    }
int main(){
    return 0;
}