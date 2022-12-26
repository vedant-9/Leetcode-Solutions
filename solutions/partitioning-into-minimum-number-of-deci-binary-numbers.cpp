// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers

class Solution {
public:
    int minPartitions(string s) 
    {
        int mx = s[0]-'0';
        int i = 1;
        while(i<s.length())
        {
            if(mx==9)
                break;
            mx = max(mx,s[i]-'0');
            i++;
        }
        return mx;
    }
};