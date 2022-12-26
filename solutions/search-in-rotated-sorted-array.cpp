// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    
    int search(vector<int>& a, int tar) 
    {
        int n = a.size();
        int lo = 0, hi = n-1, mid;
        
        while(lo<=hi)
        {
            mid = (lo+hi)/2;
            
            if(a[mid]==tar)
                return mid;
            else if(a[mid]>=a[lo])
            {
                // piovt is not in left part
                if(a[lo]<=tar && tar<=a[mid])
                    hi = mid-1;
                else 
                    lo = mid+1;
            }
            else
            {
                // piovt is not in right part
                if(a[mid]<=tar && tar<=a[hi])
                    lo = mid+1;
                else 
                    hi = mid-1;
            }
        }
        return -1;
    }
};