// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& pts, vector<vector<int>>& quer) 
    {
        vector<int> ans;
        for(auto q:quer)
        {
            int cnt = 0;
            for(auto p:pts)
            {
                if((p[0]-q[0])*(p[0]-q[0])+(p[1]-q[1])*(p[1]-q[1])<=(q[2]*q[2]))
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};