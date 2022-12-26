// https://leetcode.com/problems/delete-node-in-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) 
    {   ListNode* temp;
        //creating a temp


        // 1->2->4->NULL

        temp=node->next;
        //taking temp to the next which we would delete
        node->val=node->next->val;
        //duplicating the value of next node to the given node
        node->next=node->next->next;
        //isolating the temp node
        delete temp;
        //deleting the temp node
    }
};