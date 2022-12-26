// https://leetcode.com/problems/find-the-middle-index-in-array

class Solution {
public:
    int findMiddleIndex(vector<int>& a) 
    {
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            int lsum = 0, rsum = 0;
            for(int j=0;j<i;j++)
                lsum += a[j];
            for(int j=i+1;j<n;j++)
                rsum += a[j];
            if(lsum==rsum)
                return i;
        }
        return -1;
    }
};