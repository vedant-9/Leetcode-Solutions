// https://leetcode.com/problems/split-linked-list-in-parts

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*> parts(k, nullptr);
        int len = 0;
        for (ListNode* node = head; node; node = node->next)
            len++;
        int n = len / k, r = len % k; 
        // n : minimum guaranteed part size; r : extra nodes spread to the first r parts;
        ListNode* node = head, *prev = nullptr;
        for (int i = 0; node && i < k; i++, r--) 
        {
            parts[i] = node;
            for (int j = 0; j < n + (r > 0); j++) 
            {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return parts;
    }
};