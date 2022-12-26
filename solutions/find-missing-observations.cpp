// https://leetcode.com/problems/find-missing-observations

class Solution {
public:
    vector<int> missingRolls(vector<int>& a, int mean, int n) 
    {
        int sa = 0, sb = 0, m = a.size();
        for(auto x:a) sa+=x;
        sb = mean*(m+n)-sa;
        if(sb<1*n or sb>6*n)
            return {};
        int x = sb/n;
        vector<int> ans(n,x);
        int y = sb%n,i=0;
        while(y>0)
        {
            if(y+ans[i]<=6)
                ans[i]+=y,y=0;
            else 
                ans[i]=6,y-=(6-x);
            i++;
        }
        return ans;
    }
};