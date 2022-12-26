// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target

class Solution {
public:
    int findBestValue(vector<int>& a, int tar) 
    {
        int n = a.size(), i = 0;
        sort(a.begin(), a.end());
        while (i<n and tar > a[i]*(n - i))
            tar -= a[i++];
        return i == n ? a[n - 1] : int(round((tar - 0.0001) / (n - i)));
    }
};