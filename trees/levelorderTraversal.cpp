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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

    int level(TreeNode* root){
        if(!root)return 0;
        return 1+ max(level(root->left) , level(root->right));
    }
    void f(TreeNode* root , int curr , int req , vector<int>&v){
        if(!root)return ;
        if(curr == req){
            v.push_back(root->val);
            return ;
        }
        f(root->left, curr+1, req, v);
        f(root->right , curr +1, req, v);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int n= level(root);
        vector<vector<int>>ans;
        for(int i=1; i<=n ; i++){
            vector<int>v;
            f(root, 1, i , v);
            ans.push_back(v);
        }
        return ans;
    }
 // -------------------------------------------------------------------------------------------------------------//

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v;
        vector<vector<int>>res;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL){
                if(!q.empty()){
                    q.push(NULL);
                    res.push_back(v);
                    v.clear();
                }else{
                    res.push_back(v);
                }
            }else{
                v.push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        return res;
    }


int main(){
    return 0;
}