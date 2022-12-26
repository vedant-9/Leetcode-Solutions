// https://leetcode.com/problems/maximum-binary-string-after-change

class Solution {
public:
    string maximumBinaryString(string s) 
    {
        // we can set all chars 1 except 1 char
        // 110 -> number of ones before 1st zero + number of zeros -1  => '0'
        int ones = 0, zeros = 0, n = s.length();
        for (auto& c : s) 
        {
            if (c == '0')
                zeros++;
            else if (zeros == 0)
                ones++;
            c = '1';
        }
        if (ones < n)
            s[ones + zeros - 1] = '0';
        return s;
    }
};