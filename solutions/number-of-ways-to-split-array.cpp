// https://leetcode.com/problems/number-of-ways-to-split-array

class Solution {
public:
    int waysToSplitArray(vector<int>& a) {
        int n = a.size();
        vector<long long> suf(n);
        suf[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--) suf[i]=suf[i+1]+a[i];
        long long sum=0,ans=0;
        for(int i=0;i<n-1;i++) {
            sum+=a[i];
            if(sum>=suf[i+1]) ans++;
        }
        return ans;
    }
};