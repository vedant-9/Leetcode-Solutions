// https://leetcode.com/problems/reverse-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(!head or !head->next)
            return head;
        
        ListNode *p = head, *q = head, *r = NULL;
        
        while(q)
        {
            p = q->next;
            q->next = r;
            r = q;
            q = p;
        }
        
        return r;
    }
};