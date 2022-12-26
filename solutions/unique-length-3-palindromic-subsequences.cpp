// https://leetcode.com/problems/unique-length-3-palindromic-subsequences

class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        map<char,int> mp;
        for(auto c:s)
            mp[c]++;
        
        int ans = 0;
        
        for(auto it:mp)
        {
            char c = it.first;
            int cnt = it.second;
            if(cnt<=1)
                continue;
            
            map<char,int> x = mp;
            
            int i = 0;
            while(s[i]!=c)
            {
                x[s[i]]--;
                if(x[s[i]]==0)
                    x.erase(s[i]);
                i++;
            }
            
            int j = s.length()-1;
            while(s[j]!=c)
            {
                x[s[j]]--;
                if(x[s[j]]==0)
                    x.erase(s[j]);
                j--;
            }
            
            x[c]-=2;
            
            if(x[c]==0)
                x.erase(c);
            
            ans += x.size();
        }
        
        
        return ans;
    }
};