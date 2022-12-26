// https://leetcode.com/problems/validate-binary-search-tree

class Solution {
public:
	vector<int> ans;
    void Inorder(TreeNode *root)
    {
        if(!root)
        {
            return;
        }
        Inorder(root->left);
        ans.push_back(root->val);
        Inorder(root->right);
    }
    
    bool isValidBST(TreeNode* root) 
    {
        Inorder(root);
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i]>=ans[i+1])
            	return false;
        }
        return true;
    }
};


