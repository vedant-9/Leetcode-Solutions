// https://leetcode.com/problems/richest-customer-wealth

class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) 
    {
        int mx = 0;
        for(int i=0;i<a.size();i++)
        {
            int sum=0;
            for(auto x:a[i])
                sum+=x;
            if(sum>mx)
                mx = sum;
        }
        return mx;
    }
};