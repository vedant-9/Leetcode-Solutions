// https://leetcode.com/problems/count-special-quadruplets

class Solution {
public:
    int countQuadruplets(vector<int>& a) 
    {
        int ans = 0;
        int n = a.size();
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                for(int k=j+1;k<n-1;k++)
                {
                    for(int l=k+1;l<n;l++)
                    {
                        if(a[i]+a[j]+a[k]==a[l])
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};