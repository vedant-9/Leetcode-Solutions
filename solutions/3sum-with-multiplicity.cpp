// https://leetcode.com/problems/3sum-with-multiplicity

class Solution {
public:
    int threeSumMulti(vector<int>& a, int tar) 
    {
        // store sum of a[i] and a[j]
        unordered_map<int, int> m;
        int res = 0, mod = 1e9 + 7;
        for (int i = 0; i < a.size(); i++) 
        {
            res = (res + m[tar - a[i]]) % mod;
            for (int j = 0; j < i; j++) 
            {
                m[a[i] + a[j]]++;
            }
        }
        return res;
    }
};