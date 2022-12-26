// https://leetcode.com/problems/n-ary-tree-preorder-traversal

class Solution {
public:
    vector<int> res;
    void pre(Node *r) {
        if(!r) return;
        res.push_back(r->val);
        for(auto c:r->children)
            pre(c);
    }
    
    vector<int> preorder(Node* root) {
        pre(root);
        return res;
    }
};