// https://leetcode.com/problems/maximum-value-after-insertion

class Solution {
public:
    string maxValue(string n, int x) {
        if(n[0]=='-')
        {
            int i = 0;
            for(i=1;i<n.length();i++)
            {
                if(n[i]-'0'>x)
                    break;
            }
            n.insert(i,1,x+'0');
        }
        else
        {
            int i = 0;
            for(i=0;i<n.length();i++)
            {
                if(n[i]-'0'<x)
                    break;
            }
            n.insert(i,1,x+'0');
        }
        return n;
    }
};