// https://leetcode.com/problems/get-maximum-in-generated-array

class Solution {
public:
    int getMaximumGenerated(int n) 
    {
        if(n==0)  return 0;
    
        vector<int> nums(n+1);

        nums[0]=0;
        nums[1]=1;
        int index;
        int mx = 1;

        for(int i=2 ; i<=n ; i++)
        {
            if(i&1) 
            {
                index = (i-1)/2;
                nums[i] = nums[index] + nums[index+1];
            }
            else
            {
                index = i/2;
                nums[i] = nums[index];
            }

            if(nums[i] > mx) 
                mx = nums[i];
        }
        return mx;
    }
};