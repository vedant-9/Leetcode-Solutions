// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            auto curNode = cur.first;
            auto curHoriDist = cur.second.first;
            auto curVertDist = cur.second.second;
            
            mp[curHoriDist][curVertDist].insert(curNode->val);
            
            if(curNode->left) 
                q.push({curNode->left, {curHoriDist-1, curVertDist+1}});
            if(curNode->right) 
                q.push({curNode->right, {curHoriDist+1, curVertDist+1}});
        }
        
        vector<vector<int>> res;
        for(auto &it: mp) {
            vector<int> cur;
            for(auto &it2: it.second) {
                for(auto x: it2.second) {
                    cur.push_back(x);
                }
            }
            res.push_back(cur);
        }
        
        return res;
    }
};