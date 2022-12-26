// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *p=head,*q=head,*r=NULL;
        vector<int> res;
        int i=0;
        while(q) {
            p=q->next;
            if(r and p) {
                if((r->val<q->val and q->val>p->val) or (r->val>q->val and q->val<p->val))
                    res.push_back(i);
            }
            r=q;
            q=p;
            i++;
        }
        sort(res.begin(),res.end());
        if(res.size()<2) return {-1,-1};
        int mx=res.back()-res[0];
        int mn=mx;
        for(int i=res.size()-1;i>0;i--) {
            mn=min(mn,res[i]-res[i-1]);
        }
        return {mn,mx};
    }
};