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
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        auto [robL, skipL] = dfs(node->left);
        auto [robR, skipR] = dfs(node->right);

        int robHere  = node->val + skipL + skipR;
        int skipHere = max(robL, skipL) + max(robR, skipR);

        return {robHere, skipHere};
    }

public:
    int rob(TreeNode* root) {
        auto [robRoot, skipRoot] = dfs(root);
        return max(robRoot, skipRoot);
    }
};
