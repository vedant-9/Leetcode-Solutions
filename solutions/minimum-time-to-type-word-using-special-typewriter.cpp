// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter

class Solution {
public:
    int minTimeToType(string s) 
    {
        int sum = min(s[0]-'a','a'+26-s[0]);
        for(int i=1;i<s.length();i++)
        {
            sum += min({abs(s[i]-s[i-1]),abs(s[i-1]+26-s[i]),abs(s[i]+26-s[i-1])});
        }
        return sum+s.length();
    }
};