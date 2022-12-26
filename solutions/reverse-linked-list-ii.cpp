// https://leetcode.com/problems/reverse-linked-list-ii

class Solution {
public:
    // First locate the node before the m-th node (pre) and the m-th node (cur). Then movecur -> next to be after pre for n - m times.
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
        dummy -> next = head;
        for (int i = 0; i < m - 1; i++) {
            pre = pre -> next;
        }
        cur = pre -> next;
        for (int i = 0; i < n - m; i++) {
            ListNode* temp = pre -> next;
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next;
            pre -> next -> next = temp;
        }
        return dummy -> next;
    }
};