#include<bits/stdc++.h>
using namespace std;

class treenode{
    public:
    int val;
    treenode* left;
    treenode* right;
    treenode(int val){
        this->val = val;
        this->left = NULL;
        this->right= NULL;
    }
};
treenode* construct(vector<int>&arr){
    treenode* root = new treenode(arr[0]);
    queue<treenode* >qu;
    qu.push(root);
    int i=1;
    int j=2;
    while(!qu.empty()){
        treenode* node = qu.front();
        qu.pop();
        if(arr[i] == INT_MIN)node->left = NULL;
        else node->left = new treenode(arr[i]);
        if(arr[j] == INT_MIN)node->right = NULL;
        else node->right = new treenode(arr[j]);
        if(node->left)qu.push(node->left);
        if(node->right)qu.push(node->right);
        i+=2;
        j+=2;
    }
    return root;
}
int levelofTree(treenode* root){
    if(!root)return 0;
    return 1+max(levelofTree(root->left), levelofTree(root->right));
}
void rightside(treenode* root, int l){
    queue<treenode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty() and l>0){
        treenode* node = q.front();
        q.pop();
        if(node==NULL){
            q.push(NULL);
            l--;    
            continue;
        }
        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);
        if(q.front()==NULL)cout<<node->val<<" ";
    }
}
int main(){
    vector<int>arr{1,2,3,6,7,4,5,11,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN};
    treenode* root = construct(arr);
    int l=levelofTree(root);
    rightside(root,l);
    return 0;
}