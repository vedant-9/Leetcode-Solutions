// https://leetcode.com/problems/best-poker-hand

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        set<char> su; for(auto x:suits) su.insert(x);
        if(su.size()==1) return "Flush";
        map<int,int> ra; for(auto x:ranks) ra[x]++;
        for(auto it:ra) {
            if(it.second>=3) return "Three of a Kind";
        }
        for(auto it:ra) {
            if(it.second>=2) return "Pair";
        }
        return "High Card";
    }
};