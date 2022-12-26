// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& a) 
    {
        vector<int> res, mono;
        for (int x : a) 
        {
            int l = 0, r = mono.size();
            while (l < r) 
            {
                int m = (l + r) / 2;
                if (mono[m] <= x)
                    l = m + 1;
                else
                    r = m;
            }
            res.push_back(l + 1);
            if (mono.size() == l)
                mono.push_back(x);
            mono[l] = x;
        }
        return res;
    }
};