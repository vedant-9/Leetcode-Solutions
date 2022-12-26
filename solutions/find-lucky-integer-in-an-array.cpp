// https://leetcode.com/problems/find-lucky-integer-in-an-array

class Solution {
public:
    int findLucky(vector<int>& A) 
    {
        map<int,int> mp;
        for(auto x:A)
        {
            mp[x]++;
        }
        
        int ans = -1;
        for(auto it:mp)
        {
            if(it.second==it.first)
            {
                ans = max(ans,it.first);
            }
        }
        return ans;
    }
};