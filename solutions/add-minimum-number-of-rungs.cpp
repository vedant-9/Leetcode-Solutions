// https://leetcode.com/problems/add-minimum-number-of-rungs

class Solution {
public:
    int addRungs(vector<int>& a, int d) 
    {
        int n = a.size();
        int ans = 0;
        
        if(a[0]>d)
            ans += a[0]/d;
        if(a[0]>d and a[0]%d==0)
            ans--;
        for(int i=1;i<n;i++)
        {
            int x = a[i]-a[i-1];
            if(x>d)
                ans += x/d;
            if(x>d and x%d==0)
                ans--;
        }
        return ans;
    }
};