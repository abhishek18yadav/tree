#include<bits/stdc++.h>
using namespace std;

class Treenode{
    public:
    int val;
    Treenode* left;
    Treenode* right;
    Treenode(int val){
        this->val = val;
        this->left=NULL;
        this->right = NULL;
    }
};
int level(Treenode* root){
    if(!root)return 0;
    return 1+max(level(root->left), level(root->right));
}
Treenode* construct(vector<int>&arr){
    Treenode* root =  new Treenode(arr[0]);
    int i=1,j=2;
    queue<Treenode*>qu;
    qu.push(root);
    while(!qu.empty() and (i<arr.size() or j<arr.size())){
        Treenode* temp = qu.front();
        qu.pop();
        if(arr[i]==INT_MIN)temp->left = NULL;
        else temp->left= new Treenode(arr[i]);
        if(arr[j]==INT_MIN)temp->right = NULL;
        else temp->right= new Treenode(arr[j]);
        if(temp->left)qu.push(temp->left);
        if(temp->right)qu.push(temp->right);
        i+=2;
        j+=2;
    }
    return root;
}
int main(){
    vector<int>arr{1,2,3,INT_MIN,INT_MIN,4,5};
    Treenode* root=construct(arr);
    cout<<level(root);
    return 0;
}