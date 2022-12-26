// https://leetcode.com/problems/maximum-number-of-pairs-in-array

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& a) {
        map<int,int> m;
        for(auto x:a) m[x]++;
        int f=0,s=0;
        for(auto it:m) {
            f+=it.second/2;
            s+=it.second%2;
        }
        return {f,s};
    }
};