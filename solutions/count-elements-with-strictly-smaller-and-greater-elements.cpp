// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements

class Solution {
public:
    int countElements(vector<int>& a) {
        map<int,int> mp;
        for(auto x:a) mp[x]++;
        int prev=mp.begin()->first,ans=0;
        int last=mp.rbegin()->first;
        for(auto it:mp) {
            if(it.first!=prev and it.first!=last) {
                ans+=it.second;
            }
            prev=it.first;
        }
        return ans;
    }
};