class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return (nums[0] << k);
        
        vector<long long> preOr(n, 0), sufOr(n, 0);
        
        preOr[0] = nums[0];
        for(int i = 1; i < n; i++)
            preOr[i] = preOr[i-1] | nums[i];
        
        sufOr[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) 
            sufOr[i] = sufOr[i+1] | nums[i];
        
        long long mul = (1 << k);
        long long maxOr = max((nums[0] * mul) | sufOr[1], preOr[n-2] | (nums[n-1] * mul));
        for(int i = 1; i < n-1; i++) {
            maxOr = max(maxOr, (preOr[i-1] | (nums[i] * mul) | sufOr[i+1]));   
        }
        
        return maxOr;
    }
};
