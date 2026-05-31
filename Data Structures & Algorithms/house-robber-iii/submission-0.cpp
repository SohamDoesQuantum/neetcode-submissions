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
    pair<int,int> helper(TreeNode* node){
        if(node==nullptr) return {0,0};
        pair<int,int> Left = helper(node->left);
        pair<int,int> Right = helper(node->right);
        int robThis = node->val+Left.second+Right.second;
        int dontRob = max(Left.first,Left.second)+max(Right.first,Right.second);
        return {robThis,dontRob};
    }
    int rob(TreeNode* root) {
        pair<int,int> sol = helper(root);
        return max(sol.first,sol.second);
    }
};