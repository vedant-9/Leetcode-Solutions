// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
        int low = 0, high = 0;
        for(int i : nums) high += i;
        
        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(isPossible(nums, m, mid))
            {
                high = mid;
            }
            else
                low = mid+1;
            
        }
        
        return low;
    }
private:
    bool isPossible(const vector<int>& nums, int m, int maxSum)
    {
        int curSum = 0;
        int numSubarrays = 0;
        for(int i : nums)
        {
            if(i > maxSum) return false;
            if(curSum + i > maxSum)
            {
                numSubarrays++;
                curSum = i;
            }
            else
                curSum += i;
        }
        numSubarrays++;
        return numSubarrays <= m;
    }
};