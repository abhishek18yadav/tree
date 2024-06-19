

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


    
        TreeNode* find(TreeNode* root, int val){
            if(!root)return NULL;
            if(root->val == val)return root;
            if(root->val > val) return find(root->left, val);
            else return find(root->right, val);
        }
        TreeNode* searchBST(TreeNode* root, int val) {
            return find(root, val);
        }
