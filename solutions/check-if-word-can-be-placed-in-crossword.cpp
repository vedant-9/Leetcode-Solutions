// https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword

class Solution {
public:
    int m,n;
    bool match(string t, string s)
    {
        if(t.size()!=s.size())
            return 0;
        int f1 = 1, f2 = 1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=t[i] and t[i]!='.')
                f1=0;
        }
        for(int i=0;i<s.size();i++)
        {
            if(t[s.size()-i-1]!='.' and s[i]!=t[s.size()-i-1])
                f2=0;
        }
        return f1 or f2;
    }
    
    bool placeWordInCrossword(vector<vector<char>>& a, string s) 
    {
        m = a.size(), n = a[0].size();
        
        // replace spaces with dot
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==' ')
                    a[i][j] = '.';
            }
        }
        
        // check horizontally
        for(int i=0;i<m;i++)
        {
            int j = 0;
            while(j<n)
            {
                while(j<n and a[i][j]=='#') j++;
                
                string t = "";
                while(j<n and a[i][j]!='#')
                {
                    t += a[i][j];
                    j++;
                }
                // cout<<t<<endl;
                if(!t.empty() and match(t,s))
                {
                    return 1;
                }
            }
        }
        
        // check vertically
        for(int j=0;j<n;j++)
        {
            int i = 0;
            while(i<m)
            {
                while(i<m and a[i][j]=='#') i++;
                
                string t = "";
                while(i<m and a[i][j]!='#')
                {
                    t += a[i][j];
                    i++;
                }
                // cout<<t<<" "<<t.size()<<endl;
                if(!t.empty() and match(t,s))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};