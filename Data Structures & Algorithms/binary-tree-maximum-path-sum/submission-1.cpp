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
    int helper(TreeNode*node, int curr_sum, int& maximum){
        if(!node) return 0;
        int left_sum =max(0,helper(node->left,curr_sum,maximum));
        int right_sum = max(0,helper(node->right,curr_sum, maximum));

        curr_sum = left_sum+right_sum+node->val;
        maximum = max(maximum,curr_sum);
        return max(left_sum,right_sum)+node->val;
    }
    int maxPathSum(TreeNode* root) {
       int maximum = INT_MIN;
       int curr_sum = 0;
       helper(root,curr_sum, maximum);
       return maximum;

    }
};
