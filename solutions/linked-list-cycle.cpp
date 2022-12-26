// https://leetcode.com/problems/linked-list-cycle

class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        ListNode* p = head,*q=head;
        while(p)
		{
			q = q->next;
            if(p->next==NULL)
                return false;
			p = p->next->next;
			if(p==q && p!=NULL)
				return true;
		}
		return false;
    }
};