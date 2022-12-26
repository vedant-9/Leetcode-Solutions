// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected

class Solution {
public:
    unordered_map<int,vector<int>> adj;
    void pre(TreeNode* root) {
        if(!root or (!root->left and !root->right))
            return;
        if(root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right) {
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
        }
        
        pre(root->left);
        pre(root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root->left and !root->right) return 0;
        
        pre(root);
        
        
        
        queue<int> q;
        int vis[100005];
        memset(vis,0,sizeof(vis));
        q.push(start);
        vis[start]=1;
        
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto cur = q.front();
                q.pop();
                for(auto nxt:adj[cur]) {
                    if(!vis[nxt]) 
                        q.push(nxt), vis[nxt]=1;
                }
            }
            ans++;
        }
        return ans-1;
    }
};