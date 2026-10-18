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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // map to lookup current node index in inorder array
        map<int, int> inorderIndex;
        for(int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, inorderIndex);
    }
private:
    TreeNode* build(vector<int> & inorder, int inStart, int inEnd,
                        vector<int> & preorder, int preStart, int preEnd,
                        map<int, int> & inorderIndex) {
        if(inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        // lookup the index for root in inorder array
        int rootIdx = inorderIndex[root->val];

        int leftSubtreeSize = rootIdx - inStart;

        // Build left subtree
        root->left = build(inorder, inStart, inStart + leftSubtreeSize - 1,
                            preorder, preStart+1, preStart + leftSubtreeSize, inorderIndex);

        // Build right subtree
        root->right = build(inorder, rootIdx+1, inEnd,
                            preorder, preStart + leftSubtreeSize + 1, preEnd, inorderIndex);

        return root;
    }
};
