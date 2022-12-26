// https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, cnt = 0;
        for(auto x:nums) {
            if(x%6==0) {
                sum += x;
                cnt++;
            } 
        }
        if(cnt==0) return 0;
        return sum/cnt;
    }
};