// https://leetcode.com/problems/greatest-sum-divisible-by-three

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // remainder - 1/2 then 1st small/2nd small
        int rem1_1 = INT_MAX, rem1_2 = INT_MAX;
        int rem2_1 = INT_MAX, rem2_2 = INT_MAX;
        
        int sum = 0;
        for(auto d: nums) {
            sum += d;
            if(d%3 == 1) {
                if(rem1_1 >= d) rem1_2 = rem1_1, rem1_1 = d;
                else if(rem1_2 > d) rem1_2 = d;                     
            } else if(d%3 == 2) {
                if(rem2_1 >= d) rem2_2 = rem2_1, rem2_1 = d;
                else if(rem2_2 > d) rem2_2 = d;
            }
        }
        
        // rem = 1    -> 1 of 1 or 2 of 2
        // rem = 2    -> 1 of 2 or 2 of 1
        int sub = INT_MAX;
        if(sum%3 == 1) {
            if(rem1_1 != INT_MAX) 
                sub = min(sub, rem1_1);
            if(rem2_2 != INT_MAX)
                sub = min(sub, (rem2_1 + rem2_2));
        } else if(sum%3 == 2) {
            if(rem2_1 != INT_MAX)
                sub = min(sub, rem2_1);
            if(rem1_2 != INT_MAX) {
                sub = min(sub, (rem1_1 + rem1_2));
            }
        }
        
        if(sub != INT_MAX) 
            sum -= sub;
        
        return sum;
    }
};