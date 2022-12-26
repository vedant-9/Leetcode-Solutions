// https://leetcode.com/problems/maximum-product-difference-between-two-pairs

class Solution {
public:
    int maxProductDifference(vector<int>& a) 
    {
        int n = a.size();
        sort(a.begin(),a.end());
        return (a[n-1]*a[n-2] - a[0]*a[1]);
    }
};