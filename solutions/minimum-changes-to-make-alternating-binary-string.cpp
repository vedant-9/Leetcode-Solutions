// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

class Solution {
public:
    int minOperations(string s) 
    {
        // make it either 0101 or 1010
        int case1 = 0, case2 = 0, f=0;
        for(auto ch:s)
        {
            if(ch-'0'!=f) case2++;
            else case1++;
            f ^= 1;
        }
        return min(case1,case2);
    }
};