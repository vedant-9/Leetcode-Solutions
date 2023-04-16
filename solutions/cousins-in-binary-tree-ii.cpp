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
    map<int, long long> levelSum;
    map<TreeNode*, long long> sibSum;

    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        sibSum[root] = root->val;
        
        int lvl = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto cur = q.front(); q.pop();
                levelSum[lvl] += cur->val;
                long long x = 0;
                if(cur->left) q.push(cur->left), x += cur->left->val;
                if(cur->right) q.push(cur->right), x += cur->right->val;
                if(cur->left) sibSum[cur->left] = x;
                if(cur->right) sibSum[cur->right] = x;
            }
            // cout<<levelSum[lvl]<<endl;
            lvl++;
        }
        
        lvl = 1;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto cur = q.front(); q.pop();
                cur->val = (int) levelSum[lvl] - sibSum[cur];
                if(cur->val < 0) cur->val = 0;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            lvl++;
        }
        
        return root;
    }
};

