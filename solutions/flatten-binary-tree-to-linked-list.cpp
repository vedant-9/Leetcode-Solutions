// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root) {
            // store current root->right in temp
            TreeNode* temp = root->right;
            
            // transfer left part to right part
            root->right = root->left;
            root->left = NULL;
            
            // go to extreme right of previously left part
            TreeNode* node = root;
            while(node->right)
                node = node->right;
            
            // append temp to end of right chain 
            node->right = temp;
            flatten(root->right); 
        } 
        return;
    }
};