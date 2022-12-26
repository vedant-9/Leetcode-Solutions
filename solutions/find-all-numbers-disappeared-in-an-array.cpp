// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        vector<int> ans;
        int n = a.size();
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            vis[a[i]-1] = true;
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                ans.push_back(i+1);
        }
        return ans;
    }
};