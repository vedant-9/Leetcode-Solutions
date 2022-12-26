// https://leetcode.com/problems/longest-turbulent-subarray

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) 
    {
        // TODO
        int res = 0;
        for (auto i = 0, cnt = 0; i + 1 < A.size(); ++i, cnt *= -1) 
        {
            if (A[i] > A[i + 1]) 
                cnt = cnt > 0 ? cnt + 1 : 1;
            else if (A[i] < A[i + 1])  
                cnt = cnt < 0 ? cnt - 1 : -1;
            else 
                cnt = 0;
            res = max(res, abs(cnt));
        }
        return res + 1;
    }
};