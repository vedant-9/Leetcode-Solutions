// https://leetcode.com/problems/sum-of-subarray-ranges

class Solution {
public:
    long long subArrayRanges(vector<int>& a) {
        long long sum=0;
        int n=a.size();
        for(int i=0;i<n;i++) {
            int mx=a[i],mn=a[i];
            for(int j=i;j<n;j++) {
                mx=max(mx,a[j]);
                mn=min(mn,a[j]);
                sum+=(mx-mn);
            }
        }
        return sum;
    }
};