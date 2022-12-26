// https://leetcode.com/problems/minimum-space-wasted-from-packaging

class Solution {
public:
    int minWastedSpace(vector<int>& A, vector<vector<int>>& boxes) {
        long res = LONG_MAX, mod = 1e9 + 7, sumA = 0;
        for (int a : A)
            sumA += a;
        int n = A.size();
        int m = boxes.size();
        
        sort(A.begin(),A.end());
        
        for(auto &B:boxes)
        {
            sort(B.begin(),B.end());
            int x = B.size();
            if(A[n-1]>B[x-1])
                continue;
            
            long cur = 0, i = 0, j;
            for (int b : B) 
            {
                j = upper_bound(A.begin(), A.end(), b) - A.begin();
                cur += b * (j - i);
                i = j;
            }
            res = min(res, cur);
        }
        return res < LONG_MAX ? (res - sumA) % mod : -1;
    }
};