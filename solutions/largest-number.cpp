// https://leetcode.com/problems/largest-number

class Solution {
public:
    
    static bool comp(const string a, const string b)
    {
        return a+b>b+a;
    }
    
    string largestNumber(vector<int>& A) 
    {
        vector<string> B;
        for(auto s:A)
        {
            B.push_back(to_string(s));
        }
        sort(B.begin(),B.end(),comp);
        
        string kk;
        for(int i=0;i<B.size();i++)
            kk+=B[i];
        
        int i=0;
        while(kk[i]=='0' && i+1<kk.length())
            i++;
        return kk.substr(i);
    }
};