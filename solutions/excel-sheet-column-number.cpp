// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string s) 
    {
        int n = s.length();
        int ans = 0;
        int k =0;
        for(int i=n-1;i>=0;i--)
        {
            ans += (s[i]-'A'+1) * pow(26,k);
            k++;
        }
        return ans;
    }
};