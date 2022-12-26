// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* q = new ListNode(-1);
        ListNode* p = q;
        // carry
        int c = 0;
        while(l1 || l2 || c)
        {
            if(l1 != NULL)
            {
                c += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL)
            {
                c += l2->val;
                l2 = l2->next;
            }

            p->next = new ListNode(c%10);
            c /= 10;
            p = p->next;
        }
        return q->next;
    }
};