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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int ins, int ine, int& idx){
        if(ins>ine) return nullptr;
        int t;
        for(int j = ins; j<=ine;j++){
            if(inorder[j]==preorder[idx]){
                t = j;
                break;
            }
        }
        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        node->left = helper(preorder, inorder, ins,t-1,idx);
        node->right = helper(preorder, inorder,t+1,ine,idx);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ins = 0;
        int ine = preorder.size()-1;
        int idx = 0;
        return helper(preorder, inorder, ins, ine,idx);
    }
};
