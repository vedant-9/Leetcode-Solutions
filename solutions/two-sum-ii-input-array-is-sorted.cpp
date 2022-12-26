// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int tar) 
    {
        int n = a.size();
        int i = 0, j = n-1;
        
        while(i<j)
        {
            if(a[i]+a[j]==tar)
                return {i+1,j+1};
            else if(a[i]+a[j]<tar)
                i++;
            else
                j--;
        }
        return {};
    }
};