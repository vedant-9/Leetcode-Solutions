// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& a) 
    {
        int n = a.size();
        
        map<int,int> m;
        for(auto i:a)
            m[i]++;
        
        vector<pair<int,int>> v;
        for(auto it:m)
        {
            v.push_back({it.second,it.first});
        }
        
        sort(v.rbegin(),v.rend());
        
        int s = 0,c=0;
        for(auto x:v)
        {
            if(s>=n/2)
                break;
            s += x.first;
            c++;
        }
        
        return c;
    }
};