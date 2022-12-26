// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& A) 
    {
        int n = A.size();
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] != 0) {
                A[j++] = A[i];
            }
        }
        for (;j <n; j++) {
            A[j] = 0;
        }
    }
};