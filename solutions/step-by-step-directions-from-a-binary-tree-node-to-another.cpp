// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another

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
    // 1. apply LCA to get a new root.
    // 2. get the Path from the new root to start and dest.
    // 3. concate startPath and destPath, note that we need to replace startPath's char to 'U'
    TreeNode* lca(TreeNode *root, int startValue, int destValue) {
        if(!root) return NULL;
        if(root->val == startValue) return root;
        if(root->val == destValue) return root;
        
        auto l = lca(root->left, startValue, destValue);
        auto r = lca(root->right, startValue, destValue);
        
        if(l && r) return root;
        return l ? l : r;
    }
    bool getPath(TreeNode *root, int value, string &path) {
        if(!root) return false;
        if(root->val == value) return true;
        
        path += 'L';
        auto res = getPath(root->left, value, path);
        if(res) return true;
        path.pop_back();
        
        path += 'R';
        res = getPath(root->right, value, path);
        if(res) return true;
        path.pop_back();
        
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root=lca(root,startValue,destValue);
        
        string p1, p2;
        getPath(root, startValue, p1);
        getPath(root, destValue, p2);
        
        for(auto &c : p1) c = 'U';
        
        return p1 + p2;
    }
};