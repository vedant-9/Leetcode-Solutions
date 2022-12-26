// https://leetcode.com/problems/merge-triplets-to-form-target-triplet

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& a, vector<int>& t) 
    {
        vector<int> f;
        vector<int> s;
        vector<int> th;
        int i = 0;
        for(auto v:a)
        {
            if(v[0]==t[0] && v[1]==t[1] && v[2]==t[2])
                return true;
            if(v[0]==t[0])
                f.push_back(i);
            if(v[1]==t[1])
                s.push_back(i);
            if(v[2]==t[2])
                th.push_back(i);
            i++;
        }
        for(auto i:f)
        {
            for(auto j:s)
            {
                for(auto k:th)
                {
                    // check if valid
                    if(t[0]!=max({a[i][0],a[j][0],a[k][0]}))
                        continue;
                    if(t[1]!=max({a[i][1],a[j][1],a[k][1]}))
                        continue;
                    if(t[2]!=max({a[i][2],a[j][2],a[k][2]}))
                        continue;
                    return true;
                }
            }
        }
        return false;
    }
};