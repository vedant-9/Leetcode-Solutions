// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;

        // level order traversal
        if(root==NULL)
            return ans;
        
        int level=0;
        
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            auto k=q.front();
            q.pop();
            
            if(k!=NULL)
            {           
                v.push_back(k->val);
                if(k->left)
                    q.push(k->left);
                if(k->right)
                    q.push(k->right);
            }
            else if(!q.empty())
            {
                ans.push_back(v);
                v.clear();
                level++;
                q.push(NULL);
            }
        }
        ans.push_back(v);
        
        for(int i=0;i<ans.size();i++)
        {
            if(i%2)
            {
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};