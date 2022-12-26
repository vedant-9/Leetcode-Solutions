// https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target

class Solution {
public:
    int numOfPairs(vector<string>& a, string tar) 
    {
        int n = a.size(), ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]+a[j]==tar)
                    ans++;
                if(a[j]+a[i]==tar)
                    ans++;
            }
        }
        return ans;
    }
};