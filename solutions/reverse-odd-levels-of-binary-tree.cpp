// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int lvl = 0;
        
        while(!q.empty()) {
            auto sz = q.size();
            vector<TreeNode*> odd;
            while(sz--) {
                auto cur = q.front(); q.pop();
                if(lvl&1) odd.push_back(cur);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(lvl&1) {
                int i = 0, j = odd.size()-1;
                while(i<j) {
                    swap(odd[i]->val, odd[j]->val);
                    i++, j--;
                }
            }
            lvl++;
        }
        
        return root;
    }
};