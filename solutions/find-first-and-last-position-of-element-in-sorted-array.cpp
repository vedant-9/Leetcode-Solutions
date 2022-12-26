// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& A, int tar) 
    {
        int n = A.size();
        if(n==0)
            return {-1,-1};
        
        int i = 0, j = n - 1;
        vector<int> ret(2, -1);
        
        // Search for the left one
        while (i < j)
        {
            int mid = (i + j) /2;
            if (A[mid] < tar) i = mid + 1;
            else j = mid;
        }
        if (A[i]!=tar) return ret;
        else ret[0] = i;

        // Search for the right one
        j = n-1;  // We don't have to set i to 0 the second time.
        while (i < j)
        {
            int mid = (i + j) /2 + 1;	// Make mid biased to the right
            if (A[mid] > tar) j = mid - 1;  
            else i = mid;				// So that this won't make the search range stuck.
        }
        ret[1] = j;
        return ret; 
    }
};