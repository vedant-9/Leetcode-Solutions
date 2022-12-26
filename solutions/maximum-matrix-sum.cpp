// https://leetcode.com/problems/maximum-matrix-sum

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) 
    {
        // if the number of negative signs is even, the answer is the sum of the absolute value of all elements. If it is odd, we will have to minus 2 times the number with smallest absolute value (for we have to change + sign to -) to get the answer:
        long long neg_cnt = 0, ans = 0, n = a.size(), minn = 1000000;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j) 
            {
                ans += abs(a[i][j]);
                if (a[i][j] < 0)
                    neg_cnt++;
                minn = minn < abs(a[i][j])? minn: abs(a[i][j]);
            }
        }
        if (neg_cnt % 2 == 0)
            return ans;
        else 
            return ans - 2*minn;
    }
};