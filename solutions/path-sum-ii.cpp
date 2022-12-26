// https://leetcode.com/problems/path-sum-ii

class Solution {
public:
    void rec(TreeNode* root, int targetSum, vector<int> &path, vector<vector<int>> &paths) {
        if(!root) return;
        
        path.push_back(root->val);
        
        if(!root->left and !root->right) {
            if(targetSum == root->val) 
                paths.push_back(path);
            path.pop_back();
            return;
        }
        
        rec(root->left, targetSum-root->val, path, paths);
        rec(root->right, targetSum-root->val, path, paths);
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        
        rec(root, targetSum, path, paths);
        
        return paths;
    }
};