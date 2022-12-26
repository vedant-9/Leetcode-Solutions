// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string countAndSay(int n) 
    {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        
        string s = countAndSay(n-1);
        
        vector<pair<char,int>> v;
        
        int c = 1;
        /*if(s[0]!=s[1])
        {
            v.push_back({s[0],1});
            //c=0;
        }*/
        
        
        for(int i=1;i<s.length();i++)
        {
            if(s[i]!=s[i-1])
            {
                v.push_back({s[i-1],c});
                c=1;
            }
            else 
                c++;
        }
        v.push_back({s[s.length()-1],c});
        
        string ans = "";
        for(auto x:v)
        {
            ans += char(x.second+'0');
            ans += x.first;
            
        }
        return ans;
    }
};