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
        this->right= NULL;
    }
};
treenode* buildTree(vector<int>&arr){
    treenode* root = new treenode(arr[0]);
    queue<treenode* >qu;
    qu.push(root);
    int i=1,j=2;
    while(!qu.empty() and (i<arr.size())){
        treenode* node = qu.front();
        qu.pop();
        if(arr[i]==INT_MIN)node->left = NULL;
        else node->left = new treenode(arr[i]);
        if(arr[j]== INT_MIN)node->right=NULL;
        else node->right= new treenode(arr[j]);
        if(node->left != NULL)qu.push(node->left);
        if(node->right!= NULL)qu.push(node->right);
        i+=2;
        j+=2;
    }
        return root;
    }
    void lefttraversal(treenode* root){
        if(!root)return ;
        cout<<root->val<<" ";
        if(root->left==NULL and root->right == NULL)return;
        if(root->left)lefttraversal(root->left);
        else lefttraversal(root->right);
    }
    void bottomTraversal(treenode* root){
        if(!root)return ;
        if(!root->left and !root->right)cout<<root->val;
        bottomTraversal(root->left);
        bottomTraversal(root->right);
    }
    void rightTraversal(treenode* root){
        if(!root)return;
        cout<<root->val<<" ";
        if(!root->left and !root->right)return;
        if(root->right)rightTraversal(root->right);
        else rightTraversal(root->left);
    }
    void boundryTraversal(treenode* root){
        lefttraversal(root);
        cout<<endl;
        bottomTraversal(root);
        cout<<endl;
        rightTraversal(root);
    }
int main(){
    vector<int>arr{1,2,3,6,7,4,5,11,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN};
    treenode* root = buildTree(arr);
    boundryTraversal(root);
    return 0;
}