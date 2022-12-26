// https://leetcode.com/problems/sum-of-unique-elements

class Solution {
public:
    int sumOfUnique(vector<int>& a) 
    {
        map<int,int> m;
        for(auto x:a) m[x]++;
        int ans = 0;
        for(auto it:m)
            if(it.second==1)
                ans += it.first;
        return ans;
    }
};