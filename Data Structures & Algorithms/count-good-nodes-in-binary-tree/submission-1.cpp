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
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int max_val = root->val;
        preorder(root, cnt,max_val);
        return cnt;
    }

   private:
    void preorder(TreeNode* node, int& cnt, int max_val){
        if(!node) return;
        if(node->val>=max_val){
            cnt++;
        }
        max_val= max(max_val, node->val);
        preorder(node->left, cnt, max_val);
        preorder(node->right, cnt, max_val);
    }
};
