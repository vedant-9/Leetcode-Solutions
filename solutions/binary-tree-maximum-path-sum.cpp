// https://leetcode.com/problems/binary-tree-maximum-path-sum

class Solution {
public:
    // either our max path sum includes left subtree or right subtree gain or both & stop
    int max_sum=INT_MIN;
    int max_gain(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int l=max(max_gain(root->left),0);
        int r=max(max_gain(root->right),0);
        
        int new_price=root->val+l+r;
        max_sum=max(max_sum,new_price);
        return root->val+max(l,r);
    }
    
    int maxPathSum(TreeNode* root) 
    {
        max_gain(root);
        return max_sum;
    }
};