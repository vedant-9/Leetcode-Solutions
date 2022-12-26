// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& a) 
    {
        int n = a.size(), mn = a[0], mx_profit = 0;
        for(int i=1;i<n;i++)
        {
            mn = min(mn,a[i]);
            mx_profit = max(mx_profit,a[i]-mn);
        }
        return mx_profit;
    }
};