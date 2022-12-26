// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) 
    {
        int n = a.size();
        vector<int> minlen(a.back());
        for (int layer = n-2; layer >= 0; layer--)
        {
            for (int i = 0; i <= layer; i++) 
            {
                minlen[i] = min(minlen[i], minlen[i+1]) + a[layer][i]; 
            }
        }
        return minlen[0];
    }
};