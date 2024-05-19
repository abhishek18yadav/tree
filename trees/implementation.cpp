#include<bits/stdc++.h>
using namespace std;

int maxdia = 0;
class node{
    public:
    int val;
    node* left;
    node* right;
    node(int val){
        this->val= val;
        this->left=NULL;
        this->right=NULL;
    }
    void display(node * root){
        if(!root)return;
        cout<<root->val;
        display(root->left);
        display(root->right);
    }
    int level(node* root){
        if(!root)return 0;
        return 1+max(level(root->left),level(root->right));
    }
    int diameter(node * root){
        if(!root)return 0;
        int dia = level(root->left)+ level(root->right);
        int maxdia = max(maxdia, dia);
        diameter(root->left);
        diameter(root->right);
        return maxdia;
    }
};
int main(){
    return 0;
}