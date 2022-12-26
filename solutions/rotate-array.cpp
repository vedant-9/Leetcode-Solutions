// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& A, int k) 
    {
        k %=A.size();
        reverse(A.begin(), A.end());
        
        reverse(A.begin(), A.begin()+k);
        reverse(A.begin()+k, A.end());
    }
};