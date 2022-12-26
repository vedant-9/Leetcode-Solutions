// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& a, int k) 
    {
        int n = a.size();
        int sum = 0;
        int ans = 0;
        
        // map stores the frequency of sum
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            sum += a[i];
            // pre[i]-pre[0]
            if(sum==k)
                ans++;
            // find the count of i's such that pre[j]-pre[i] = k
            // sum - x = k ... x = sum-k
            if(mp.find(sum-k)!=mp.end())
                ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};