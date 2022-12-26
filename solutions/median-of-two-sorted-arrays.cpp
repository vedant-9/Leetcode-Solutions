// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) 
    {
        // merge two sorted arrays -> TC - O(m+n) & SC - O(m+n)
        int m = a.size(), n = b.size();
        
        vector<int> c(m+n);
        int i = 0,j = 0, k= 0;
        
        while(i<m && j<n)
        {
            if(a[i]<b[j])
            {
                c[k++] = a[i++];
            }
            else
            {
                c[k++] = b[j++];
            }
        }
        
        while(i<m)
            c[k++] = a[i++];
        
        while(j<n)
            c[k++] = b[j++];
        
        // median
        int sz = m+n;
        return ((c[sz/2] + c[(sz-1)/2])/2.0);
    }
};