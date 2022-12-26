// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

class Solution {
public:
    int repeatedNTimes(vector<int>& A) 
    {
        // intuitive either adjacent or alternate or at end
        for (auto i = 0; i < A.size() - 2; ++i)
            if (A[i] == A[i + 1] || A[i] == A[i + 2]) 
                return A[i];
        return A[A.size() - 1];
    }
};