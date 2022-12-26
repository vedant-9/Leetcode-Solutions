// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& a) 
    {
        // O(logn) and O(1)
        int start=0,end=a.size()-1;
        
        while (start<end) 
        {
            if (a[start]<a[end])
                return a[start];
            
            int mid = (start+end)/2;
            
            if (a[mid]>=a[start])
                start = mid+1;
            else
                end = mid;
        }
        
        return a[start];
    }
};