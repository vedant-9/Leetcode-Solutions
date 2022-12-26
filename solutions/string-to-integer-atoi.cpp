// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) 
    {
        int i = 0,f=0,c=0;
        while(i<s.length() && s[i]==' ') i++;
        if(i==s.length())
            return 0;
        if(s[i]!='-' && s[i]!='+' && !(s[i]<='9' && s[i]>='0'))
        {
            return 0;
        }
        if(s[i]=='-')
        {
            f = 1;
            c =1;
            i++;
        }
        else if(s[i]=='+')
            i++;
        long long n = 0;
        while(i<s.length() && (s[i]<='9' && s[i]>='0'))
        {
            int r = s[i]-'0';
            if(c==1 && f==0)
                n =  n*10 -r;
            else 
                n = n*10+r;
            if(f==1)
                n *= -1,f=0;
            if(n>=INT32_MAX)
                return INT32_MAX;
            if(n<=INT32_MIN)
                return INT32_MIN;
            i++;
        }
        
        return n;
        
    }
};