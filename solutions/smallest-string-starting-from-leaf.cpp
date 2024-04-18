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
    string ans = "{";
    void rec(TreeNode* root, string s) {
        if(!root) return;
        if(!root->left and !root->right) {
            ans = min(ans, (char)(root->val+'a')+s);
            return;
        }
        rec(root->left, (char)(root->val+'a')+s);
        rec(root->right, (char)(root->val+'a')+s);
    }
    string smallestFromLeaf(TreeNode* root) {
        rec(root, "");
        return ans;
    }
};
