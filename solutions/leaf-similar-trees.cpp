// https://leetcode.com/problems/leaf-similar-trees

class Solution {
public:
    void dfs(TreeNode *root, string &s) {
        if(!root) return;
        if(!root->left and !root->right) s += to_string(root->val)+",";
        dfs(root->left, s);
        dfs(root->right, s);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1,s2;
        dfs(root1, s1);
        dfs(root2, s2);
        return s1 == s2;
    }
};