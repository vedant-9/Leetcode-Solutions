// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) 
    {
        int parts = 0;
        auto total = accumulate(begin(A), end(A), 0);
        if (total % 3 != 0) return false;
        for (auto i = 0, sum = 0; i < A.size(); ++i) 
        {
            sum += A[i];
            if (sum == (parts + 1) * total / 3) 
                ++parts;
        }
        return parts >= 3;
    }
};