// https://leetcode.com/problems/sum-of-digits-of-string-after-convert

class Solution {
public:
    int getLucky(string s, int k) 
    {
        int n = s.length();
        
        string t = "";
        for(auto c:s)
        {
            t += to_string(c-'a'+1);
        }
        cout<<t<<endl;
        
        while(k--)
        {
            int sum = 0;
            for(auto c:t)
            {
                sum += c-'0';
            }
            t = to_string(sum);
        }
        return stoi(t);
    }
};