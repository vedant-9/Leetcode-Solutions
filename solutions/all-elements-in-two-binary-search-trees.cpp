// https://leetcode.com/problems/all-elements-in-two-binary-search-trees

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
    void in(TreeNode* root) {
        if(!root) return;
        in(root->left);
        ans.push_back(root->val);
        in(root->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        in(root1); in(root2);
        sort(ans.begin(),ans.end()); return ans;    
    }
};