// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

class Solution {
public:
    // Note all node values are unique
    void buildGraph(TreeNode* root, map<int, vector<int>> &adj) {
        if(!root) return;
        if(root->left) {
            adj[root->left->val].push_back(root->val);
            adj[root->val].push_back(root->left->val);
            buildGraph(root->left, adj);
        }
        if(root->right) {
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
            buildGraph(root->right, adj);
        }
    } 
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {  
        vector<int> ans;
        
        map<int, vector<int>> adj;
        
        buildGraph(root, adj);
        
        queue<int> q;
        map<int, bool> vis;
        q.push(target->val);
        k++;
        
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto cur = q.front(); q.pop();
                if(k==1) {
                    ans.push_back(cur);
                } 
                vis[cur]=1;
                for(auto next: adj[cur]) {
                    if(!vis.count(next)) {
                        q.push(next);
                    }
                }
            }
            k--;
        }
        
        return ans;
    }
};