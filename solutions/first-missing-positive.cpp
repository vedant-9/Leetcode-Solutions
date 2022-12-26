// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& A) 
    {
        int n = A.size();
        int i = 0;
        int p = n;

        while (i < p) 
        {
            int n = A[i];
            if (n == i+1)
                ++i; // Found it! Look for the next one.
            else if (n < 1 || n > p || n == A[n-1])
                A[i] = A[--p]; // Useless. Get new candidate from the end.
            else 
            {
                A[i] = A[n-1]; // Within range; put it in the right place.
                A[n-1] = n;
            }
        }   

        return p + 1;
    }
};