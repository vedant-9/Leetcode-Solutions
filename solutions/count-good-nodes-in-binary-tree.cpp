// https://leetcode.com/problems/count-good-nodes-in-binary-tree

class Solution {
public:
    int goodNodes(TreeNode* root, int mx = -1e9) {
        if(!root) return 0;
        int leftSubtreeGoodNodes = goodNodes(root->left, max(mx, root->val));
        int rightSubtreeGoodNodes = goodNodes(root->right, max(mx, root->val));
        int isRootGoodNode = (mx <= root->val);
        int totalGoodNodes = leftSubtreeGoodNodes + rightSubtreeGoodNodes + isRootGoodNode;
        return totalGoodNodes;
    }
};