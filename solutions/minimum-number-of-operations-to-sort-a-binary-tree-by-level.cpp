// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level

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
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            vector<pair<int, int>> curData;
            int idx = 0, tsz = sz;
            while(tsz--) {
                auto cur = q.front();
                q.pop();
                
                curData.push_back({cur->val, idx++});
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            sort(curData.begin(), curData.end());
            vector<int> vis(sz, 0);
            for(int i=0; i<sz; i++) {
                if(vis[i] or curData[i].second == i) {
                    continue;
                }
                int j = i, cycle = 0;
                while(!vis[j]) {
                    vis[j] = 1;
                    j = curData[j].second;
                    cycle++;
                }
                if(cycle>0) ans += (cycle-1);
            }
        }
        return ans;
    }
};