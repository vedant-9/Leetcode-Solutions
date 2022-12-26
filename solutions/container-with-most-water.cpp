// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& A) 
    {
        int n = A.size();
        int i = 0,j = n-1;
        
        int mx = 0;
        while(i<j)
        {
            mx = max(mx,(j-i)*(min(A[i],A[j])));
            if(A[i]<A[j])
                i++;
            else
                j--;
        }
        return mx;
    }
};