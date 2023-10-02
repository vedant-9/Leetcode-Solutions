class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int an = 0;
        for(auto x: nums) an &= x;
        int ans = 0, y = -1;
        for(auto x: nums) {
            if(y == -1) y = x;
            else y &= x;
            if(y == an) ans++, y = -1;
        }
        if(ans == 0) ans = 1; 
        return ans;
    }
};
