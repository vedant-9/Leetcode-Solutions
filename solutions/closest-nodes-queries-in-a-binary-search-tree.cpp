// https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree

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
    vector<int> ans;
    void inOrder(TreeNode* root) {
        if(!root) return;
        inOrder(root->left);
        ans.push_back(root->val);
        inOrder(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inOrder(root);
        vector<vector<int>> res;
        for(auto q: queries) {
            auto it = lower_bound(ans.begin(), ans.end(), q);
            if(it != ans.end() and *it == q) {
                res.push_back({q, q});
            } else {
                int mni = -1;
                if(it != ans.begin()) mni = *prev(it);
                int mxi = -1;
                if(it != ans.end()) mxi = *it;
                res.push_back({mni, mxi});
            }
        }
        return res;
    }
};