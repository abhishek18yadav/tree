#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/same-tree/
  bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q== NULL)return true;
        if((p!=NULL and q==NULL) or( p==NULL and q!=NULL))return false;
        if(p->val != q->val)return false;
        if(isSameTree(p->left , q->left)){
            if(isSameTree(p->right , q->right)){
                return true;
            }
        }

        return false;
    }

int main(){
    return 0;
}