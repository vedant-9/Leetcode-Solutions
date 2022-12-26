// https://leetcode.com/problems/find-unique-binary-string

class Solution {
public:
    string findDifferentBinaryString(vector<string>& a) 
    {
        int n = a.size();
        for(int i=0;i<(1<<n);i++)
        {
            string s;
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j))
                    s += "1";
                else
                    s += "0";
            }
            if(find(a.begin(),a.end(),s)==a.end())
                return s;
        }
        return "";
    }
};