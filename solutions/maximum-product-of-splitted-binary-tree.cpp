// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

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
    const int M = 1e9+7;
    long st,mx=INT_MIN;
    
    int getSum(TreeNode* r)
    {
        return (r? (getSum(r->left) + getSum(r->right) + r->val):0);
    }
    
    long subtreeSum(TreeNode* r)
    {
        if(!r)
            return 0;
        long sl = subtreeSum(r->left), sr = subtreeSum(r->right);
        mx = max({(long)mx,((st-sl)*sl),((st-sr)*sr)});
        return ((sl+sr+r->val));
    }
    
    int maxProduct(TreeNode* root) 
    {
        st = getSum(root);
        subtreeSum(root);
        return mx%M;
    }
};