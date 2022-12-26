// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& a, int tar) 
    {
        int n = a.size();
        int low = 0, high = n;
        while(low<high)
        {
            int mid = (low+high)/2;
            if(a[mid]<tar)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};