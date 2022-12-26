// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root)
            return 0;
        
        queue<pair<TreeNode*,unsigned>> q;
        q.push({root,1});
        
        unsigned max_width = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            
            max_width = max(max_width,q.back().second-q.front().second+1);
            
            while(sz-->0)
            {
                auto node = q.front().first;
                auto idx = q.front().second;
                q.pop();
                if(node->left)
                    q.push({node->left,2*idx});
                if(node->right)
                    q.push({node->right,2*idx+1});
            }
        }
        return max_width;
    }
};