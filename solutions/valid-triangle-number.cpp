// https://leetcode.com/problems/valid-triangle-number

class Solution {
public:
    // a+b > c  -> Traingle Condition
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int count = 0;
        for(int k=n-1; k>1; k--) {
            int i = 0, j = k-1;
            while(i<j) {
                if(nums[i]+nums[j] > nums[k]) {
                    count += (j-i); 
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};