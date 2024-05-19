#include<bits/stdc++.h>
using namespace std;

void helper(TreeNode* root, vector<string>&res, string ans){
        if(!root)return;
        if(root->left==NULL and root->right==NULL){
            ans+=to_string(root->val);
            res.push_back(ans);
        }
        ans+=to_string(root->val);
        helper(root->left,res,ans+"->");
        helper(root->right,res,ans+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        string ans="";
        helper(root,res,ans);
        return res;
    }
int main(){
    return 0;
}