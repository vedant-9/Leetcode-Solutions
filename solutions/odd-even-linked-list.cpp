// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head)
            return head;
        ListNode* head2 = head->next;
        ListNode *p = head, *q = head2;
        while(q && q->next)
        {   
            p->next = p->next->next;
            p = p->next;
            q->next = q->next->next;
            q = q->next;
        }
        p->next = head2;
        return head;
    }
};