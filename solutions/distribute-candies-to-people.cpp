// https://leetcode.com/problems/distribute-candies-to-people

class Solution {
public:
    vector<int> distributeCandies(int tot, int n) 
    {
        vector<int> ans(n,0);
        int i = 0, c = 1;
        while(tot>0)
        {
            if(i==n)
                i = 0;
            if(tot<c)
            {
                ans[i] += tot;
                tot = 0;
                continue;
            }
            ans[i] += c;
            tot -= c;
            c++;
            i++;
        }
        return ans;
    }
};