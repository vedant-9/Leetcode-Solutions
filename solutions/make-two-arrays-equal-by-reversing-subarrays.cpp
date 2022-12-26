// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays

class Solution {
public:
    bool canBeEqual(vector<int>& a, vector<int>& b) 
    {
        return unordered_multiset<int>(a.begin(), a.end()) == unordered_multiset<int>(b.begin(),b.end());
    }
};