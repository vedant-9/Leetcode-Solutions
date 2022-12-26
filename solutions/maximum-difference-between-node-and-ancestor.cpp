// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

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
    int maxAncestorDiff(TreeNode* root, int mx=INT_MIN, int mn=INT_MAX) {
        if(!root) return 0;
        int ans=-1;
        if(mx!=INT_MIN) ans=abs(root->val-mx);
        if(mn!=INT_MAX) ans=max(ans,abs(root->val-mn));
        return max({ans,maxAncestorDiff(root->left,max(mx,root->val),min(mn,root->val)),maxAncestorDiff(root->right,max(mx,root->val),min(mn,root->val))});
    }
};