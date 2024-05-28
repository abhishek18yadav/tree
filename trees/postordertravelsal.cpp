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
int level(treenode* root){
    if(!root)return 0;
    return 1+max(level(root->left), level(root->right));
}
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
vector<int> postorder(treenode* root){
    vector<int>res;
    stack<treenode*>st;
    st.push(root);
    while(!st.empty()){
        treenode* temp = st.top();
        st.pop();
        res.push_back(temp->val);
        if(temp->left)st.push(temp->left);
        if(temp->right)st.push(temp->right);
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    vector<int>arr{1,2,3,4,5,6,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN};
    treenode* root = construct(arr);
    vector<int>res = postorder(root);
    // cout<<level(root);
    for(auto ele : res){
        cout<<ele<<" ";
    }
    return 0;
}