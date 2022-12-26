// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& a, int tar) 
    {
        int n = a.size();
        int low = 0, high = n-1, mid;
        while(low<high)
        {
            mid = (low+high+1)/2;
            if(tar<a[mid])
                high = mid-1;
            else
                low = mid;
        }
        return a[low]==tar?low:-1;
    }
};