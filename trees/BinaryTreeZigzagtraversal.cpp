#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        left=NULL;
        right = NULL;
    }
    
};

TreeNode* construct(vector<int>&arr){
    TreeNode* root =  new TreeNode(arr[0]);
    int i=1,j=2;
    queue<TreeNode*>qu;
    qu.push(root);
    while(!qu.empty() and (i<arr.size() or j<arr.size())){
        TreeNode* temp = qu.front();
        qu.pop();
        if(arr[i]==INT_MIN)temp->left = NULL;
        else temp->left= new TreeNode(arr[i]);
        if(arr[j]==INT_MIN)temp->right = NULL;
        else temp->right= new TreeNode(arr[j]);
        if(temp->left)qu.push(temp->left);
        if(temp->right)qu.push(temp->right);
        i+=2;
        j+=2;
    }
    return root;
}
void display(TreeNode * root){
        if(!root)return;
        cout<<root->val<<" ";
        display(root->left);
        display(root->right);
    }
    int level(TreeNode* root){
        if(!root)return 0;
        return 1+max(level(root->left), level(root->right));
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>qu;
        qu.push(root);
        qu.push(NULL);
        vector<int>res;
        vector<vector<int>>ans;
        int i=0;
        int lev=level(root);
        while(!qu.empty() and lev>0){
            TreeNode* node = qu.front();
            qu.pop();
            if(node == NULL){
                lev--;
                qu.push(NULL);
                if(i%2 !=0){
                    reverse(res.begin(), res.end());
                }
                ans.push_back(res);
                res.clear();
                i++;
                
            }else{
                res.push_back(node->val);
                if(node->left){
                   qu.push(node->left);
                }
                if(node->right){
                   qu.push(node->right);
                }
            }
            
        }
        return ans;
    }
int main(){
    vector<int>v{3,9,20,INT_MAX,INT_MAX,15,7 };
    TreeNode* root = construct(v);
    vector<vector<int>>ans = zigzagLevelOrder(root);
    for(auto ele : ans){
        for(auto e : ele){
            cout<<e<<" ";
        }
        cout<<endl;
    }
    return 0;
}