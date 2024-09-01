class Solution {
public:
    bool checkTwoChessboards(string s1, string s2) {
        return ( (s1[0]-'a' + s1[1]) % 2 == (s2[0]-'a' + s2[1]) % 2);
    }
};
