// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) 
    {
        int l = 0, r = a.size() - 1, mid;
        while (l < r) 
        {
            mid = (l + r) / 2;
            if (a[mid] < a[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};