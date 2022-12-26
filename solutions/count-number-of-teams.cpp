// https://leetcode.com/problems/count-number-of-teams

class Solution {
public:
    int numTeams(vector<int>& a) 
    {
        int n = a.size();
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {   
            int c1 =0,c2=0;
            for(int j=0;j<i;j++)
            {
                if(a[i]>a[j])
                    c1++;
            }
            for(int j=i+1;j<n;j++)
            {
                if(a[i]<a[j])
                    c2++;
            }
            ans += c1*c2+(i-c1)*(n-i-c2-1);
        }
        return ans;
    }
};