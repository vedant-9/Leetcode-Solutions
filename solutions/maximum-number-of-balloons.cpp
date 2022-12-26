// https://leetcode.com/problems/maximum-number-of-balloons

class Solution {
public:
    int maxNumberOfBalloons(string s) 
    {
        unordered_map<char, int> mm;
        for (char i : s) mm[i] += 1;
        return min(mm['b'], min(mm['a'], min(mm['l']/2, min(mm['o']/2, mm['n']))));
    }
};