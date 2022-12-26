// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        if(!head->next->next) {
            head->next=NULL; return head;
        }
        ListNode *p=head,*q=head,*r=NULL;
        while(p and p->next) {
            r=q;
            q=q->next;
            p=p->next->next;
        }
        // if(p->next) r=q,q=q->next;
        if(r) r->next=q->next;
        delete(q);
        return head;
    }
};