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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            root = new TreeNode(val);
            return root;
        }
        TreeNode* curr = root;
        TreeNode* parent =nullptr;
        
        while(curr){
            parent = curr;
            if(curr->val<val){
                curr = curr->right;
            }
            else {curr = curr->left;}
            
        }
        if(val<parent->val){
            parent->left = new TreeNode(val);
        }
        else 
        {
            parent->right = new TreeNode(val);
        }
        return root;


    }
};