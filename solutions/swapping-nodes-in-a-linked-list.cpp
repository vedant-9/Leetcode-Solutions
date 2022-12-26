// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p = head;
        int cnt = 0;
        while(p) {
            p=p->next;
            cnt++;
        }
        
        ListNode *leftk = head;
        int l = 0;
        while(leftk and l<k-1) {
            leftk = leftk->next;
            l++;
        }
        
        ListNode *rightk = head;
        int r = 0;
        while(rightk and r<cnt-k) {
            rightk = rightk->next;
            r++;
        }
        
        swap(leftk->val,rightk->val);
        
        return head;
    }
};