// https://leetcode.com/problems/determine-color-of-a-chessboard-square

class Solution {
public:
    bool squareIsWhite(string s) 
    {
        return (s[0]-'a'+s[1]-'0')%2==0;    
    }
};