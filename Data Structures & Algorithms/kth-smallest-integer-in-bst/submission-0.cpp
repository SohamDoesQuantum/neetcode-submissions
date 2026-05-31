/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int inorder(TreeNode* node, int& k ){
        if(!node) return -1;
        if(node->left){
            int left_res = inorder(node->left, k);
            if(left_res!=-1) return left_res;
        }
        k--;
        if(k==0){
            return node->val;
        }
        if(node->right)
            return inorder(node->right,k);
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root,k);
    }
};
