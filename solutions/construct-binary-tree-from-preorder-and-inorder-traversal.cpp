// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    vector<int> pre,in;
    TreeNode* build(int ps, int pe, int is, int ie)
    {
        if(ps>pe)
            return NULL;
        TreeNode* node = new TreeNode(pre[ps]);
        int pos;
        for(int i = is; i <= ie; i++)
        {
            if(in[i] == node->val)
            {
                pos = i;
                break;
            }
        }
        node->left = build(ps + 1, ps + pos - is, is, pos - 1);
        node->right = build(pe - ie + pos + 1, pe, pos + 1, ie);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        pre = preorder;
        in = inorder;
        int n = pre.size();
        return build(0,n-1,0,n-1);
    }
};