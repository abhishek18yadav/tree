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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int>res;
        while(curr){
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr= curr->right;
            }else{
                TreeNode* leftchild = curr->left;
                while(leftchild->right){
                    leftchild = leftchild->right;
                }
                leftchild->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left= NULL;
            }
        }
        return res;
    }
};