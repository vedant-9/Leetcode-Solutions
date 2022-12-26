// https://leetcode.com/problems/spiral-matrix-iv

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> a(m,vector<int>(n,-1));
        ListNode* p=head;
        int cb=0,ce=n-1,rb=0,re=m-1;
        while(p) {
            for(int j=cb;j<=ce and p;j++,p=p->next) a[rb][j]=p->val;
            rb++;
            for(int i=rb;i<=re and p;i++,p=p->next) a[i][ce]=p->val;
            ce--;
            for(int j=ce;j>=cb and p;j--,p=p->next) a[re][j]=p->val;
            re--;
            for(int i=re;i>=rb and p;i--,p=p->next) a[i][cb]=p->val;
            cb++;
        }
        return a;
    }
};