// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> shuffle(vector<int>& a, int n) 
    {
        vector<int> ans(2*n);
        int i = 0, j = n;
        for(int c=0;c<2*n;c++)
        {
            if(c%2==0)
                ans[c] = a[i++];
            else
                ans[c] = a[j++];
        }
        return ans;
    }
};