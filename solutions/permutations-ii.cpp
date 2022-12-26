// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    vector<vector<int>> res;
    int n;
    void rec(vector<int> a, int i) 
    {
        if (i == n-1) 
        {
            res.push_back(a);
            return;
        }
        for (int k = i; k < n; k++) 
        {
            if (i != k && a[i] == a[k]) 
                continue;
            swap(a[i], a[k]);
            rec(a, i+1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &a) 
    {
        sort(a.begin(), a.end());
        n = a.size();
        rec(a, 0);
        return res;
    }
};