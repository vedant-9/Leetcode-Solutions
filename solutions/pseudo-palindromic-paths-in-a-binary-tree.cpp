// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root, int mask = 0) {
        if(!root) return 0;
        mask ^= (1<<root->val);
        if(!root->left and !root->right) {
            return (mask==0 or (mask&(mask-1))==0);
        }
        int l = pseudoPalindromicPaths(root->left, mask);
        int r = pseudoPalindromicPaths(root->right, mask);
        return l+r;
    }
};