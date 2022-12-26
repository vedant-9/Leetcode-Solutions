// https://leetcode.com/problems/most-frequent-even-element

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums) {
            if(x%2==0) mp[x]++;
        }
        int ans = -1;
        for(auto it:mp) {
            if(it.second > mp[ans]) ans = it.first;  
        }
        return ans;
    }
};