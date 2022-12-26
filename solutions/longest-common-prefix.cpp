// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) 
    {
        int i=0;
        for(;i<v[0].size();i++)
        {
            int f=0;
            char c = v[0][i];
            for(int j=1;j<v.size();j++)
            {
                if(i>=v[j].size() || c!=v[j][i])
                {
                    f=1;
                    break;
                }
                
            }
            if(f==1)
            {
                break;
            }
        }
        return v[0].substr(0,i);
    }
};