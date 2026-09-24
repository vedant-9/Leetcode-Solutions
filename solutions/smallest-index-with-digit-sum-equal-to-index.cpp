class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int su = 0, x = nums[i];
            while(x) {
                su += x%10;
                x /= 10;
            }
            if(su == i) return i;
        }
        return -1;
    }
};
