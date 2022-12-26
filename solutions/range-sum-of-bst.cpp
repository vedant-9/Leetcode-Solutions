// https://leetcode.com/problems/range-sum-of-bst

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
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        if (!root) return 0; // base case.
        if (root->val < L) return rangeSumBST(root->right, L, R); // left branch excluded.
        if (root->val > R) return rangeSumBST(root->left, L, R); // right branch excluded.
        return root->val + rangeSumBST(root->right, L, R) + rangeSumBST(root->left, L, R); // count in both children.
    }
};