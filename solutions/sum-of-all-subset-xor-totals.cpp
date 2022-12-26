// https://leetcode.com/problems/sum-of-all-subset-xor-totals

class Solution {
public:
    int subsetXORSum(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for(int i=1;i<(1<<n);i++)
        {
            int c = 0;
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j))
                    c^=a[j];
            }
            sum += c;
        }
        return sum;
    }
};