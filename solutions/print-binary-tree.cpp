// https://leetcode.com/problems/print-binary-tree

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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        vector<vector<string>> result(height + 1, vector<string>(pow(2, height + 1) - 1));
        printChildren(root, result, 0, result[0].size() / 2, height);
        return result;
    }
    
    void printChildren(TreeNode* root, vector<vector<string>> &result, int i, int j, int height){
        if(!root) return;
        result[i][j] = to_string(root->val);
        printChildren(root->left, result, i + 1, j - pow(2, height - i - 1), height);
        printChildren(root->right, result, i + 1, j + pow(2, height - i - 1), height);
    }
    
    int getHeight(TreeNode* root){
        if(!root) return -1;
        int height = 1 + max(getHeight(root->left), getHeight(root->right));
        return height;
    }
};