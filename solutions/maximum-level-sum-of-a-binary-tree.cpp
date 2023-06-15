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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        vector<long long> sums;

        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            while(sz--) {
                auto cur = q.front(); q.pop();
                sum += cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            sums.push_back(sum);
        }
        int mxi = 0;
        for(int i = 0; i < sums.size(); i++) {
            if(sums[mxi] < sums[i]) mxi = i;
        }
        return mxi+1;
    }
};
