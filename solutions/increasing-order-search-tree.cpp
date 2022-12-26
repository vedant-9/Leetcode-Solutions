// https://leetcode.com/problems/increasing-order-search-tree

class Solution {
public:
     TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) 
     {
        if (!root) 
            return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};