#include<bits/stdc++.h>
using namespace std;

class treenode{
    public:
    int val;
    treenode* left;
    treenode* right;
    treenode(int val){
        this->val = val;
        this->left= NULL;
        this->right=NULL;
    }
};

treenode* construct(vector<int>&arr){
    treenode* root = new treenode(arr[0]);
    int i=1,j=2;
    queue<treenode*>qu;
    qu.push(root);
    while(!qu.empty() and (i<arr.size() or j<arr.size())){
        treenode* temp = qu.front();
        // cout<<temp->val;
        qu.pop();
        if(arr[i]!=INT_MIN)temp->left= new treenode(arr[i]);
        else temp->left=NULL;
        if(arr[j]!=INT_MIN)temp->right= new treenode(arr[j]);
        else temp->right=NULL;
        if(temp->left)qu.push(temp->left);
        if(temp->right)qu.push(temp->right);
        i+=2;
        j+=2;
    }
    return root;
}
///    iterative approach////
void preorder(treenode* root){
    if(!root)return ;
    stack<treenode*>st;
    st.push (root);
    while(st.size()>0){
        treenode* temp =st.top();
        cout<<temp->val<<" ";
        st.pop();
        if(temp->right)st.push(temp->right);
        if(temp->left)st.push(temp->left);
    }
}
///   recursive approach
void Preorder(treenode* root){
    if(!root)return ;
    cout<<root->val<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
int main(){
    vector<int>arr{1,2,3,4,5,6,7};
    treenode* root = construct(arr);
    preorder(root);
    return 0;
}