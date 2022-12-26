// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k

class Solution {
public:
    int partitionArray(vector<int>& a, int k) {
        int n = a.size();
        int ans = 0, i =0;
        sort(a.begin(),a.end());
        while(i<n) {
            int j=i;
            while(i<n and abs(a[j]-a[i])<=k) i++;
            ans++;
        }
        return ans;
    }
};