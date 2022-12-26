// https://leetcode.com/problems/sum-of-beauty-in-the-array

class Solution {
public:
    int sumOfBeauties(vector<int>& a) 
    {   
        int n = a.size();
        
        int mx[n],mn[n];
        mx[0] = a[0];
        for(int i=1;i<n;i++)
        {
            mx[i] = max(mx[i-1],a[i]);
        }
        mn[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            mn[i] = min(mn[i+1],a[i]);
        }
        
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            if(mn[i+1]>a[i] and mx[i-1]<a[i])
                ans+=2;
            else if(a[i-1]<a[i] and a[i]<a[i+1])    
                ans++;
        }
        return ans;
    }
};