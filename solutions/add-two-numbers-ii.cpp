// https://leetcode.com/problems/add-two-numbers-ii

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
    
    ListNode* reverseList(ListNode *head)
    {
        if(!head || !head->next)
            return head;
        
        ListNode * p = head, *q = head, *r = NULL;
        
        while(q)
        {
            p = q->next;
            q->next = r;
            r = q;
            q = p;
        }
        
        return r;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *r1 = reverseList(l1);
        ListNode *r2 = reverseList(l2);
        
        int carry = 0;
        
        ListNode *head = new ListNode(-1);
        ListNode *p = r1, *q = r2, *r = head;
        
        while(p || q)
        {
            int s = (p?p->val:0)+(q?q->val:0)+carry;
            carry = s/10;
            s %= 10;
            // ListNode * t = new ListNode(s);
            r->next = new ListNode(s);
            r = r->next;
            if(p)
                p = p->next;
            if(q)
                q = q->next;
        }
        if(carry)
        {
            r->next = new ListNode(carry);
        }
        head = head->next;
        return reverseList(head);
    }
};