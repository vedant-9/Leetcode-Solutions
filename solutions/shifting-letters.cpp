// https://leetcode.com/problems/shifting-letters

class Solution {
public:
    string shiftingLetters(string s, vector<int>& a) 
    {
        int n = a.size();
        
        // suffix sum on a
        a[n-1] %= 26;
        for(int i=n-2;i>=0;i--)
            a[i] = (a[i]%26+a[i+1]%26)%26;
        
        for(int i=0;i<n;i++)
        {
            s[i] = (s[i]-'a'+a[i])%26+'a';
        }
        return s;
    }
};