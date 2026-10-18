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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Map each value to its index in inorder for O(1) root lookup.
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderIndex);
    }

private:
    TreeNode* build(vector<int>& inorder,   int inStart,   int inEnd,
                    vector<int>& postorder, int postStart, int postEnd,
                    unordered_map<int, int>& inorderIndex) {
        if (inStart > inEnd) return nullptr;

        // In postorder, the LAST element of the range is the subtree's root.
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // Find the root in inorder. Everything left of it is the left
        // subtree, everything right is the right subtree.
        int rootIdx = inorderIndex[rootVal];
        int leftSize = rootIdx - inStart;

        // Left subtree: inorder [inStart, rootIdx-1],
        //               postorder [postStart, postStart+leftSize-1]
        root->left = build(inorder, inStart, rootIdx - 1,
                           postorder, postStart, postStart + leftSize - 1,
                           inorderIndex);

        // Right subtree: inorder [rootIdx+1, inEnd],
        //                postorder [postStart+leftSize, postEnd-1]
        root->right = build(inorder, rootIdx + 1, inEnd,
                            postorder, postStart + leftSize, postEnd - 1,
                            inorderIndex);

        return root;
    }
};
