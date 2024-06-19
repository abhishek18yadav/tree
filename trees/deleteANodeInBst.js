/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} key
 * @return {TreeNode}
 */

function find(root , key){
    if(root==null)return null;
    if(root.val == key){
        if(root.left == null && root.right == null)return null;
        else {
            if(root.left){
                let leftchild = root.left;
                while(leftchild.right != null){
                    leftchild = leftchild.right;
                }
                root.val = leftchild.val;
                root.left = find(root.left , leftchild.val);
            }else{
                let rightchild = root.right;
                while(rightchild.left != null){
                    rightchild = rightchild.left;
                }
                root.val = rightchild.val;
                root.right = find(root.right , rightchild.val);
            }
        }
    }
    if(root.val > key){
        root.left = find(root.left , key);
    }else{
        root.right = find(root.right , key);
    }
    return root;
}
var deleteNode = function(root, key) {
    return find(root , key);
};