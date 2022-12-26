// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& a, int k) 
    {
        int mp[2001] = {0};
        for(auto x:a) mp[x] = 1;
        int kk = 0, ans = 0;
        for(int i=1;i<2001 && kk<k;i++)
            if(!mp[i]) ans = i,kk++;
        return ans;
    }
};