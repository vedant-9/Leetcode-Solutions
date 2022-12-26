// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [&](const vector<int> &x, const vector<int> &y){
            if(x[0] == y[0])  
                return x[1] < y[1];
            return x[0] > y[0];
        });
        
        int weakCount = 0, maxDefenceTill = INT_MIN;
        for(auto p: properties) {
            if(p[1] < maxDefenceTill) 
                weakCount++;
            maxDefenceTill = max(maxDefenceTill, p[1]);
        }
        
        return weakCount;
    }
};