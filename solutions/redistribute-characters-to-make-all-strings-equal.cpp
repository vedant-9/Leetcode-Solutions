// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

class Solution {
public:
    bool makeEqual(vector<string>& A) 
    {
        int n = A.size();
        
        map<char,int> M;
        
        for(auto s:A)
        {
            for(auto c:s)
                M[c]++;
        }
        
        for(auto x:M)
        {
            if(x.second%n!=0)
                return 0;
        }
        return 1;
    }
};