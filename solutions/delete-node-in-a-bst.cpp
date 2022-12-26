// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Find the Node
        TreeNode *prev = nullptr;
        TreeNode *cur =  root;
        while (cur && cur->val != key) {
            prev = cur;
            cur = (key < cur->val)?cur->left:cur->right;
        }
        
        // special cases: either case return root no change to BST
        // 1. if tree passed is empty: Not required as per contraints (completeness sake) 
        // 2. If key is not found
        if (cur == nullptr)
            return root;
        
        // key is found in tree
        // Delete Case 1: Node to be deleted is leaf node
        if (cur->left == nullptr && cur->right == nullptr) {
            // Special case: leaf node is root :)
            if (prev == nullptr) {
                root = nullptr;
            } else if (prev->left == cur) {
                prev->left = nullptr;
            } else {
                prev->right = nullptr;
            }
            delete cur;
            return root;
        } 
        if (cur->left == nullptr || cur->right == nullptr) {
            // Delete Case 2: Node to be deleted has single child
            TreeNode *child = (cur->left)?cur->left:cur->right;
            
            // Special Case: If node to be deleted is root which single child /Sub tree
            if (prev == nullptr) {
                root = child;
            } else if (prev->left == cur) {
                prev->left = child;
            } else {
                prev->right = child;
            }
            delete cur;
            return root;
        } 
        // Delete case 3: Node to be deleted has both left and right child/sub tree
        prev = cur;
        TreeNode *successor = cur->right;
        while (successor->left) {
            prev = successor;
            successor = successor->left;
        }
        cur->val = successor->val;
        // Now delete successor
        if (prev->left == successor)
            prev->left = successor->right;
        else
            prev->right = successor->right;
        delete successor;
        return root;
    }
};