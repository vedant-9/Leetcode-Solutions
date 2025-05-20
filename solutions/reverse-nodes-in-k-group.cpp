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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);

        ListNode* cur = head;
        int len = 0;
        while (cur) {
            cur = cur->next;
            len++;
        }

        cur = head;
        ListNode* prevGroupHead = dummy;
        while (len) {
            ListNode* groupHead = cur;
            if (len < k) {
                len = 0;
            } else {
                ListNode *r = NULL, *q = cur, *p = cur;
                int cnt = 0;
                while (p and cnt < k) {
                    p = p->next;
                    q->next = r;
                    r = q;
                    q = p;
                    cnt++;
                }
                len -= k;
                groupHead->next = q;
                prevGroupHead->next = r;
                cur = q;
            }

            prevGroupHead = groupHead;
        }

        return dummy->next;
    }
};
