// https://leetcode.com/problems/find-players-with-zero-or-one-losses

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& a) {
        map<int,int> lose;
        for(auto v:a) {
            lose[v[1]]++;
        }
        vector<int> notlose, loseone;
        for(auto v:a) {
            if(lose.find(v[0])==lose.end()) notlose.push_back(v[0]);
        }
        for(auto it:lose) {
            if(it.second==1) loseone.push_back(it.first);
        }
        sort(notlose.begin(),notlose.end());
        notlose.erase(unique(notlose.begin(),notlose.end()),notlose.end());
        sort(loseone.begin(),loseone.end());
        return {notlose,loseone};
    }
};