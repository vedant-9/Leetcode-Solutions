// https://leetcode.com/problems/add-one-row-to-tree

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int lvl = 1;
        while(!q.empty()) {
            int sz = q.size();
            if(lvl==depth-1) {
                while(sz--) {
                    auto cur=q.front(); q.pop();
                    TreeNode* tmp=cur->left;
                    cur->left=new TreeNode(val);
                    cur->left->left=tmp;
                    
                    tmp=cur->right;
                    cur->right=new TreeNode(val);
                    cur->right->right=tmp;
                }
                break;
            }
            while(sz--) {
                auto cur = q.front(); q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right) 
                    q.push(cur->right);
            }
            lvl++;
        }
        return root;
    }
};