// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

class Solution {
public:
    TreeNode* rec(vector<int>nums,int start,int end) {
        if(start>=end) return NULL;
        int mid=(start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left=rec(nums,start,mid);
        root->right=rec(nums,mid+1,end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return rec(nums,0,nums.size());
    }
};