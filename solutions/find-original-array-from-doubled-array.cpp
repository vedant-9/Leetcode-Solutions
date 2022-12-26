// https://leetcode.com/problems/find-original-array-from-doubled-array

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) 
    {
        int n = a.size();
        if(n==1)
            return {};
        
        map<int,int> m;
        for(auto x:a)
            m[x]++;
        
        vector<int> ans;
        for(auto &p:m)
        {
            if(p.first==0)
            {
                if(p.second%2!=0)
                    return {};
                for(int c=0;c<p.second/2;c++)
                    ans.push_back(0);
                continue;
            }
            int y = p.second;
            int x = p.first*2;
            while(y--)
            {
                if(m.find(x)!=m.end() and m[x]!=0)
                    m[x]--,p.second--,ans.push_back(x/2);
                else
                    return {};
            }
        }
        return ans;
    }
};