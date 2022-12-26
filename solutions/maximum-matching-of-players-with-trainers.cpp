// https://leetcode.com/problems/maximum-matching-of-players-with-trainers

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int i = players.size() - 1, j = trainers.size() - 1, ans = 0;
        while(i >= 0) {
            if(j < 0) break;
            while(i >= 0 and players[i] > trainers[j]) i--;
            if(i >= 0) ans++, i--, j--;
        }
        return ans;
    }
};