// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if (root == NULL) return root;
        Node * start = root;//start of cur level
        Node * end = root;//end of all levels
        Node * levelEnd = root;//cur level's end
        while (start != NULL)
        {
            if (start->left != NULL)
            {
                end->next = start->left;
                end = end->next;
            }
            if (start->right != NULL)
            {
                end->next = start->right;
                end = end->next;
            }
            if (start == levelEnd)
            {
                start = start->next;//start points to next level
                levelEnd->next = NULL;//set cur level's next to NULL
                levelEnd = end;//set cur level's end as next level's end
            }
            else
            {
                start = start->next;
            }
        }    
        return root;
    }
};