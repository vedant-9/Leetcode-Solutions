// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int>& a) 
    {
        int n = a.size(),ans = 0;
        int i = 0;
        while(i<n-1)
        {
            // Buy at A[i]<A[i+1]
            while(i<n-1 && a[i]>=a[i+1])
                i++;
            int j = i;
            // Sell at A[i]>A[i+1]
            while(i<n-1 && a[i]<=a[i+1])
                i++;
            ans += a[i]-a[j];
        }
        return ans;
    }
};

// 1 2 4 5 3 7 9 11 2 5
// b     s b     s  b s