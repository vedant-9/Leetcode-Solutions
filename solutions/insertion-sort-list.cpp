// https://leetcode.com/problems/insertion-sort-list

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
    ListNode *insertionSortList(ListNode *head) {
        ListNode result(INT_MIN);

        while (head) {
            ListNode* iter = &result;
            while (iter->next && iter->next->val < head->val) {
                iter = iter->next;
            }
            ListNode* next = head->next;
            head->next = iter->next;
            iter->next = head;
            head = next;
        }

        return result.next;
    }
};