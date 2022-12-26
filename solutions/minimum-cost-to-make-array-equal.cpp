// https://leetcode.com/problems/minimum-cost-to-make-array-equal

class Solution {
public:
    long long minCost(vector<int> &nums, vector<int> &cost) {
        // binary search on x (x is final equal ele)
        long long low = 1, high = 1e6, ans = getCost(nums, cost, 1);
        while(low < high) {
            long long mid = (low+high)/2;
            long long c1 = getCost(nums, cost, mid), c2 = getCost(nums, cost, mid+1);
            ans = min(c1, c2);
            if(c1 < c2) high = mid;
            else low = mid+1;
        }
        return ans;
    }
    
    long long getCost(vector<int> &nums, vector<int> &cost, int x) {
        long long totalCost = 0;
        for(int i=0; i<nums.size(); i++) 
            totalCost += (long long) abs(nums[i]-x) * cost[i];
        return totalCost;
    }
};