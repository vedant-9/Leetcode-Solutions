// https://leetcode.com/problems/n-ary-tree-level-order-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> temp;
            int sz = q.size();
            while(sz--) {
                auto cur = q.front(); q.pop();
                temp.push_back(cur->val);
                for(auto &child: cur->children) {
                    q.push(child);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};