// https://leetcode.com/problems/n-ary-tree-postorder-traversal

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
    vector<int> res;
    void post(Node *r)
    {
        if(!r) return;
        for(auto c:r->children)
        {
            post(c);
        }
        res.push_back(r->val);
    }
    
    vector<int> postorder(Node* root) 
    {
        post(root);
        return res;
    }
};